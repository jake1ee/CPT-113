#ifndef OPERATION_H
#define OPERATION_H

#include"Student.h"

void menu();
void start();
void getInput(Student&);
int getData(Student*&);

void Registration(Student*&, int);
void displayStudent(Student*&, int);
void StudentSameCourse(Student*&, int);
void CalUnit(Student*&, int);


#endif // !OPERATION_H