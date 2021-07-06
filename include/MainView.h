#pragma once
#ifndef C_MAINVIEW_H
#define C_MAINVIEW_H

#include <iostream>
#include <map>
#include <string>
#include "Student.h"
#include "SFn.h"

class MainView
{
public:
	MainView();
	~MainView();

	//欢迎界面
	void welcome();
	//显示菜单
	void showMenu();
	//view显示所有的学生
	void showAllStuAtView(const std::map<int, Student>& stu_m1);
	//view添加学生信息
	void addStuAtView(std::map<int, Student>& stu_m1);
	//view查找学生信息
	void findStuAtView(const std::map<int, Student>& m1);
	//view删除学生信息
	void deleteStuAtView(std::map<int, Student>& v1);
	//view更新学生信息
	void updateStuAtView(std::map<int, Student>& m1);
	//把map保存进文件
	void saveToFileAtView(const std::map<int, Student>& m1, std::string pathName);
	//把文件中的东西导入到map
	void readFromAtView(std::map<int, Student>& m, std::string pathName);
private:

};

#endif // !C_MAINVIEW_H
