#pragma once
#include<iostream>
#include"Manager.h"
#include"Salesman.h"
using namespace std;

class SalesManager :public Manager, public Salesman {
public:
	//���캯��
	SalesManager(int id, string name, int age, int deptid, int salesVolum);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ
	virtual string getDeptName();
	//��ȡ���۶�
	virtual int getsla();



};