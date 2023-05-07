#pragma once
#include<iostream>
using namespace std;
#include"staff.h"

class Salesman :virtual public staff {
protected:
	//销售额
	int m_salesVolume;
public:
	//构造函数
	Salesman();
	Salesman(int id, string name, int age, int deptid, int salesVolum);
	//显示个人信息
	virtual void showInfo();
	//获取岗位
	virtual string getDeptName();
	//获取销售额
	virtual int getsla();
}; 
