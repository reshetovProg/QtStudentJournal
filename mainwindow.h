#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_btnAddDiscipline_clicked();
    void updateLists();
    void updateTable();

    void on_btnAddStudent_clicked();

    void on_btnAddLesson_clicked();

private:
    Ui::MainWindow *ui;
    QSet <QString> disciplines;
    QMap <int, Student> students;

};
#endif // MAINWINDOW_H
