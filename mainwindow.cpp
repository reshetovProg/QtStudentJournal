#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    QTableWidgetItem* item1 = new QTableWidgetItem("дисциплина");
    QTableWidgetItem* item2 = new QTableWidgetItem("дата");
    ui->tableWidget->setHorizontalHeaderItem(0,item1);
    ui->tableWidget->setHorizontalHeaderItem(1,item2);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(100);

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

void MainWindow::updateTable(){
     int size = students.size();
     ui->tableWidget->setColumnCount(2+size);

     QTableWidgetItem* item1 = new QTableWidgetItem("дисциплина");
     QTableWidgetItem* item2 = new QTableWidgetItem("дата");
     ui->tableWidget->setHorizontalHeaderItem(0,item1);
     ui->tableWidget->setHorizontalHeaderItem(1,item2);
     for(int i = 1; i<=size; i++){
         Student st=students[i];
         QTableWidgetItem* buf = new QTableWidgetItem(st.getFullName());
         ui->tableWidget->setHorizontalHeaderItem(i+1,buf);
     }

}

void MainWindow::on_btnAddStudent_clicked()
{
    QString stName = ui->studentName->toPlainText();
    QString stSurname = ui->studentSurname->toPlainText();
    Student st(stName, stSurname);
    students[st.getUniqId()]=st;
    updateTable();
}

void MainWindow::on_btnAddLesson_clicked()
{
    int a=0;

    ui->tableWidget->insertRow(a);
    QTableWidgetItem* date = new QTableWidgetItem(ui->editDate->toPlainText());
    QTableWidgetItem* disc = new QTableWidgetItem(ui->selectDiscipline->currentText());
     ui->tableWidget->setItem(a,0,disc);
    ui->tableWidget->setItem(a,1,date);
    updateTable();

}
