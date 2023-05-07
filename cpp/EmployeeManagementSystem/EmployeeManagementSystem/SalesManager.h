#pragma once
#include<iostream>
#include"Manager.h"
#include"Salesman.h"
using namespace std;

class SalesManager :public Manager, public Salesman {
public:
	//构造函数
	SalesManager(int id, string name, int age, int deptid, int salesVolum);
	//显示个人信息
	virtual void showInfo();
	//获取岗位
	virtual string getDeptName();
	//获取销售额
	virtual int getsla();



};