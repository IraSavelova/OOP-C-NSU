#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "mainwindow.h"
#include "score.h"
#include "ui_score.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    void updateScoreMenu();
    void updateScoreLeft();
    void updateScoreRight();
signals:
    void updateScoreMenuSIGNAL(int currentScoreLeft, int currentScoreRight);
//public slots:
    //void updateScoreMenuSLOT(int currentScoreLeft, int currentScoreRight);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MenuWindow *ui;
    MainWindow *mainWindow;
    QTimer *timer;
    Score *scoreWidget;
    int currentScoreLeft = 0;
    int currentScoreRight = 0;
    int scoreLeft=0;
    int scoreRight=0;
};

#endif // MENUWINDOW_H
