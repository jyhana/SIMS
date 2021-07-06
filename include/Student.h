#pragma once
#ifndef C_STUDENT_H
#define C_STUDENT_H
#include <string>
#include <iostream>
class Student
{
	//友元函数：可以访问private成员
	friend std::ostream& operator<<(std::ostream& os, Student& stu);
	friend std::istream& operator>>(std::istream& is, Student& stu);

public:

	Student();//构造函数
	~Student();//析构函数

	//学号
	int getID() const;//?
	void setID(int val);

	//姓名
	std::string getName()const;
	void setName(std::string val);

	//分数
	double getScore() const;
	void setScore(double val);

private:

	int id;
	std::string name;
	int score;
};

#endif // !C_STUDENT_H



