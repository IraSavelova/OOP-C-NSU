#include "ball.h"

Ball::Ball(qreal x, qreal y, qreal radius, qreal speedX, qreal speedY)
    : x(x), y(y), radius(radius), speedX(speedX), speedY(speedY) {}

void Ball::move() {
    x += speedX;
    y += speedY;


    if (y - radius < 0 || y + radius > 470) {
        speedY = -speedY;
    }

}

void Ball::draw(QPainter &painter) {
    painter.setBrush(QColor(255, 0, 0));
    painter.drawEllipse(QPointF(x, y), radius, radius);
}

void Ball::bounceOffPaddle(const QRectF &paddleRect) {
    if (paddleRect.contains(x, y)) {
        speedX = -speedX;
    }
}
void Ball::restart() {
    x = 400;
    y = 250;

}

QRectF Ball::boundingRect() const {
    return QRectF(x - radius, y - radius, radius * 2, radius * 2);
}
