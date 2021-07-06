/*
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 14:36:03
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-07-06 16:09:01
 */
#include "SFn.h"
#include "Student.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
SFn::SFn()
{
}
SFn::~SFn()
{
}
//功能实现：增删查改
//1. 增加
Student SFn::addStu(std::map<int, Student> &m1, Student &stu)
{
	m1.insert(std::make_pair(stu.getID(), stu));
	return stu;
}
//2. 删除
bool SFn::deleteStuById(std::map<int, Student> &m1, const int &id)
{
	bool b = false;

	std::map<int, Student>::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		m1.erase(iter);
		b = true; //删除成功
	}
	return b;
}
//3. 查找
Student SFn::findStuById(const std::map<int, Student> &m1, const int &id)
{
	Student stu;

	std::map<int, Student>::const_iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		stu = iter->second;
	}
	return stu;
}
//4. 改动
Student SFn::updateStu(std::map<int, Student> &m1, const Student &cstu)
{
	Student stu;
	int id = cstu.getID();

	std::map<int, Student>::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		//修改
		iter->second = cstu;
		stu = cstu;
	}
	return stu;
}
//显示全部
void SFn::showAll(const std::map<int, Student> &m1) const
{
	for (auto p : m1) //p??
	{
		std::cout << p.second << std::endl;
	}
}
//保存
bool SFn::saveToFile(const std::map<int, Student> &m1, const std::string &pathName) const
{
	bool b = true;
	std::fstream ofs(pathName, std::ios::out);
	if (ofs)
	{
		std::stringstream ss;
		std::cout << "文件打开" << std::endl;
		Student stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << std::endl;
		}
		ofs << ss.str();
		ofs.close();
	}
	else
	{
		std::cout << "文件打开失败！" << std::endl;
		b = false;
	}

	return b;
}
//读取
bool SFn::readFromFile(std::map<int, Student> &m1, std::string path)
{
	bool b = true;
	m1.clear();
	std::fstream ifs(path, std::ios::in);
	if (ifs)
	{
		std::cout << "文件打开" << std::endl;
		std::string s;
		std::stringstream ss;
		while (getline(ifs, s))
		{
			Student stu;
			ss << s;
			ss >> stu;
			ss.clear();
			m1.insert(std::make_pair(stu.getID(), stu));
		}
		ifs.close();
	}
	else
	{
		std::cout << "文件打开失败！" << std::endl;
		b = false;
	}

	return b;
}
