#pragma once
#include<iostream>
#include"staff.h"
using namespace std;

class Manager :virtual public staff {
protected:
	int nop = 0;
public:
	//构造函数
	Manager();
	Manager(int id, string name, int age, int deptid);
	//显示个人信息
	virtual void showInfo();
	//获取岗位
	virtual string getDeptName();
	//获取销售额
	virtual int getsla();
};
