#ifndef STAY_H
#define STAY_H
#include<string>
#include "Student.h"

using namespace std;

class Stay
{
private:
	Student student[20];
	string Desa;
public:
	Stay();
	~Stay();
};
#endif // !STAY_H
