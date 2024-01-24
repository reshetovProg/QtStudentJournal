#include "student.h"


int Student::id = 0;

bool Student::checkMark(int mark)
{
    return mark>1 && mark<6;
}

Student::Student()
{

}

Student::Student(QString name, QString surname)
{
    this->name=name;
    this->surname=surname;
    uniqId=++id;
}

void Student::addMark(QString disc, QString date, int mark)
{
    if (checkMark(mark)){
        marks[disc][date]=mark;
    }

}

void Student::changeMark(QString disc, QString date, int mark)
{
    if (checkMark(mark)){
        marks[disc][date]=mark;
    }

}

void Student::removeMark(QString disc, QString date)
{
    marks[disc].remove(date);
}

QString Student::getFullName()
{
    return name+" "+surname;
}

int Student::getUniqId()
{
    return uniqId;
}

