#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QColor>
#include "Shapes.h"

class CanvasState;

// Passive view that repaints whenever CanvasState changes.
class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);

    void setCanvasState(CanvasState *state);
    void setShapes(const ShapeList &shapes);

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;

private slots:
    void onShapesChanged(const ShapeList &shapes);
    void onBackgroundChanged(const QColor &color);
    void onZoomChanged(qreal zoom);

private:
    void disconnectState();

    CanvasState *m_state;
    ShapeList    m_shapes;
    QColor       m_background;
    qreal        m_zoom;
};

#endif 
