#include "UdpScriptTransport.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcNetworkTransport, "script.network.transport")

UdpScriptTransport::UdpScriptTransport(QObject *parent)
    : IScriptTransport(parent)
    , m_socket(new QUdpSocket(this))
{
    // Keep the class focused on translating socket events into high level signals.
    connect(m_socket, &QUdpSocket::readyRead,
            this, &UdpScriptTransport::onReadyRead);
}

void UdpScriptTransport::bind(quint16 localPort)
{
    qCInfo(lcNetworkTransport) << "Binding UDP transport on port" << localPort;

    if (m_socket->state() == QAbstractSocket::BoundState)
        m_socket->close();

    // Using AnyIPv4 keeps the behavior consistent on systems with IPv6 disabled.
    if (m_socket->bind(QHostAddress::AnyIPv4, localPort)) {
        emit statusMessage(tr("UDP: listening on %1").arg(localPort));
    } else {
        const QString error = m_socket->errorString();
        qCWarning(lcNetworkTransport) << "Bind failed:" << error;
        emit statusMessage(tr("UDP: bind failed (%1)").arg(error));
    }
}

void UdpScriptTransport::sendScript(const QByteArray &script, const TransportEndpoint &target)
{
    if (!target.address.isNull() && target.port != 0) {
        const qint64 sent = m_socket->writeDatagram(script, target.address, target.port);
        if (sent == -1) {
            const QString error = m_socket->errorString();
            qCWarning(lcNetworkTransport) << "Failed to send script:" << error;
            emit statusMessage(tr("Failed to send script: %1").arg(error));
        } else {
            emit statusMessage(tr("Script sent to %1:%2 (%3 bytes)")
                               .arg(target.address.toString())
                               .arg(target.port)
                               .arg(sent));
            qCInfo(lcNetworkTransport) << "Script sent to" << target.address << target.port << "bytes" << sent;
        }
    } else {
        emit statusMessage(tr("Invalid target endpoint"));
        qCWarning(lcNetworkTransport) << "Invalid target endpoint";
    }
}

void UdpScriptTransport::requestScript(const TransportEndpoint &target)
{
    if (target.address.isNull() || target.port == 0) {
        emit statusMessage(tr("Invalid editor endpoint"));
        return;
    }

    // Tiny one-word protocol that keeps parsing logic trivial on both ends.
    static const QByteArray requestPayload("GET_SCRIPT");
    const qint64 sent = m_socket->writeDatagram(requestPayload, target.address, target.port);
    if (sent == -1) {
        const QString error = m_socket->errorString();
        qCWarning(lcNetworkTransport) << "Failed to send GET_SCRIPT:" << error;
        emit statusMessage(tr("Failed to send UDP datagram: %1").arg(error));
    } else {
        emit statusMessage(tr("GET_SCRIPT sent to %1:%2")
                           .arg(target.address.toString())
                           .arg(target.port));
        qCInfo(lcNetworkTransport) << "GET_SCRIPT sent to" << target.address << target.port;
    }
}

void UdpScriptTransport::onReadyRead()
{
    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        TransportEndpoint endpoint { datagram.senderAddress(), static_cast<quint16>(datagram.senderPort()) };
        const QByteArray data = datagram.data().trimmed();

        if (data.isEmpty()) {
            // Some OSes deliver zero-byte datagrams when the sender closed the socket.
            continue;
        }

        if (data == "GET_SCRIPT") {
            qCInfo(lcNetworkTransport) << "Script request received from" << endpoint.address << endpoint.port;
            emit scriptRequested(endpoint);
        } else if (data.size() > 0) {
            qCInfo(lcNetworkTransport) << "Script received from" << endpoint.address << endpoint.port << "bytes" << data.size();
            emit scriptReceived(data, endpoint);
        }
    }
}

