#pragma once
#include<iostream>
using namespace std;
#include <string>

//ְ��������
class staff {
protected:

public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ
	virtual string getDeptName() = 0;
	//���
	int m_Id;
	//����
	string m_Name;
	//����
	int m_Age;
	//ְ����λ
	int m_DeptId;
	//��ȡ���������ֵ
	virtual int getsla() = 0;


};