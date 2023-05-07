#include"Salesman.h"
using namespace std;



//构造函数
Salesman::Salesman() {};
Salesman::Salesman(int id, string name, int age, int deptid, int salesVolum) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Age = age;
	this->m_DeptId = deptid;
	this->m_salesVolume = salesVolum;
};
//显示个人信息
void Salesman::showInfo() {
	cout << "编号:" << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t年龄：" << this->m_Age
		<< "\t岗位：" << this->getDeptName()
		<< "\t销售额：" << this->m_salesVolume << endl;

};
//获取岗位
string Salesman::getDeptName() {
	return  string("销售员");
};

int Salesman::getsla() {
	return m_salesVolume;
};