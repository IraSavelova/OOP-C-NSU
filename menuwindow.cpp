#include "menuwindow.h"
#include "ui_menuwindow.h"
MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
    , mainWindow(nullptr)
    , scoreLeft(0)
    , scoreRight(0)
{
    ui->setupUi(this);
    scoreWidget = new Score(nullptr, scoreLeft, scoreRight);
    //timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &MenuWindow::updateScoreMenu);
    //timer->start(1600); // Запуск обновления каждые 16 мс

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_pushButton_3_clicked()
{
    mainWindow = new MainWindow();
    mainWindow->setWindowTitle("Ping Pong Game");
    mainWindow->show();
    connect(mainWindow, &MainWindow::destroyed, mainWindow, &MainWindow::deleteLater);
}
/*void MenuWindow::updateScoreMenu() {
    updateScoreLeft(scoreLeft);
    updateScoreRight(scoreRight);
    //update();
}
*/
void MenuWindow::updateScoreLeft(){
    scoreLeft+= mainWindow->scoreLeft;

}
void MenuWindow::updateScoreRight(){
    scoreRight += mainWindow->scoreRight;
}
void MenuWindow::on_pushButton_2_clicked()
{
    scoreWidget->setWindowTitle("Score Ping Pong Game");
    updateScoreLeft();
    updateScoreRight();
    connect(scoreWidget, &Score::destroyed, scoreWidget, &Score::deleteLater);
    connect(this, &MenuWindow::updateScoreMenuSIGNAL, scoreWidget, &Score::updateScoreSLOT);
    scoreWidget->updateScoreSLOT(scoreLeft,scoreRight);
    emit updateScoreMenuSIGNAL(scoreLeft, scoreRight);
    scoreWidget->show();
}

