/*
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 14:36:03
 * @LastEditors: 
 * @LastEditTime: 2021-07-06 14:36:42
 */
#include "SFn.h"
#include "Student.h"
#include "MainView.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string pathName = "d://成绩.txt";
	map<int, Student> stu;

	MainView view;
	view.welcome();
	view.showMenu();

	string operateType;
	cin >> operateType;

	while (operateType != "#")
	{
		if (operateType == "1") //录入
		{
			view.addStuAtView(stu);
		}
		else if (operateType == "2") //修改
		{
			view.updateStuAtView(stu);
		}
		else if (operateType == "3") //查找
		{
			view.findStuAtView(stu);
		}
		else if (operateType == "4") //删除
		{
			view.deleteStuAtView(stu);
		}
		else if (operateType == "5") //显示所有
		{
			view.showAllStuAtView(stu);
		}
		else if (operateType == "6") //保存至文件
		{
			view.saveToFileAtView(stu, pathName);
		}
		else if (operateType == "7") //从文件读取
		{
			view.readFromAtView(stu, pathName);
		}
		else
		{
			view.welcome();
			view.showMenu();
		}
		cin >> operateType;
	}
	return 0;
}