#pragma once
#include<iostream>
using namespace std;
#include"staff.h"

class Salesman :virtual public staff {
protected:
	//���۶�
	int m_salesVolume;
public:
	//���캯��
	Salesman();
	Salesman(int id, string name, int age, int deptid, int salesVolum);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ
	virtual string getDeptName();
	//��ȡ���۶�
	virtual int getsla();
}; 
