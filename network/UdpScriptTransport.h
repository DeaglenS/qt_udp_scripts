#ifndef UDPSCRIPTTRANSPORT_H
#define UDPSCRIPTTRANSPORT_H

#include "IScriptTransport.h"

#include <QUdpSocket>
#include <QNetworkDatagram>

// QUdpSocket backed implementation of IScriptTransport.
class UdpScriptTransport : public IScriptTransport
{
    Q_OBJECT
public:
    explicit UdpScriptTransport(QObject *parent = nullptr);

    void bind(quint16 localPort) override;
    void sendScript(const QByteArray &script, const TransportEndpoint &target) override;
    void requestScript(const TransportEndpoint &target) override;

private slots:
    void onReadyRead();

private:
    QUdpSocket *m_socket;
};

#endif

