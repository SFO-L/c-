#include"SalesManager.h"
using namespace std;

//���캯��
SalesManager::SalesManager(int id, string name, int age, int deptid, int salesVolum) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Age = age;
	this->m_DeptId = deptid;
	this->m_salesVolume = salesVolum;
};
//��ʾ������Ϣ
void SalesManager::showInfo() {
	cout << "���:" << this->m_Id
		<< "\t����:" << this->m_Name
		<< "\t���䣺" << this->m_Age
		<< "\t��λ��" << this->getDeptName()
		<< "\t���۶" << this->m_salesVolume << endl;

};
//��ȡ��λ
string SalesManager::getDeptName() {
	return  string("���۾���");

};
int SalesManager::getsla() {
	return m_salesVolume;
};