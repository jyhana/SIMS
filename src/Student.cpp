/*
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 14:36:03
 * @LastEditors: 
 * @LastEditTime: 2021-07-06 16:06:47
 */
#include <iostream>
#include <string>

#include "Student.h"
using namespace std;

//学生的id默认为-1（无效值）
Student::Student() { this->id = -1; }
Student::~Student() {}

int Student::getID() const { return id; }
void Student::setID(int val) { id = val; }

std::string Student::getName() const { return name; }
void Student::setName(std::string val) { name = val; }

double Student::getScore() const { return score; }
void Student::setScore(double val) { val = score; }

//重载运算符
std::ostream &operator<<(std::ostream &os, Student &stu)
{
	//输出
	os << stu.getID() << "	" << stu.getName() << "		" << stu.getScore();
	return os;
}

std::istream &operator>>(std::istream &is, Student &stu)
{
	//输入
	is >> stu.id >> stu.name >> stu.score;
	return is;
}