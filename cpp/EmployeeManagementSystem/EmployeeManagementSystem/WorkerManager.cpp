#include"WorkManager.h"



WorkerManager::WorkerManager() {

	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;  //���Դ���
		//��ʼ��
		this->m_staffNum = 0;  //��¼����
		this->m_staffArray = nullptr;//����ָ��Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;  //���Դ���
		//��ʼ��
		this->m_staffNum = 0;  //��¼����
		this->m_staffArray = nullptr;//����ָ��Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�������������
	int num = this->getm_staffNum();
	//cout << "ְ��������Ϊ��" << num << endl;  //���Դ���   
	this->m_staffNum = num;
	//���ٿռ�	
	this->m_staffArray = new staff * [this->m_staffNum];
	//���ļ������ݴ浽������
	this->init_staff();

	//���Դ���
	/*for (int i = 0; i < this->m_staffNum; i++) {
		cout << "ְ����ţ�" << this->m_staffArray[i]->m_Id 
			<< " ְ��������" << this->m_staffArray[i]->m_Name 
			<< " ְ�����䣺" << this->m_staffArray[i]->m_Age 
			<< " ְ����λ��" << this->m_staffArray[i]->m_DeptId 
			<< " ���۶" << this->m_staffArray[i]->getsla() << endl;
	}*/
}

//չʾ�˵�
void WorkerManager::Show_Menu() {
	cout << "------------------------------------------------" << endl;
	cout << "----------��������Ӧ����ѡ����Ҫ�Ĺ���----------" << endl;
	cout << "----------1.��������        2.��ʾ����----------" << endl;
	cout << "----------3.��������        4.ɾ������----------" << endl;
	cout << "----------5.��ѯ����        6.��������----------" << endl;
	cout << "----------7.����ļ�        8.�˳�����----------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
};

//�Ƴ�ϵͳ
void WorkerManager::ExitSystem() {


	cout << "��ӭ�´���ʹ��" << endl;
	system("pause");
	exit(0);


}

//���ְ��
void WorkerManager::Add_staff() {
	cout << "�����������Ӷ����ˣ�" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//���
		
		//�������������
		for (int i = 0; i < addnum; i++) 
		{
		//��������¿ռ�Ĵ�С
				int newsize = this->m_staffNum + 1;//ԭ����¼��������������

				//�����Կռ�
				staff** newspace = new staff * [newsize];

				//��ԭ�������ݿ������¿ռ�
				if (this->m_staffArray != nullptr) 
				{
					for (int i = 0; i < this->m_staffNum; i++) 
					{
						newspace[i] = this->m_staffArray[i];
					}
		        }

			int id = 0;//���
			string name = "";//����
			int age = 0;//����
			int dselect = 0;//��λѡ��
			int salesvolum = 0;//���۶�
			
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.����Ա" << endl;
			cout << "2.����" << endl;
			cout << "3.���۾���" << endl;
			cin >> dselect;

			staff* staff = nullptr;
			switch (dselect)
			{
			case 1:
			   {
				cout << "�������" << i + 1 << "����Ա����ţ�" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "����Ա��������" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "����Ա�����䣺" << endl;
				cin >> age;
				cout << "�������" << i + 1 << "����Ա�����۶" << endl;
				cin >> salesvolum;
				int panduan =this->IsExist(id);

				if (panduan == -1) {
					staff = new Salesman(id, name, age, 1, salesvolum);
					//��������ְ�������浽������
					newspace[m_staffNum] = staff;
					
					//�ͷ�ԭ�еĿռ�
					delete[] this->m_staffArray;

					//�����¿ռ��ָ��
					this->m_staffArray = newspace;

					//�����µ�ְ������
					this->m_staffNum = newsize;

					//����ְ����Ϊ��
					this->m_FileIsEmpty = false;


					//��ʾ��ӳɹ�
					cout << "�ɹ����" << endl;

					this->save();
				}
				else {
					cout << "����Ѿ�����" << endl;
					

				}
				
				
			    }
				break;
			case 2:
			{
					cout << "�������" << i + 1 << "����Ա����ţ�" << endl;
					cin >> id;
					cout << "�������" << i + 1 << "����Ա��������" << endl;
					cin >> name;
					cout << "�������" << i + 1 << "����Ա�����䣺" << endl;
					cin >> age;
					
					int panduan = this->IsExist(id);
				
					if (panduan == -1) {
						staff = new Manager(id, name, age, 2);
						//��������ְ�������浽������
						newspace[m_staffNum] = staff;

						//�ͷ�ԭ�еĿռ�
						delete[] this->m_staffArray;

						//�����¿ռ��ָ��
						this->m_staffArray = newspace;

						//�����µ�ְ������
						this->m_staffNum = newsize;

						//����ְ����Ϊ��
						this->m_FileIsEmpty = false;


						//��ʾ��ӳɹ�
						cout << "�ɹ����" << endl;

						this->save();
					}
					else {
						cout << "����Ѿ�����" << endl;
						
					}
				
					
			}
				break;
			case 3:
			   {
				cout << "�������" << i + 1 << "����Ա����ţ�" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "����Ա��������" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "����Ա�����䣺" << endl;
				cin >> age;
				cout << "�������" << i + 1 << "����Ա�����۶" << endl;
				cin >> salesvolum;
				int panduan = this->IsExist(id);
				if (panduan == -1) {
					staff = new SalesManager(id, name, age, 3, salesvolum);
					//��������ְ�������浽������
					newspace[m_staffNum] = staff;

					//�ͷ�ԭ�еĿռ�
					delete[] this->m_staffArray;

					//�����¿ռ��ָ��
					this->m_staffArray = newspace;

					//�����µ�ְ������
					this->m_staffNum = newsize;

					//����ְ����Ϊ��
					this->m_FileIsEmpty = false;


					//��ʾ��ӳɹ�
					cout << "�ɹ����" << endl;

					this->save();
				}
				else {
					cout << "����Ѿ�����" << endl;
				
				}
								
			   }
				break;
			default:
				break;
			}
		
			


		}
	

	}
	else {
		cout << "������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�

	//������д���ļ�

	for (int i = 0; i < this->m_staffNum; i++) {


		ofs << this->m_staffArray[i]->m_Id << " "
            << this->m_staffArray[i]->m_Name << " "
			<< this->m_staffArray[i]->m_Age << " "
			<< this->m_staffArray[i]->m_DeptId << " "
			<< this->m_staffArray[i]->getsla() << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::getm_staffNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��

	int id;
	string name;
	int age;
	int dId;
	int sla;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> age && ifs >> dId && ifs >> sla) {
		//ͳ������
		num++;
	}
	return num;
};

//��ʼ��Ա��
void WorkerManager::init_staff() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//��
	int id;
	string name;
	int age;
	int dId;
	int sla;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> age && ifs >> dId && ifs >> sla) {
		staff* staff = nullptr;
		if (dId == 1)//����
		{
			staff = new Salesman(id, name, age, dId, sla);
		}
		else if (dId == 2)//����
		{
			staff = new Manager(id, name, age, dId);
		}
		else//���۾���
		{
			staff = new SalesManager(id, name, age, dId, sla);
		}
		this->m_staffArray[index] = staff;
		index++;
	}
	ifs.close();//���ļ�
};


//��ʾְ��
void WorkerManager::Show_staff() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "1.��ʾȫ��" << endl;
		cout << "2.��ʾ����Ա" << endl;
		cout << "3.��ʾ����" << endl;
		cout << "4.��ʾ���۾���" << endl;
		//for (int i = 0; i < m_staffNum; i++) {  ���Դ���
		//	//���ö�̬���ýӿ�
		//	this->m_staffArray[i]->showInfo();
		//}
		int sxx = 0;
		cin >> sxx;
		switch (sxx)
		{
		case 1:
			for (int i = 0; i < m_staffNum; i++) {
						//���ö�̬���ýӿ�
						this->m_staffArray[i]->showInfo();
					}
			break;
		case 2:
			for (int i = 0; i < m_staffNum; i++) {
				//���ö�̬���ýӿ�
				if (m_staffArray[i]->m_DeptId == 1) {
                      this->m_staffArray[i]->showInfo();
				}
				
			}
			break;
		case 3:
			for (int i = 0; i < m_staffNum; i++) {
				//���ö�̬���ýӿ�
				if (m_staffArray[i]->m_DeptId == 2) {
					this->m_staffArray[i]->showInfo();
				}

			}
			break;
		case 4:
			for (int i = 0; i < m_staffNum; i++) {
				//���ö�̬���ýӿ�
				if (m_staffArray[i]->m_DeptId == 3) {
					this->m_staffArray[i]->showInfo();
				}

			}
			break;
		default:
			break;
		}
		
	}
	//��������������Ļ
	system("pause");
	system("cls");
};


//ɾ��Ա��
void WorkerManager::Del_staff() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		//��Ա����ɾ��
		cout << "��������Ҫɾ����Ա����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index=this->IsExist(id);

		if (index != -1) {//˵��ְ�����ڣ�����ɾ��indexλ���ϵ�Ա��
			//����ǰ��  ������Ҫɾ��������
			for (int i = index; i < this->m_staffNum - 1; i++) {
				this->m_staffArray[i] = this->m_staffArray[i + 1];
			}
			this->m_staffNum--;//���������м�¼����Ա����
			//����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�!" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		/*int mysss = sizeof(m_staffArray) / sizeof(m_staffArray[0]);
		if (mysss==1) {
			m_FileIsEmpty = true;
		}*/
	}
	//�����������
	system("pause");
	system("cls");
};

//�ж�Ա���Ƿ����  ������ڷ���ְ��������λ�ã������ڷ���-1
int WorkerManager::IsExist(int id) {

	int index = -1;

	for (int i = 0; i < this->m_staffNum; i++) {
	   
		if (this->m_staffArray[i]->m_Id == id) {

			index = i;
			
			break;
		}
	}
	return index;
};

//�޸�ְ��
void WorkerManager::mod_staff() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "������Ա�����" << endl;
		int id;
		cin >> id;

		int ret=this->IsExist(id);
		if (ret != -1) {
			//���ҵ���ŵ�ְ��

			//delete m_staffArray[ret];(δ֪����)
			
			int newid = 0;
			string newname = " ";
			int newage = 0;//����
			int newdselect = 0;//��λѡ��
			int newsalesvolum = 0;//���۶�

			cout << "���ҵ���" << id << "��ְ������������ְ���ĸ�λ��" << endl;
            cout << "1.����Ա" << endl;
			cout << "2.����" << endl;
			cout << "3.���۾���" << endl;
			cin >> newdselect;

			staff* staff = nullptr;
			switch (newdselect)
			{
			case 1:
			      {
					cout << "�������µı��" << endl;
					cin >> newid;
					cout << "������������" << endl;
					cin >> newname;
					cout << "�������µ�����" << endl;
					cin >> newage;
					cout << "��������Ա�������۶�" << endl;
					cin >> newsalesvolum;
					int panduan = this->IsExist(newid);

					if (panduan == -1) 
					{
						staff = new Salesman(newid, newname, newage, 1, newsalesvolum);
						//��������
						this->m_staffArray[ret] = staff;

						cout << "�޸ĳɹ���" << endl;

						//���浽�ļ���
						this->save();
					}
					else 
					{
						cout << "����Ѿ�����" << endl;

					}
			      }
				
				
				break;
			case 2:
			      {
						cout << "�������µı��" << endl;
						cin >> newid;
						cout << "������������" << endl;
						cin >> newname;
						cout << "�������µ�����" << endl;
						cin >> newage;
						int panduan = this->IsExist(newid);

						if (panduan == -1) {
							staff = new Manager(newid, newname, newage, 2);
							//��������
							this->m_staffArray[ret] = staff;

							cout << "�޸ĳɹ���" << endl;

							//���浽�ļ���
							this->save();
						}
						else {
							cout << "����Ѿ�����" << endl;

						}
			       }
				
				
				break;
			case 3:
			      {
					cout << "�������µı��" << endl;
					cin >> newid;
					cout << "������������" << endl;
					cin >> newname;
					cout << "�������µ�����" << endl;
					cin >> newage;
					cout << "��������Ա�������۶�" << endl;
					cin >> newsalesvolum;
					int panduan = this->IsExist(newid);

					if (panduan == -1) {
						staff = new Salesman(newid, newname, newage, 3, newsalesvolum);
						//��������
						this->m_staffArray[ret] = staff;

						cout << "�޸ĳɹ���" << endl;

						//���浽�ļ���
						this->save();
					}
					else {
						cout << "����Ѿ�����" << endl;

					}
			      }
				
				
				break;
			default:
				break;
			}
			//11

		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");

};

//����ְ��
void WorkerManager::Find_staff(){
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {//��ְ����Ų�
			int id = 0;
			cout << "��������ҵ�ְ���ı�ţ�" << endl;
			cin >> id;

			int ret =IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_staffArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) {//��ְ��������
			string name = " ";
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�ж��Ƿ�鵽
			bool flag = false;//Ĭ��δ�ҵ�

			for (int i = 0; i < m_staffNum; i++) {
				
				if (this->m_staffArray[i]->m_Name == name) {
					cout << "���ҳɹ�,ְ�����Ϊ"
						<<this->m_staffArray[i]->m_Id 
						<< "��ְ������Ϣ���£�" << endl;
					flag = true;
					this->m_staffArray[i]->showInfo();
				}
				
			}
            if (flag == false) {
					cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else {//�������
			cout << "��������" << endl;

		}

	}

	system("pause");
	system("cls");
};

//��ְ���������
void WorkerManager::sort_staff() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ����Ž�������" << endl;
		cout << "2.��ְ����Ž��н���" << endl;
		
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_staffNum; i++) {
			int minormax = i;//���ֵ����Сֵ�±�

			for (int j = i + 1; j < m_staffNum; j++) 
			{

                if(select==1)//����
				{

					if (this->m_staffArray[minormax]->m_Id > this->m_staffArray[j]->m_Id) 
					{
						      
						      minormax = j;
					}
				}
				else //����
				{

					if (this->m_staffArray[minormax]->m_Id < this->m_staffArray[j]->m_Id) 
					{

						minormax = j;
					}
				}
		

			}

            //�ж�  ��������
			if (i != minormax) {
				staff* temp = this->m_staffArray[i];
				this->m_staffArray[i] = this->m_staffArray[minormax];
				this->m_staffArray[minormax] = temp;
			}

		}
		
		//cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();//���浽�ļ�
		this->Show_staff();//Show_staff()�����Լ��������������������ٽ�������
	}
};

//����ļ�
void WorkerManager::Clean_File() 
{
	cout << "ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) 
	{
		//����ļ�
		ofstream ofs(FILENAME,ios::trunc);  //ɾ���ļ������´���
		ofs.close();

		if (this->m_staffArray != nullptr) {
			
			//ɾ��������ְ������
			for (int i = 0; i < this->m_staffNum; i++) {
				
				//delete this->m_staffArray[i];
				
				m_staffArray[i] = nullptr;
			}

			//ɾ����������ָ��
			delete[] this->m_staffArray;
			this->m_staffArray = nullptr;
			this->m_staffNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;

	}
	system("pause");
	system("cls");

};

//��������
WorkerManager::~WorkerManager() 
{
	//����������Ѷ����������
	/*if (this->m_staffArray != nullptr) 
	{
		for (int i = 0; i < this->m_staffNum; i++) 
		{
			if (this->m_staffArray[i] != nullptr) 
			{
				delete this->m_staffArray[i];
			}
	    }
		delete[] this->m_staffArray;
		this->m_staffArray = nullptr;
	}*/
}
