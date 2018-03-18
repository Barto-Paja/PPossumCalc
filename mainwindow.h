#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cb_age_currentIndexChanged();

    void on_cb_circulation_currentIndexChanged();

private:
    Ui::MainWindow *ui;

    float dscore =0; // death score
    float mscore =0; // morbidity score
    int glasgow =0; // glasgow scale score

    int pscore =0; // "Parametry fizjologiczne" formularz
    int oscore =0; // "Parametry zabiegu" formularz

// combobox formlar info
    void cbInfo();
    int pscoreSum();
    int glasgowSum();
};

#endif // MAINWINDOW_H
