#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
namespace Ui {
class Score;
}

class Score : public QWidget
{
    Q_OBJECT

public:
    //explicit Score(QWidget *parent);
    explicit Score(QWidget *parent = nullptr, int currentScoreLeft=0, int currentScoreRight=0);
    ~Score();


public slots:
    void updateScoreSLOT(int currentScoreLeft, int currentScoreRight);

private:
    Ui::Score *ui;
    QLabel *scoreLabelLeft;
    QLabel *scoreLabelRight;
    QTimer *timer;
    int currentScoreLeft;
    int currentScoreRight;
};

#endif // SCORE_H
