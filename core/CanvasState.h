#ifndef CANVASSTATE_H
#define CANVASSTATE_H

#include <QObject>
#include <QColor>
#include <QUndoStack>

#include "Shapes.h"

class AddShapeCommand;
class ClearShapesCommand;
class SetBackgroundCommand;
class SetZoomCommand;

// Shared model for everything the runner needs to render: shapes,
// background and zoom. Views/widgets listen to the signals below.
class CanvasState : public QObject
{
    Q_OBJECT
public:
    explicit CanvasState(QObject *parent = nullptr);

    const ShapeList &shapes() const;
    QColor backgroundColor() const;
    qreal zoomFactor() const;
    QUndoStack *undoStack() const;

    // All mutations are undoable so the toolbar buttons work automatically.
    void addShape(const Shape &shape);
    void clearShapes();
    void setBackgroundColor(const QColor &color);
    void setZoomFactor(qreal zoom);

signals:
    void shapesChanged(const ShapeList &shapes);
    void backgroundChanged(const QColor &color);
    void zoomChanged(qreal zoom);

private:
    // Low level setters used by the undo commands to prevent duplicate stack entries.
    void applyShapes(const ShapeList &shapes);
    void applyBackground(const QColor &color);
    void applyZoom(qreal zoom);

    friend class AddShapeCommand;
    friend class ClearShapesCommand;
    friend class SetBackgroundCommand;
    friend class SetZoomCommand;

    ShapeList  m_shapes;
    QColor     m_background;
    qreal      m_zoom;
    QUndoStack *m_undoStack;
};

#endif

