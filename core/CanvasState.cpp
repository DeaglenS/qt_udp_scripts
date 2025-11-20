#include "CanvasState.h"

#include <QUndoCommand>
#include <QtGlobal>

// Each interaction funnels through a tiny undo command so both applications
// get undo/redo for free via QUndoStack.
class AddShapeCommand : public QUndoCommand
{
public:
    AddShapeCommand(CanvasState *state, const Shape &shape)
        : m_state(state)
        , m_shape(shape)
    {
        setText(QObject::tr("Add Shape"));
    }

    void undo() override
    {
        ShapeList shapes = m_state->shapes();
        if (!shapes.isEmpty())
            shapes.removeLast();
        m_state->applyShapes(shapes);
    }

    void redo() override
    {
        ShapeList shapes = m_state->shapes();
        shapes.append(m_shape);
        m_state->applyShapes(shapes);
    }

private:
    CanvasState *m_state;
    Shape        m_shape;
};

class ClearShapesCommand : public QUndoCommand
{
public:
    ClearShapesCommand(CanvasState *state, const ShapeList &before)
        : m_state(state)
        , m_before(before)
    {
        setText(QObject::tr("Clear Canvas"));
    }

    void undo() override
    {
        m_state->applyShapes(m_before);
    }

    void redo() override
    {
        m_state->applyShapes(ShapeList());
    }

private:
    CanvasState *m_state;
    ShapeList    m_before;
};

class SetBackgroundCommand : public QUndoCommand
{
public:
    SetBackgroundCommand(CanvasState *state, const QColor &before, const QColor &after)
        : m_state(state)
        , m_before(before)
        , m_after(after)
    {
        setText(QObject::tr("Set Background"));
    }

    void undo() override
    {
        m_state->applyBackground(m_before);
    }

    void redo() override
    {
        m_state->applyBackground(m_after);
    }

private:
    CanvasState *m_state;
    QColor       m_before;
    QColor       m_after;
};

class SetZoomCommand : public QUndoCommand
{
public:
    SetZoomCommand(CanvasState *state, qreal before, qreal after)
        : m_state(state)
        , m_before(before)
        , m_after(after)
    {
        setText(QObject::tr("Set Zoom"));
    }

    void undo() override
    {
        m_state->applyZoom(m_before);
    }

    void redo() override
    {
        m_state->applyZoom(m_after);
    }

private:
    CanvasState *m_state;
    qreal        m_before;
    qreal        m_after;
};

CanvasState::CanvasState(QObject *parent)
    : QObject(parent)
    , m_background(Qt::white)
    , m_zoom(1.0)
    , m_undoStack(new QUndoStack(this))
{
}

const ShapeList &CanvasState::shapes() const
{
    return m_shapes;
}

QColor CanvasState::backgroundColor() const
{
    return m_background;
}

qreal CanvasState::zoomFactor() const
{
    return m_zoom;
}

QUndoStack *CanvasState::undoStack() const
{
    return m_undoStack;
}

void CanvasState::addShape(const Shape &shape)
{
    // ScriptCanvas always appends, so the command can pop the last element.
    m_undoStack->push(new AddShapeCommand(this, shape));
}

void CanvasState::clearShapes()
{
    if (m_shapes.isEmpty())
        return;

    // Carry the previous buffer so undo can restore it in one step.
    m_undoStack->push(new ClearShapesCommand(this, m_shapes));
}

void CanvasState::setBackgroundColor(const QColor &color)
{
    if (m_background == color)
        return;

    m_undoStack->push(new SetBackgroundCommand(this, m_background, color));
}

void CanvasState::setZoomFactor(qreal zoom)
{
    if (qFuzzyCompare(m_zoom, zoom))
        return;

    m_undoStack->push(new SetZoomCommand(this, m_zoom, zoom));
}

void CanvasState::applyShapes(const ShapeList &shapes)
{
    m_shapes = shapes;
    emit shapesChanged(m_shapes);
}

void CanvasState::applyBackground(const QColor &color)
{
    if (m_background == color)
        return;

    m_background = color;
    emit backgroundChanged(m_background);
}

void CanvasState::applyZoom(qreal zoom)
{
    if (qFuzzyCompare(m_zoom, zoom))
        return;

    m_zoom = zoom;
    emit zoomChanged(m_zoom);
}

