#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , screenHeight(500)
    , currentLeft(0)
    , currentRight(0)
    , scoreLeft(0)
    , scoreRight(0)
{
    ui->setupUi(this);
    setFixedSize(800, screenHeight);


    scoreWidget = new Score(nullptr, scoreLeft, scoreRight);
    leftPaddle = new Paddle(10, 200, 10, 100);
    rightPaddle = new Paddle(780, 200, 10, 100);
    ball = new Ball(100,100,10,5,5);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePaddles);
    timer->start(16); // Запуск обновления каждые 16 мс
    connect(this, &MainWindow::updateScoreSIGNAL, scoreWidget, &Score::updateScoreSLOT);
    //connect(this, &MainWindow::updateScoreSIGNAL, menuWindow, &MenuWindow::updateScoreMenuSLOT);
}

MainWindow::~MainWindow() {
    delete ui;
    delete leftPaddle;
    delete rightPaddle;
    delete ball;
    delete scoreWidget;
}
void MainWindow::closeEvent(QCloseEvent *event) { //чтобы игра не продолжалась при закрытии
    updateScore(scoreLeft, scoreRight);
    timer->stop();
    event->accept(); // Принять событие закрытия
}
void MainWindow::updateScore(int scoreLeft, int scoreRight) {
    scoreWidget->updateScoreSLOT(scoreLeft,scoreRight);
    emit updateScoreSIGNAL(scoreLeft, scoreRight);
    scoreWidget->show();
}
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    leftPaddle->draw(painter);
    rightPaddle->draw(painter);
    ball->draw(painter);
    painter.drawText(rect(), Qt::AlignCenter, QString("%1 : %2").arg(currentLeft).arg(currentRight));
    painter.drawText(rect(), Qt::AlignLeft, QString("%1 : %2").arg(scoreLeft).arg(scoreRight));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        leftPaddle->upPressed = true;
    } else if (event->key() == Qt::Key_S) {
        leftPaddle->downPressed = true;
    }

    if (event->key() == Qt::Key_Up) {
        rightPaddle->upPressed = true;
    } else if (event->key() == Qt::Key_Down) {
        rightPaddle->downPressed = true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        leftPaddle->stopUp();
    } else if (event->key() == Qt::Key_S) {
        leftPaddle->stopDown();
    }

    if (event->key() == Qt::Key_Up) {
        rightPaddle->stopUp();
    } else if (event->key() == Qt::Key_Down) {
        rightPaddle->stopDown();
    }
}
int MainWindow::winLeft(int currentLeft){
    currentLeft ++;
    if (currentLeft == 2) {
        QMessageBox::information(this, "Win!!!!", "Выиграл 1-ый игрок!");
        currentLeft = 0;
        scoreLeft += 1;


    }
    return currentLeft;
}
int MainWindow::winRight(int currentRight){
    currentRight ++;
    if (currentRight == 2) {
        QMessageBox::information(this, "Win!!!!", "Выиграл 2-oй игрок!");
        currentRight = 0;
        scoreRight += 1;
    }
    return currentRight;

}
void MainWindow::updatePaddles() {
    if (leftPaddle->upPressed) {
        leftPaddle->moveUp();
    }
    if (leftPaddle->downPressed) {
        leftPaddle->moveDown();
    }
    if (rightPaddle->upPressed) {
        rightPaddle->moveUp();
    }
    if (rightPaddle->downPressed) {
        rightPaddle->moveDown();
    }
    if (ball->boundingRect().intersects(leftPaddle->boundingRect())) {
        ball->bounceOffPaddle(leftPaddle->boundingRect());
    }
    if (ball->boundingRect().intersects(rightPaddle->boundingRect())) {
        ball->bounceOffPaddle(rightPaddle->boundingRect());
    }
    if (ball->x < 0){
        ball->restart();
        currentRight = winRight(currentRight);
    }
    if (ball->x > 800){
        ball->restart();
        currentLeft = winLeft(currentLeft);
    }
    ball->move();

    update();
}
