#include<iostream>
using namespace std;
#include"staff.h"
#include"Salesman.h"
#include"Manager.h"
#include"SalesManager.h"
#include"WorkManager.h"

int main() {
	//test
	/*staff* staff = NULL;
	staff = new SalesManager(1, "张三",18,1,200,500);
	staff->showInfo();*/

	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;
	while (true) {
		//展示菜单
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice) {
		case 1://增加数据
			wm.Add_staff();
			break;
		case 2://显示数据
			wm.Show_staff();
			break;
		case 3://更新数据
			wm.mod_staff();
			break;
		case 4://删除数据
			wm.Del_staff();
			break;
		case 5://查询数据
			wm.Find_staff();
			break;
		case 6://排序数据
			wm.sort_staff();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		case 8://退出系统
			wm.ExitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}

	}





	system("pause");

	return 0;

}