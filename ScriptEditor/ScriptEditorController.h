#ifndef SCRIPTEDITORCONTROLLER_H
#define SCRIPTEDITORCONTROLLER_H

#include <QObject>

class QPlainTextEdit;
class ScriptDocument;

// Small mediator that keeps QPlainTextEdit and ScriptDocument in sync without
// recursive signal storms.
class ScriptEditorController : public QObject
{
    Q_OBJECT
public:
    ScriptEditorController(ScriptDocument *document,
                           QPlainTextEdit *editor,
                           QObject *parent = nullptr);

private slots:
    void onEditorTextChanged();
    void onDocumentTextChanged(const QString &text);

private:
    ScriptDocument *m_document;
    QPlainTextEdit *m_editor;
    bool m_ignoreEditorSignal;
    bool m_ignoreDocumentSignal;
};

#endif

