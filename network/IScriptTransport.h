#ifndef ISCRIPTTRANSPORT_H
#define ISCRIPTTRANSPORT_H

#include <QObject>
#include <QHostAddress>

// Simple POD so both apps can reason about host/port pairs the same way.
struct TransportEndpoint
{
    QHostAddress address;
    quint16      port = 0;
};

Q_DECLARE_METATYPE(TransportEndpoint)

// Abstract transport so we can drop in TCP or shared-memory later without
// touching UI code.
class IScriptTransport : public QObject
{
    Q_OBJECT
public:
    explicit IScriptTransport(QObject *parent = nullptr) : QObject(parent) {}
    ~IScriptTransport() override = default;

    virtual void bind(quint16 localPort) = 0;
    virtual void sendScript(const QByteArray &script, const TransportEndpoint &target) = 0;
    virtual void requestScript(const TransportEndpoint &target) = 0;

signals:
    void scriptReceived(const QByteArray &script, const TransportEndpoint &sender);
    void scriptRequested(const TransportEndpoint &sender);
    void statusMessage(const QString &message);
};

#endif

