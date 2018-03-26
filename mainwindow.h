#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cmath"
#include "iomanip"

#include "QDebug"
#include "QMessageBox"

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
    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged();

    void on_pushButton_clicked();

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
    int oscoreSum();
};

#endif // MAINWINDOW_H
