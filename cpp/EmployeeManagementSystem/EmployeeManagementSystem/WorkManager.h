#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include"staff.h"
#include"Salesman.h"
#include"SalesManager.h"
#include"Manager.h"

#include<fstream>
#define FILENAME "staffFile.txt"

class WorkerManager {
public:
	//����
	WorkerManager();

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_staffNum;

	//ְ������ָ��
	staff** m_staffArray;

	//���ְ��
	void Add_staff();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int getm_staffNum();

	//��ʼ��Ա��
	void init_staff();

	//��ʾְ��
	void Show_staff();

	//ɾ��Ա��
	void Del_staff();

	//�ж�Ա���Ƿ����  ������ڷ���ְ��������λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void mod_staff();

	//����ְ��
	void Find_staff();

	//��ְ���������
	void sort_staff();

	//����ļ�
	void Clean_File();

	//����
	~WorkerManager();
};
