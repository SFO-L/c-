#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"staff.h"
#include"Salesman.h"
#include"SalesManager.h"
#include"Manager.h"

#include<fstream>
#define FILENAME "staffFile.txt"

class WorkerManager {
public:
	//构造
	WorkerManager();

	//显示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_staffNum;

	//职工数组指针
	staff** m_staffArray;

	//添加职工
	void Add_staff();

	//保存文件
	void save();

	//判断文件是否为空标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int getm_staffNum();

	//初始化员工
	void init_staff();

	//显示职工
	void Show_staff();

	//删除员工
	void Del_staff();

	//判断员工是否存在  如果存在返回职工的所长位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void mod_staff();

	//查找职工
	void Find_staff();

	//按职工编号排序
	void sort_staff();

	//清空文件
	void Clean_File();

	//析构
	~WorkerManager();
};
