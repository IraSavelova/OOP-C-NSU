#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include "paddle.h" // Включение класса Paddle
#include "ball.h"
#include "score.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateScore(int leftScore, int rightScore);
    int scoreLeft = 0;
    int scoreRight = 0;

signals:
    void updateScoreSIGNAL(int scoreLeft, int scoreRight);
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event);
    int winLeft(int currentLeft);
    int winRight(int currentRight);


private slots:
    void updatePaddles();
private:
    Ui::MainWindow *ui;
    QTimer *timer;

    int currentLeft = 0;
    int currentRight = 0;

    Paddle *leftPaddle;
    Paddle *rightPaddle;
    Ball *ball;
    Score *scoreWidget;

    int screenHeight;
};

#endif // MAINWINDOW_H
