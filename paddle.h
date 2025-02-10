#ifndef PADDLE_H
#define PADDLE_H

#include <QPainter>
#include <QKeyEvent>

class Paddle {
public:
    Paddle(int x, int y, int width, int height);

    void draw(QPainter &painter);
    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void setPosition(int y);
    QRectF boundingRect() const;
    int getY() const;

    bool upPressed;
    bool downPressed;

private:
    int x;
    int y;
    int width;
    int height;
};

#endif // PADDLE_H
