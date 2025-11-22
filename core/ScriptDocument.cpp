#include "ScriptDocument.h"

#include <QUndoCommand>

// Undo command for full-buffer updates. We keep it simple because scripts
// tend to be small and we only care about whole document swaps.
class TextChangeCommand : public QUndoCommand
{
public:
    TextChangeCommand(ScriptDocument *doc,
                      const QString &oldText,
                      const QString &newText)
        : m_document(doc)
        , m_oldText(oldText)
        , m_newText(newText)
    {
        setText(QObject::tr("Text Change"));
    }

    void undo() override
    {
        m_document->applyText(m_oldText, true);
    }

    void redo() override
    {
        m_document->applyText(m_newText, true);
    }

private:
    ScriptDocument *m_document;
    QString m_oldText;
    QString m_newText;
};

ScriptDocument::ScriptDocument(QObject *parent)
    : QObject(parent)
    , m_dirty(false)
    , m_undoStack(new QUndoStack(this))
{
}

QString ScriptDocument::text() const
{
    return m_text;
}

QString ScriptDocument::filePath() const
{
    return m_filePath;
}

bool ScriptDocument::isDirty() const
{
    return m_dirty;
}

QUndoStack *ScriptDocument::undoStack() const
{
    return m_undoStack;
}

void ScriptDocument::setText(const QString &text, bool recordUndo, bool markDirty)
{
    if (recordUndo) {
        if (m_text == text)
            return;
        m_undoStack->push(new TextChangeCommand(this, m_text, text));
    } else {
        applyText(text, markDirty);
    }
}

void ScriptDocument::loadText(const QString &text)
{
    // Disk loads become the new baseline, so we drop undo history.
    m_undoStack->clear();
    applyText(text, false);
}

void ScriptDocument::setFilePath(const QString &path)
{
    if (m_filePath == path)
        return;

    m_filePath = path;
    emit filePathChanged(m_filePath);
}

void ScriptDocument::clearDirty()
{
    if (!m_dirty)
        return;

    m_dirty = false;
    emit dirtyChanged(m_dirty);
}

void ScriptDocument::undo()
{
    m_undoStack->undo();
}

void ScriptDocument::redo()
{
    m_undoStack->redo();
}

void ScriptDocument::applyText(const QString &text, bool markDirty)
{
    if (m_text == text && m_dirty == markDirty)
        return;

    // All updates funnel through here so signals stay consistent no matter
    // whether the change came from undo, redo, or manual editing.
    m_text = text;
    emit textChanged(m_text);

    if (m_dirty != markDirty) {
        m_dirty = markDirty;
        emit dirtyChanged(m_dirty);
    }
}



