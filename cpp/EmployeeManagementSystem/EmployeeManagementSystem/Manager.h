#pragma once
#include<iostream>
#include"staff.h"
using namespace std;

class Manager :virtual public staff {
protected:
	int nop = 0;
public:
	//���캯��
	Manager();
	Manager(int id, string name, int age, int deptid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ
	virtual string getDeptName();
	//��ȡ���۶�
	virtual int getsla();
};
