#ifndef SCRIPTCANVAS_H
#define SCRIPTCANVAS_H

#include <QObject>
#include <QColor>
#include "Shapes.h"

class CanvasState;
// Thin wrapper exposed to the scripting engine. Every Q_INVOKABLE call maps
// to a CanvasState mutation so scripts cannot bypass validation.
class ScriptCanvas : public QObject
{
    Q_OBJECT
public:
    explicit ScriptCanvas(CanvasState *state, QObject *parent = nullptr);

    Q_INVOKABLE void clear();
    Q_INVOKABLE void line(qreal x1, qreal y1, qreal x2, qreal y2, const QColor &color, qreal width = 1.0);
    Q_INVOKABLE void rect(qreal x, qreal y, qreal width, qreal height, const QColor &fillColor, const QColor &strokeColor, qreal penWidth = 1.0);
    Q_INVOKABLE void circle(qreal x, qreal y, qreal radius, const QColor &strokeColor, qreal penWidth = 1.0);
    Q_INVOKABLE void filledCircle(qreal x, qreal y, qreal radius, const QColor &fillColor);
    Q_INVOKABLE void triangle(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, const QColor &fillColor, const QColor &strokeColor, qreal penWidth = 1.0);
    Q_INVOKABLE void setBackground(const QColor &color);
    Q_INVOKABLE void setZoom(qreal zoom);
    // Feeds the console in ScriptRunnerWindow via the message signal.
    Q_INVOKABLE void print(const QString &msg);

    ShapeList shapes() const;

signals:
    void message(const QString &text);

private:
    CanvasState *m_state;
};

#endif

