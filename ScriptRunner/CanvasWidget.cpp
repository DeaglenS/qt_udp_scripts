#include "CanvasWidget.h"

#include "CanvasState.h"

#include <QPainter>
#include <QPaintEvent>
#include <QtGlobal>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent)
    , m_state(nullptr)
    , m_background(Qt::white)
    , m_zoom(1.0)
{
    setMinimumSize(400, 300);
}

void CanvasWidget::setCanvasState(CanvasState *state)
{
    if (m_state == state)
        return;

    disconnectState();
    m_state = state;

    if (m_state) {
        // React to all state change signals so repaint logic stays local.
        connect(m_state, &CanvasState::shapesChanged,
                this, &CanvasWidget::onShapesChanged);
        connect(m_state, &CanvasState::backgroundChanged,
                this, &CanvasWidget::onBackgroundChanged);
        connect(m_state, &CanvasState::zoomChanged,
                this, &CanvasWidget::onZoomChanged);

        onShapesChanged(m_state->shapes());
        onBackgroundChanged(m_state->backgroundColor());
        onZoomChanged(m_state->zoomFactor());
    } else {
        m_shapes.clear();
        m_background = Qt::white;
        m_zoom = 1.0;
        update();
    }
}

void CanvasWidget::setShapes(const ShapeList &shapes)
{
    m_shapes = shapes;
    update();
}

QSize CanvasWidget::sizeHint() const
{
    return QSize(480, 360);
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.fillRect(rect(), m_background);
    p.save();
    if (!qFuzzyCompare(m_zoom, 1.0))
        p.scale(m_zoom, m_zoom);

    for (const Shape &s : m_shapes) {
        // Rendering intentionally mirrors ScriptCanvas packing rules.
        switch (s.type) {
        case ShapeType::FilledCircle: {
            const QPointF c = s.p1;
            const qreal r = s.p2.x();
            p.setPen(Qt::NoPen);
            p.setBrush(s.fillColor);
            p.drawEllipse(c, r, r);
            break;
        }
        case ShapeType::StrokeCircle: {
            const QPointF c = s.p1;
            const qreal r = s.p2.x();
            QPen pen(s.strokeColor, s.penWidth);
            p.setPen(pen);
            p.setBrush(Qt::NoBrush);
            p.drawEllipse(c, r, r);
            break;
        }
        case ShapeType::Rect: {
            const QRectF rect(s.p1, QSizeF(s.p2.x(), s.p2.y()));
            QPen pen;
            if (s.strokeColor.isValid()) {
                pen = QPen(s.strokeColor, s.penWidth);
            } else {
                pen = Qt::NoPen;
            }
            p.setPen(pen);

            if (s.fillColor.isValid())
                p.setBrush(s.fillColor);
            else
                p.setBrush(Qt::NoBrush);

            p.drawRect(rect);
            break;
        }
        case ShapeType::Triangle: {
            QPolygonF poly;
            poly << s.p1 << s.p2 << s.p3;

            QPen pen;
            if (s.strokeColor.isValid())
                pen = QPen(s.strokeColor, s.penWidth);
            else
                pen = Qt::NoPen;

            p.setPen(pen);
            if (s.fillColor.isValid())
                p.setBrush(s.fillColor);
            else
                p.setBrush(Qt::NoBrush);

            p.drawPolygon(poly);
            break;
        }
        case ShapeType::Line: {
            QPen pen(s.strokeColor, s.penWidth);
            p.setPen(pen);
            p.setBrush(Qt::NoBrush);
            p.drawLine(s.p1, s.p2);
            break;
        }
        }
    }
    p.restore();
}

void CanvasWidget::onShapesChanged(const ShapeList &shapes)
{
    m_shapes = shapes;
    update();
}

void CanvasWidget::onBackgroundChanged(const QColor &color)
{
    m_background = color;
    update();
}

void CanvasWidget::onZoomChanged(qreal zoom)
{
    m_zoom = zoom;
    update();
}

void CanvasWidget::disconnectState()
{
    if (!m_state)
        return;

    // Disconnect everything at once; the widget may outlive the state.
    disconnect(m_state, nullptr, this, nullptr);
    m_state = nullptr;
}
