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
	staff = new SalesManager(1, "����",18,1,200,500);
	staff->showInfo();*/

	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;
	while (true) {
		//չʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1://��������
			wm.Add_staff();
			break;
		case 2://��ʾ����
			wm.Show_staff();
			break;
		case 3://��������
			wm.mod_staff();
			break;
		case 4://ɾ������
			wm.Del_staff();
			break;
		case 5://��ѯ����
			wm.Find_staff();
			break;
		case 6://��������
			wm.sort_staff();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		case 8://�˳�ϵͳ
			wm.ExitSystem();
			break;
		default:
			system("cls");//����
			break;
		}

	}





	system("pause");

	return 0;

}