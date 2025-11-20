#include "ScriptCanvas.h"

#include "CanvasState.h"

ScriptCanvas::ScriptCanvas(CanvasState *state, QObject *parent)
    : QObject(parent)
    , m_state(state)
{
}

void ScriptCanvas::clear()
{
    if (m_state)
        m_state->clearShapes();
}

void ScriptCanvas::line(qreal x1, qreal y1, qreal x2, qreal y2, const QColor &color, qreal width)
{
    if (!m_state)
        return;

    // Store the raw geometry so CanvasWidget can paint deterministically later.
    Shape s;
    s.type = ShapeType::Line;
    s.p1 = QPointF(x1, y1);
    s.p2 = QPointF(x2, y2);
    s.strokeColor = color;
    s.penWidth = width;
    m_state->addShape(s);
}

void ScriptCanvas::rect(qreal x, qreal y, qreal width, qreal height, const QColor &fillColor, const QColor &strokeColor, qreal penWidth)
{
    if (!m_state)
        return;

    Shape s;
    s.type = ShapeType::Rect;
    s.p1 = QPointF(x, y);
    s.p2 = QPointF(width, height);
    s.fillColor = fillColor;
    s.strokeColor = strokeColor;
    s.penWidth = penWidth;
    m_state->addShape(s);
}

void ScriptCanvas::circle(qreal x, qreal y, qreal radius, const QColor &strokeColor, qreal penWidth)
{
    if (!m_state)
        return;

    // Stash the radius in p2.x to keep the Shape struct small.
    Shape s;
    s.type = ShapeType::StrokeCircle;
    s.p1 = QPointF(x, y);
    s.p2 = QPointF(radius, 0);
    s.strokeColor = strokeColor;
    s.penWidth = penWidth;
    m_state->addShape(s);
}

void ScriptCanvas::filledCircle(qreal x, qreal y, qreal radius, const QColor &fillColor)
{
    if (!m_state)
        return;

    Shape s;
    s.type = ShapeType::FilledCircle;
    s.p1 = QPointF(x, y);
    s.p2 = QPointF(radius, 0);
    s.fillColor = fillColor;
    m_state->addShape(s);
}

void ScriptCanvas::triangle(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, const QColor &fillColor, const QColor &strokeColor, qreal penWidth)
{
    if (!m_state)
        return;

    Shape s;
    s.type = ShapeType::Triangle;
    s.p1 = QPointF(x1, y1);
    s.p2 = QPointF(x2, y2);
    s.p3 = QPointF(x3, y3);
    s.fillColor = fillColor;
    s.strokeColor = strokeColor;
    s.penWidth = penWidth;
    m_state->addShape(s);
}

void ScriptCanvas::setBackground(const QColor &color)
{
    if (m_state)
        m_state->setBackgroundColor(color);
}

void ScriptCanvas::setZoom(qreal zoom)
{
    if (m_state)
        m_state->setZoomFactor(zoom);
}

void ScriptCanvas::print(const QString &msg)
{
    // Runner window logs this text so script authors can get feedback.
    emit message(msg);
}

ShapeList ScriptCanvas::shapes() const
{
    return m_state ? m_state->shapes() : ShapeList();
}

