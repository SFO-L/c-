#include"Manager.h"
using namespace std;

//���캯��
Manager::Manager() {};
Manager::Manager(int id, string name, int age, int deptid) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Age = age;
	this->m_DeptId = deptid;

};
//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "���:" << this->m_Id
		<< "\t����:" << this->m_Name
		<< "\t���䣺" << this->m_Age
		<< "\t��λ��" << this->getDeptName() << endl;

};
//��ȡ��λ
string Manager::getDeptName() {
	return  string("����");
};

//��ȡ���۶�
int Manager::getsla() {
	return nop;
};