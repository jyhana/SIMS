/*
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 14:36:03
 * @LastEditors: 
 * @LastEditTime: 2021-07-06 16:07:47
 */
#pragma once
#ifndef C_STUDENT_SFn_H
#define C_STUDENG_SFn_H

#include "Student.h"
#include <string>
#include <map>
class SFn //业务类：主要用来实现几个功能板块
{
public:
	SFn();
	~SFn();

	//功能实现：增删查改
	//1. 增加
	Student addStu(std::map<int, Student> &m1, Student &stu);
	//2. 删除
	bool deleteStuById(std::map<int, Student> &m1, const int &id);
	//3. 查找
	Student findStuById(const std::map<int, Student> &m1, const int &id);
	//4. 改动
	Student updateStu(std::map<int, Student> &m1, const Student &stu);

	//显示全部
	void showAll(const std::map<int, Student> &m1) const;
	//保存
	bool saveToFile(const std::map<int, Student> &m1, const std::string &pathName) const;
	//读取
	bool readFromFile(std::map<int, Student> &m1, std::string path);

private:
};
#endif // !C_STUDENT_ENTRY_H
