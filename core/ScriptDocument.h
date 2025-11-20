#ifndef SCRIPTDOCUMENT_H
#define SCRIPTDOCUMENT_H

#include <QObject>
#include <QString>
#include <QUndoStack>

class TextChangeCommand;

// Keeps track of the editor text plus metadata so UI code does not
// have to duplicate state tracking logic.
class ScriptDocument : public QObject
{
    Q_OBJECT
public:
    explicit ScriptDocument(QObject *parent = nullptr);

    QString text() const;
    QString filePath() const;
    bool isDirty() const;
    QUndoStack *undoStack() const;

public slots:
    // Replaces the entire buffer and optionally records undo + dirty state.
    void setText(const QString &text, bool recordUndo = true, bool markDirty = true);
    // Used when loading from disk where we do not want an undo entry.
    void loadText(const QString &text);
    void setFilePath(const QString &path);
    void clearDirty();
    void undo();
    void redo();

signals:
    void textChanged(const QString &text);
    void filePathChanged(const QString &path);
    void dirtyChanged(bool dirty);

private:
    // Internal helpers that perform raw state mutation so undo commands can
    // flip between values without re-emitting public API side effects.
    void applyText(const QString &text, bool markDirty);

    friend class TextChangeCommand;

    QString m_text;
    QString m_filePath;
    bool m_dirty;
    QUndoStack *m_undoStack;
};

#endif

