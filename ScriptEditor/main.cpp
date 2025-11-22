#include <QApplication>
#include "ScriptEditorWindow.h"
#include "../network/IScriptTransport.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Needed for queued connections between editor and transport.
    qRegisterMetaType<TransportEndpoint>("TransportEndpoint");

    ScriptEditorWindow w;
    w.resize(800, 600);
    w.show();

    return app.exec();
}
