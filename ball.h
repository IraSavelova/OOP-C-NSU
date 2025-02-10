#ifndef BALL_H
#define BALL_H
#include <QRectF>
#include <QPainter>
#include <QColor>
#include <QTimer>

class Ball {
public:
    Ball(qreal x, qreal y, qreal radius, qreal speedX, qreal speedY);

    void move();
    void draw(QPainter &painter);
    void bounceOffPaddle(const QRectF &paddleRect);
    void restart();
    QRectF boundingRect() const;
    qreal x;
private:
    qreal y;        // Положение по оси Y
    qreal radius;   // Радиус мяча
    qreal speedX;   // Скорость по оси X
    qreal speedY;   // Скорость по оси Y
};

#endif // BALL_H
