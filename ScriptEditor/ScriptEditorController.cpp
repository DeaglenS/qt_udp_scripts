#include "ScriptEditorController.h"

#include "ScriptDocument.h"

#include <QPlainTextEdit>
#include <QSignalBlocker>

ScriptEditorController::ScriptEditorController(ScriptDocument *document,
                                               QPlainTextEdit *editor,
                                               QObject *parent)
    : QObject(parent)
    , m_document(document)
    , m_editor(editor)
    , m_ignoreEditorSignal(false)
    , m_ignoreDocumentSignal(false)
{
    connect(m_editor, &QPlainTextEdit::textChanged,
            this, &ScriptEditorController::onEditorTextChanged);

    connect(m_document, &ScriptDocument::textChanged,
            this, &ScriptEditorController::onDocumentTextChanged);

    m_editor->setPlainText(m_document->text());
}

void ScriptEditorController::onEditorTextChanged()
{
    if (m_ignoreEditorSignal)
        return;

    m_ignoreDocumentSignal = true;
    m_document->setText(m_editor->toPlainText(), true, true);
    m_ignoreDocumentSignal = false;
}

void ScriptEditorController::onDocumentTextChanged(const QString &text)
{
    if (m_ignoreDocumentSignal)
        return;

    m_ignoreEditorSignal = true;
    {
        QSignalBlocker blocker(m_editor);
        if (m_editor->toPlainText() != text)
            m_editor->setPlainText(text);
    }
    m_ignoreEditorSignal = false;
}


