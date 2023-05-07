#include"Manager.h"
using namespace std;

//构造函数
Manager::Manager() {};
Manager::Manager(int id, string name, int age, int deptid) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Age = age;
	this->m_DeptId = deptid;

};
//显示个人信息
void Manager::showInfo() {
	cout << "编号:" << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t年龄：" << this->m_Age
		<< "\t岗位：" << this->getDeptName() << endl;

};
//获取岗位
string Manager::getDeptName() {
	return  string("经理");
};

//获取销售额
int Manager::getsla() {
	return nop;
};