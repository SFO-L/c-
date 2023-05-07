#pragma once
#include<iostream>
using namespace std;
#include <string>

//职工抽象类
class staff {
protected:

public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位
	virtual string getDeptName() = 0;
	//编号
	int m_Id;
	//姓名
	string m_Name;
	//年龄
	int m_Age;
	//职工岗位
	int m_DeptId;
	//获取各自特殊的值
	virtual int getsla() = 0;


};