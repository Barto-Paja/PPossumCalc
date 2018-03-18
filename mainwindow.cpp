#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cbInfo();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cbInfo()
{

    // Age Combobox
    ui->cb_age->addItem("<61",1);
    ui->cb_age->addItem("61 - 70",2);
    ui->cb_age->addItem("70>",4);

    // Circulation Combobox
    ui->cb_circulation->addItem("Brak patologii",1);
    ui->cb_circulation->addItem("Leki diuretyczne, digoksyna, leki na dusznicę lub nadciśnienie",2);
    ui->cb_circulation->addItem("Obrzęki obwodowe, warfaryna, graniczna kardiomiopatia",4);
    ui->cb_circulation->addItem("Podniesione JVP, kardiomegalia",8);

    // ECG Combobox
    ui->cb_ECG->addItem("Norma",1);
    ui->cb_ECG->addItem("Migotanie przedsionków, puls 60-90",4);
    ui->cb_ECG->addItem("Inne zaburzenia rytmu, >4min ektopowe, fale Q, zmiany ST/T",8);

    // systolic pressure Combobox
    ui->cb_systolicPressure->addItem("110 - 130 mmHg",1);
    ui->cb_systolicPressure->addItem("100 - 109 lub 131 - 170 mmHg",2);
    ui->cb_systolicPressure->addItem(">170 lub 90 - 99 mmHg",4);
    ui->cb_systolicPressure->addItem("<90 mmHg",8);

    // Pulse Combobox
    ui->cb_pulse->addItem("50 - 80/min",1);
    ui->cb_pulse->addItem("40 - 49 lub 81 - 100/min",2);
    ui->cb_pulse->addItem("101 - 120/min",4);
    ui->cb_pulse->addItem("<40 lub >120/min",8);

    // Haemoglobin Combobox
    ui->cb_haemoglobin->addItem("13 - 16 g/dl",1);
    ui->cb_haemoglobin->addItem("11.5 - 12.9 lub 16.1 - 17 g/dl",2);
    ui->cb_haemoglobin->addItem("10 - 11.4 lub 17.1 - 18 g/dl",4);
    ui->cb_haemoglobin->addItem("<10 lub >18g/dl",8);

    // Leucocytosis Combobox
    ui->cb_leukocytosis->addItem("4 - 10",1);
    ui->cb_leukocytosis->addItem("10.1 - 20 lub 3.1 - 4",2);
    ui->cb_leukocytosis->addItem(">20 lub <3",4);

    // Urea Combobox
    ui->cb_urea->addItem("<7.6",1);
    ui->cb_urea->addItem("7.6 - 10",2);
    ui->cb_urea->addItem("10.1 - 15",4);
    ui->cb_urea->addItem(">15",8);

    // Na Combobox
    ui->cb_Na->addItem(">135 mmol/l",1);
    ui->cb_Na->addItem("131 - 135 mmol/l",2);
    ui->cb_Na->addItem("126 - 130 mmol/l",4);
    ui->cb_Na->addItem("<126 mmol/l",8);

    // K Combobox
    ui->cb_K->addItem("3.5 - 5 mmol/l",1);
    ui->cb_K->addItem("3.2 - 3.4 lub 5.1 - 5.3 mmol/l",2);
    ui->cb_K->addItem("2.9 - 3.1 lub 5.4 - 5.9 mmol/l",4);
    ui->cb_K->addItem("<2.9 lub >5.9 mmol/l",8);

    // ===== 3th site ==== //

    // type of surgery Combobox
    ui->cb_tos->addItem("Mały zabieg",1);
    ui->cb_tos->addItem("Średni zabieg",2);
    ui->cb_tos->addItem("Duży zabieg",4);
    ui->cb_tos->addItem("Złożony duży zabieg",8);

    // number of procedures Combobox
    ui->cb_nop->addItem("Jedna",1);
    ui->cb_nop->addItem("Dwie",4);
    ui->cb_nop->addItem("Więcej niż dwie",8);

    // intraoperative blood loss Combobox
    ui->cb_blood->addItem("<100ml",1);
    ui->cb_blood->addItem("101 - 500ml",2);
    ui->cb_blood->addItem("501 - 999ml",4);
    ui->cb_blood->addItem(">1000ml",8);

    // peritoneal contamination Combobox
    ui->cb_cont->addItem("Bez zanieczyszczenia",1);
    ui->cb_cont->addItem("Niewielkie zanieczyszczenie",2);
    ui->cb_cont->addItem("Ognisko ropy (punktowe zanieczyszczenie)",4);
    ui->cb_cont->addItem("Treść jelitowa, ropa lub krew",8);

    // malicious changes Combobox
    ui->cb_malig->addItem("Nie złośliwa",1);
    ui->cb_malig->addItem("Tylko pierwotna zmiana",2);
    ui->cb_malig->addItem("Złośliwa + zajęcie węzłów",4);
    ui->cb_malig->addItem("Złoślwa + odległe przerzuty",8);

    // treatment mode Combobox
    ui->cb_cepod->addItem("Planowy",1);
    ui->cb_cepod->addItem("Nagły",4);
    ui->cb_cepod->addItem("Nagły w ciągu 2 godzin",8);

}

int MainWindow::pscoreSum()
{
    int age = ui->cb_age->currentData().toInt();
    int circulation = ui->cb_circulation->currentData().toInt();
    int ecg = ui->cb_ECG->currentData().toInt();
    int systolic = ui->cb_systolicPressure->currentData().toInt();
    int pulse = ui->cb_pulse->currentData().toInt();
    int haemoglobin = ui->cb_haemoglobin->currentData().toInt();
    int leukocytosis = ui->cb_leukocytosis->currentData().toInt();
    int urea = ui->cb_urea->currentData().toInt();
    int Na = ui->cb_Na->currentData().toInt();
    int K = ui->cb_K->currentData().toInt();

    pscore = age+circulation+ecg+systolic+pulse+haemoglobin+leukocytosis+urea+Na+K;
}

int MainWindow::glasgowSum()
{
    int temp_v0 = 0, temp_v1 = 0, temp_v2 = 0;

    if(ui->rB_spontaneously->isChecked())
    {
        ui->rB_order->setChecked(false);
        ui->rB_incentives->setChecked(false);
        ui->rB_closedEyes->setChecked(false);

        temp_v0 = 4;
    }
    else if(ui->rB_order->isChecked())
    {
        ui->rB_spontaneously->setChecked(false);
        ui->rB_incentives->setChecked(false);
        ui->rB_closedEyes->setChecked(false);

        temp_v0 = 3;
    }
    else if(ui->rB_incentives->isChecked())
    {
        ui->rB_spontaneously->setChecked(false);
        ui->rB_order->setChecked(false);
        ui->rB_closedEyes->setChecked(false);

        temp_v0 = 2;
    }
    else if(ui->rB_closedEyes->isChecked())
    {
        ui->rB_spontaneously->setChecked(false);
        ui->rB_order->setChecked(false);
        ui->rB_incentives->setChecked(false);

        temp_v0 = 1;
    }
    else
    {
        qDebug() << "Nie wybrano ani jednej z opcji";
    }

    if(ui->rB_logic->isChecked())
    {
        ui->rB_confused->setChecked(false);
        ui->rB_scream->setChecked(false);
        ui->rb_noreaction->setChecked(false);

        temp_v1 = 4;
    }
    else if(ui->rB_confused->isChecked())
    {
        ui->rB_logic->setChecked(false);
        ui->rb_noreaction->setChecked(false);
        ui->rB_scream->setChecked(false);

        temp_v1 = 3;
    }
    else if(ui->rB_scream->isChecked())
    {
        ui->rB_logic->setChecked(false);
        ui->rb_noreaction->setChecked(false);
        ui->rB_confused->setChecked(false);

        temp_v1 = 2;
    }
    else if(ui->rb_noreaction->isChecked())
    {
        ui->rB_confused->setChecked(false);
        ui->rB_scream->setChecked(false);
        ui->rB_logic->setChecked(false);

        temp_v1 = 1;
    }
    else
    {
        qDebug() << "Nie wybrano ani jednej opcji";
    }
}

void MainWindow::on_cb_age_currentIndexChanged()
{
    qDebug() << ui->cb_age->currentData();
}

void MainWindow::on_cb_circulation_currentIndexChanged()
{
    qDebug() << ui->cb_circulation->currentData();
}
