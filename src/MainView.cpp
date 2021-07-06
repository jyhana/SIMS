#include "MainView.h"

MainView::MainView()
{

}
MainView::~MainView()
{

}
//欢迎界面
void MainView::welcome()
{
	system("cls");
	std::cout << "学籍信息管理系统" << std::endl;
}
//显示菜单
void MainView::showMenu()
{
	std::cout << std::endl;
	std::cout << "操作步骤：" << std::endl;
	std::cout << "1. 录入信息" << std::endl;
	std::cout << "2. 修改信息" << std::endl;
	std::cout << "3. 查找信息" << std::endl;
	std::cout << "4. 删除信息" << std::endl;
	std::cout << "5. 显示所有" << std::endl;
	std::cout << "6. 保存文件" << std::endl;
	std::cout << "7. 导入文件" << std::endl;
	std::cout << std::endl;

	std::cout << "作者：JYHan" << std::endl;
	std::cout << "2021/07/16" << std::endl;

	std::cout << "请选择操作：";
}
//view显示所有的学生
void MainView::showAllStuAtView(const std::map<int, Student>& stu_m1)
{
	system("cls");
	std::cout << "学号		" << "姓名		" << "成绩		" << std::endl;
	SFn Stu;
	Stu.showAll(stu_m1);

	system("pause");
	system("cls");
	welcome();
	showMenu();
}
//view添加学生信息
void MainView::addStuAtView(std::map<int, Student>& stu_m1)
{
	SFn SFnstu;
	int id;
	std::string name;
	double score;
	Student Studentstu;
	system("cls");

	std::cout << "录入\n";
	std::cout << "id:";
	std::cin >> id;

	std::cout << "name:";
	std::cin >> name;

	std::cout << "score:";
	std::cin >> score;

	Studentstu.setID(id);
	Studentstu.setName(name);
	Studentstu.setScore(score);

	//保存
	SFnstu.addStu(stu_m1, Studentstu);

	system("cls");
	welcome();
	showMenu();
}
//view查找学生信息
void MainView::findStuAtView(const std::map<int, Student>& m1)
{
	system("cls");
	std::cout << "请输入需要查找的学生的学号：" << std::endl;
	int id;
	std::cin >> id;

	Student Studentstu;
	SFn SFnstu;
	Studentstu = SFnstu.findStuById(m1, id);

	if (Studentstu.getID() != -1)
	{
		std::cout << Studentstu << std::endl;
	}
	else
	{
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();
}
//view删除学生信息
void MainView::deleteStuAtView(std::map<int, Student>& v1)
{
	system("cls");
	std::cout << "请输入需要删除学生的学号：" << std::endl;

	int id;
	std::cin >> id;

	SFn SFnstu;
	bool b = SFnstu.deleteStuById(v1, id);

	if (b)
	{
		std::cout << "删除成功" << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}
}
//view更新学生信息
void MainView::updateStuAtView(std::map<int, Student>& m1)
{
	system("cls");
	std::cout << "请输入需要修改的学生的学号：" << std::endl;
	int id;
	std::cin >> id;
	std::string name;
	std::cout << "name:";
	std::cin >> name;
	double score;
	std::cout << "score:";
	std::cin >> score;

	Student Studentstu;
	Studentstu.setID(id);
	Studentstu.setName(name);
	Studentstu.setScore(score);

	SFn SFnstu;
	Student Studentstu_ = SFnstu.updateStu(m1, Studentstu);

	if (Studentstu_.getID() != -1)
	{
		std::cout << Studentstu_ << std::endl;
		std::cout << "修改成功" << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();
}
//把map保存进文件
void MainView::saveToFileAtView(const std::map<int, Student>& m1, std::string pathName)
{
	if (m1.begin() == m1.end())
	{
		system("cls");
		std::cout << "还没有任何学生的信息，无法保存！" << std::endl;
	}
	else
	{
		//baocun
		SFn SFnstu;
		bool b = SFnstu.saveToFile(m1, pathName);
		if (b)
		{
			system("cls");
			std::cout << "保存成功" << std::endl;
		}
		else
		{
			std::cout << "保存失败！" << std::endl;
		}
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();
}
//把文件中的东西导入到map
void MainView::readFromAtView(std::map<int, Student>& m, std::string pathName)
{
	system("cls");
	SFn SFnstu;
	bool b = SFnstu.readFromFile(m, pathName);
	if (b)
	{
		std::cout << "读取成功" << std::endl;
	}
	else
	{
		std::cout << "读取失败！" << std::endl;
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();
}