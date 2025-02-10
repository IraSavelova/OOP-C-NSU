#include "score.h"
#include "ui_score.h"

Score::Score(QWidget *parent, int currentScoreLeft, int currentScoreRight)
    : QWidget(parent)
    , ui(new Ui::Score)
    , currentScoreLeft(currentScoreLeft)
    , currentScoreRight(currentScoreRight)
{
    ui->setupUi(this);
    setFixedSize(800, 300);


    scoreLabelLeft = new QLabel(this);
    scoreLabelLeft->setGeometry(80, 30, 300, 30);


    scoreLabelRight = new QLabel(this);
    scoreLabelRight->setGeometry(500, 30, 300, 30);

    updateScoreSLOT(currentScoreLeft, currentScoreRight);
}

Score::~Score()
{
    delete ui;
    delete scoreLabelLeft;
    delete scoreLabelRight;
}
void Score::updateScoreSLOT(int currentScoreLeft, int currentScoreRight) {

    scoreLabelLeft->setText(QString("Текущий счет игрока 1: %1").arg(currentScoreLeft));
    scoreLabelRight->setText(QString("Текущий счет игрока 2: %1").arg(currentScoreRight));
    update();
}


