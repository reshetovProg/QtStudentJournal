#ifndef STUDENT_H
#define STUDENT_H
#include <QApplication>


class Student
{
    static int id;

    int uniqId;
    QString name;
    QString surname;
    QMap <QString, QMap<QString, int>> marks;

    bool checkMark(int mark);

public:
    Student();
    Student(QString name, QString surname);
    void addMark(QString disc, QString date, int mark);
    void changeMark(QString disc, QString date, int mark);
    void removeMark(QString disc, QString date);
    QString getFullName();
    int getUniqId();

};

#endif // STUDENT_H
