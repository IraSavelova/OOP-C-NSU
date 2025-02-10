#include "paddle.h"

Paddle::Paddle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), upPressed(false), downPressed(false) {}

void Paddle::draw(QPainter &painter) {
    painter.setBrush(Qt::black);
    painter.drawRect(x, y, width, height);
}

void Paddle::moveUp() {
    if (y > 0) {
        y -= 10;
    }
}

void Paddle::moveDown() {
    if(y < 370){
        y += 10;
    }
}

void Paddle::stopUp() {
    upPressed = false;
}

void Paddle::stopDown() {
    downPressed = false;
}

void Paddle::setPosition(int y) {
    this->y = y;
}
QRectF Paddle::boundingRect() const {
    return QRectF(x, y, width, height);
}
int Paddle::getY() const {
    return y;
}
