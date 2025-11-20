#include <QApplication>
#include "ScriptRunnerWindow.h"
#include "../network/IScriptTransport.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // TransportEndpoint travels across queued signal/slot boundaries.
    qRegisterMetaType<TransportEndpoint>("TransportEndpoint");

    ScriptRunnerWindow w;
    w.resize(900, 600);
    w.show();

    return app.exec();
}
