#ifndef SHAPES_H
#define SHAPES_H

#include <QColor>
#include <QPointF>
#include <QVector>

enum class ShapeType {
    FilledCircle,
    StrokeCircle,
    Triangle,
    Rect,
    Line
};

struct Shape
{
    ShapeType type;
    QPointF   p1;
    QPointF   p2;
    QPointF   p3;
    QPointF   p4;
    QColor    fillColor;
    QColor    strokeColor;
    qreal     penWidth;

    Shape()
        : type(ShapeType::FilledCircle)
        , penWidth(1.0)
    {}
};

typedef QVector<Shape> ShapeList;

#endif