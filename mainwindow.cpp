#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAddDiscipline_clicked()
{
    QString name = ui->textEditDiscipline->toPlainText();
    disciplines.insert(name);
    updateLists();
}

void MainWindow::updateLists()
{
    ui->selectDiscipline->clear();
    for(auto el: disciplines){
        ui->selectDiscipline->addItem(el);
    }
}
