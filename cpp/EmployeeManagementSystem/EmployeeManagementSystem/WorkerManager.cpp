#include"WorkManager.h"



WorkerManager::WorkerManager() {

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;  //测试代码
		//初始化
		this->m_staffNum = 0;  //记录人数
		this->m_staffArray = nullptr;//数组指针为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		//cout << "文件为空" << endl;  //测试代码
		//初始化
		this->m_staffNum = 0;  //记录人数
		this->m_staffArray = nullptr;//数组指针为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有数据
	int num = this->getm_staffNum();
	//cout << "职工的人数为：" << num << endl;  //测试代码   
	this->m_staffNum = num;
	//开辟空间	
	this->m_staffArray = new staff * [this->m_staffNum];
	//将文件中数据存到数组中
	this->init_staff();

	//测试代码
	/*for (int i = 0; i < this->m_staffNum; i++) {
		cout << "职工编号：" << this->m_staffArray[i]->m_Id 
			<< " 职工姓名：" << this->m_staffArray[i]->m_Name 
			<< " 职工年龄：" << this->m_staffArray[i]->m_Age 
			<< " 职工岗位：" << this->m_staffArray[i]->m_DeptId 
			<< " 销售额：" << this->m_staffArray[i]->getsla() << endl;
	}*/
}

//展示菜单
void WorkerManager::Show_Menu() {
	cout << "------------------------------------------------" << endl;
	cout << "----------请输入相应数字选择需要的功能----------" << endl;
	cout << "----------1.增加数据        2.显示数据----------" << endl;
	cout << "----------3.更新数据        4.删除数据----------" << endl;
	cout << "----------5.查询数据        6.排序数据----------" << endl;
	cout << "----------7.清空文件        8.退出程序----------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
};

//推出系统
void WorkerManager::ExitSystem() {


	cout << "欢迎下次再使用" << endl;
	system("pause");
	exit(0);


}

//添加职工
void WorkerManager::Add_staff() {
	cout << "请问你想增加多少人？" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0) {
		//添加
		
		//批量添加新数据
		for (int i = 0; i < addnum; i++) 
		{
		//计算添加新空间的大小
				int newsize = this->m_staffNum + 1;//原来记录人数加新增人数

				//开辟性空间
				staff** newspace = new staff * [newsize];

				//将原来的数据拷贝到新空间
				if (this->m_staffArray != nullptr) 
				{
					for (int i = 0; i < this->m_staffNum; i++) 
					{
						newspace[i] = this->m_staffArray[i];
					}
		        }

			int id = 0;//编号
			string name = "";//名字
			int age = 0;//年龄
			int dselect = 0;//岗位选择
			int salesvolum = 0;//销售额
			
			cout << "请选择该职工的岗位" << endl;
			cout << "1.销售员" << endl;
			cout << "2.经理" << endl;
			cout << "3.销售经理" << endl;
			cin >> dselect;

			staff* staff = nullptr;
			switch (dselect)
			{
			case 1:
			   {
				cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个新员工姓名：" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个新员工年龄：" << endl;
				cin >> age;
				cout << "请输入第" << i + 1 << "个新员工销售额：" << endl;
				cin >> salesvolum;
				int panduan =this->IsExist(id);

				if (panduan == -1) {
					staff = new Salesman(id, name, age, 1, salesvolum);
					//将创建的职工，保存到数组中
					newspace[m_staffNum] = staff;
					
					//释放原有的空间
					delete[] this->m_staffArray;

					//更新新空间的指向
					this->m_staffArray = newspace;

					//更新新的职工人数
					this->m_staffNum = newsize;

					//更新职工不为空
					this->m_FileIsEmpty = false;


					//提示添加成功
					cout << "成功添加" << endl;

					this->save();
				}
				else {
					cout << "编号已经存在" << endl;
					

				}
				
				
			    }
				break;
			case 2:
			{
					cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
					cin >> id;
					cout << "请输入第" << i + 1 << "个新员工姓名：" << endl;
					cin >> name;
					cout << "请输入第" << i + 1 << "个新员工年龄：" << endl;
					cin >> age;
					
					int panduan = this->IsExist(id);
				
					if (panduan == -1) {
						staff = new Manager(id, name, age, 2);
						//将创建的职工，保存到数组中
						newspace[m_staffNum] = staff;

						//释放原有的空间
						delete[] this->m_staffArray;

						//更新新空间的指向
						this->m_staffArray = newspace;

						//更新新的职工人数
						this->m_staffNum = newsize;

						//更新职工不为空
						this->m_FileIsEmpty = false;


						//提示添加成功
						cout << "成功添加" << endl;

						this->save();
					}
					else {
						cout << "编号已经存在" << endl;
						
					}
				
					
			}
				break;
			case 3:
			   {
				cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个新员工姓名：" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个新员工年龄：" << endl;
				cin >> age;
				cout << "请输入第" << i + 1 << "个新员工销售额：" << endl;
				cin >> salesvolum;
				int panduan = this->IsExist(id);
				if (panduan == -1) {
					staff = new SalesManager(id, name, age, 3, salesvolum);
					//将创建的职工，保存到数组中
					newspace[m_staffNum] = staff;

					//释放原有的空间
					delete[] this->m_staffArray;

					//更新新空间的指向
					this->m_staffArray = newspace;

					//更新新的职工人数
					this->m_staffNum = newsize;

					//更新职工不为空
					this->m_FileIsEmpty = false;


					//提示添加成功
					cout << "成功添加" << endl;

					this->save();
				}
				else {
					cout << "编号已经存在" << endl;
				
				}
								
			   }
				break;
			default:
				break;
			}
		
			


		}
	

	}
	else {
		cout << "输入数据有误" << endl;
	}

	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件

	//将数据写入文件

	for (int i = 0; i < this->m_staffNum; i++) {


		ofs << this->m_staffArray[i]->m_Id << " "
            << this->m_staffArray[i]->m_Name << " "
			<< this->m_staffArray[i]->m_Age << " "
			<< this->m_staffArray[i]->m_DeptId << " "
			<< this->m_staffArray[i]->getsla() << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkerManager::getm_staffNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读

	int id;
	string name;
	int age;
	int dId;
	int sla;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> age && ifs >> dId && ifs >> sla) {
		//统计人数
		num++;
	}
	return num;
};

//初始化员工
void WorkerManager::init_staff() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读
	int id;
	string name;
	int age;
	int dId;
	int sla;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> age && ifs >> dId && ifs >> sla) {
		staff* staff = nullptr;
		if (dId == 1)//销售
		{
			staff = new Salesman(id, name, age, dId, sla);
		}
		else if (dId == 2)//经理
		{
			staff = new Manager(id, name, age, dId);
		}
		else//销售经理
		{
			staff = new SalesManager(id, name, age, dId, sla);
		}
		this->m_staffArray[index] = staff;
		index++;
	}
	ifs.close();//关文件
};


//显示职工
void WorkerManager::Show_staff() {
	//判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "1.显示全部" << endl;
		cout << "2.显示销售员" << endl;
		cout << "3.显示经理" << endl;
		cout << "4.显示销售经理" << endl;
		//for (int i = 0; i < m_staffNum; i++) {  测试代码
		//	//利用多态调用接口
		//	this->m_staffArray[i]->showInfo();
		//}
		int sxx = 0;
		cin >> sxx;
		switch (sxx)
		{
		case 1:
			for (int i = 0; i < m_staffNum; i++) {
						//利用多态调用接口
						this->m_staffArray[i]->showInfo();
					}
			break;
		case 2:
			for (int i = 0; i < m_staffNum; i++) {
				//利用多态调用接口
				if (m_staffArray[i]->m_DeptId == 1) {
                      this->m_staffArray[i]->showInfo();
				}
				
			}
			break;
		case 3:
			for (int i = 0; i < m_staffNum; i++) {
				//利用多态调用接口
				if (m_staffArray[i]->m_DeptId == 2) {
					this->m_staffArray[i]->showInfo();
				}

			}
			break;
		case 4:
			for (int i = 0; i < m_staffNum; i++) {
				//利用多态调用接口
				if (m_staffArray[i]->m_DeptId == 3) {
					this->m_staffArray[i]->showInfo();
				}

			}
			break;
		default:
			break;
		}
		
	}
	//按任意键后清空屏幕
	system("pause");
	system("cls");
};


//删除员工
void WorkerManager::Del_staff() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		//按员工号删除
		cout << "请输入想要删除的员工编号：" << endl;
		int id = 0;
		cin >> id;

		int index=this->IsExist(id);

		if (index != -1) {//说明职工存在，需求删除index位置上的员工
			//数据前移  覆盖需要删除的数据
			for (int i = index; i < this->m_staffNum - 1; i++) {
				this->m_staffArray[i] = this->m_staffArray[i + 1];
			}
			this->m_staffNum--;//更新数组中记录的人员个数
			//数据同步更新到文件中
			this->save();

			cout << "删除成功!" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
		/*int mysss = sizeof(m_staffArray) / sizeof(m_staffArray[0]);
		if (mysss==1) {
			m_FileIsEmpty = true;
		}*/
	}
	//按任意键清屏
	system("pause");
	system("cls");
};

//判断员工是否存在  如果存在返回职工的所长位置，不存在返回-1
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

//修改职工
void WorkerManager::mod_staff() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入员工编号" << endl;
		int id;
		cin >> id;

		int ret=this->IsExist(id);
		if (ret != -1) {
			//查找到编号的职工

			//delete m_staffArray[ret];(未知问题)
			
			int newid = 0;
			string newname = " ";
			int newage = 0;//年龄
			int newdselect = 0;//岗位选择
			int newsalesvolum = 0;//销售额

			cout << "查找到：" << id << "号职工，请输入新职工的岗位：" << endl;
            cout << "1.销售员" << endl;
			cout << "2.经理" << endl;
			cout << "3.销售经理" << endl;
			cin >> newdselect;

			staff* staff = nullptr;
			switch (newdselect)
			{
			case 1:
			      {
					cout << "请输入新的编号" << endl;
					cin >> newid;
					cout << "请输入新姓名" << endl;
					cin >> newname;
					cout << "请输入新的年龄" << endl;
					cin >> newage;
					cout << "请输入新员工的销售额" << endl;
					cin >> newsalesvolum;
					int panduan = this->IsExist(newid);

					if (panduan == -1) 
					{
						staff = new Salesman(newid, newname, newage, 1, newsalesvolum);
						//更新数据
						this->m_staffArray[ret] = staff;

						cout << "修改成功！" << endl;

						//保存到文件中
						this->save();
					}
					else 
					{
						cout << "编号已经存在" << endl;

					}
			      }
				
				
				break;
			case 2:
			      {
						cout << "请输入新的编号" << endl;
						cin >> newid;
						cout << "请输入新姓名" << endl;
						cin >> newname;
						cout << "请输入新的年龄" << endl;
						cin >> newage;
						int panduan = this->IsExist(newid);

						if (panduan == -1) {
							staff = new Manager(newid, newname, newage, 2);
							//更新数据
							this->m_staffArray[ret] = staff;

							cout << "修改成功！" << endl;

							//保存到文件中
							this->save();
						}
						else {
							cout << "编号已经存在" << endl;

						}
			       }
				
				
				break;
			case 3:
			      {
					cout << "请输入新的编号" << endl;
					cin >> newid;
					cout << "请输入新姓名" << endl;
					cin >> newname;
					cout << "请输入新的年龄" << endl;
					cin >> newage;
					cout << "请输入新员工的销售额" << endl;
					cin >> newsalesvolum;
					int panduan = this->IsExist(newid);

					if (panduan == -1) {
						staff = new Salesman(newid, newname, newage, 3, newsalesvolum);
						//更新数据
						this->m_staffArray[ret] = staff;

						cout << "修改成功！" << endl;

						//保存到文件中
						this->save();
					}
					else {
						cout << "编号已经存在" << endl;

					}
			      }
				
				
				break;
			default:
				break;
			}
			//11

		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");

};

//查找职工
void WorkerManager::Find_staff(){
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找的方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工的姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {//按职工编号查
			int id = 0;
			cout << "请输入查找的职工的编号：" << endl;
			cin >> id;

			int ret =IsExist(id);
			if (ret != -1) {
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_staffArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) {//按职工姓名查
			string name = " ";
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//判断是否查到
			bool flag = false;//默认未找到

			for (int i = 0; i < m_staffNum; i++) {
				
				if (this->m_staffArray[i]->m_Name == name) {
					cout << "查找成功,职工编号为"
						<<this->m_staffArray[i]->m_Id 
						<< "号职工的信息如下：" << endl;
					flag = true;
					this->m_staffArray[i]->showInfo();
				}
				
			}
            if (flag == false) {
					cout << "查找失败，查无此人" << endl;
			}
		}
		else {//输入错误
			cout << "输入有误！" << endl;

		}

	}

	system("pause");
	system("cls");
};

//按职工编号排序
void WorkerManager::sort_staff() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;

		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号进行升序" << endl;
		cout << "2.按职工编号进行降序" << endl;
		
		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_staffNum; i++) {
			int minormax = i;//最大值或最小值下标

			for (int j = i + 1; j < m_staffNum; j++) 
			{

                if(select==1)//升序
				{

					if (this->m_staffArray[minormax]->m_Id > this->m_staffArray[j]->m_Id) 
					{
						      
						      minormax = j;
					}
				}
				else //降序
				{

					if (this->m_staffArray[minormax]->m_Id < this->m_staffArray[j]->m_Id) 
					{

						minormax = j;
					}
				}
		

			}

            //判断  交换数据
			if (i != minormax) {
				staff* temp = this->m_staffArray[i];
				this->m_staffArray[i] = this->m_staffArray[minormax];
				this->m_staffArray[minormax] = temp;
			}

		}
		
		//cout << "排序成功！排序后的结果为：" << endl;
		this->save();//保存到文件
		this->Show_staff();//Show_staff()函数以及做了清屏操作，不用再进行清屏
	}
};

//清空文件
void WorkerManager::Clean_File() 
{
	cout << "确定清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) 
	{
		//清空文件
		ofstream ofs(FILENAME,ios::trunc);  //删除文件后重新创建
		ofs.close();

		if (this->m_staffArray != nullptr) {
			
			//删除堆区的职工对象
			for (int i = 0; i < this->m_staffNum; i++) {
				
				//delete this->m_staffArray[i];
				
				m_staffArray[i] = nullptr;
			}

			//删除堆区数组指针
			delete[] this->m_staffArray;
			this->m_staffArray = nullptr;
			this->m_staffNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;

	}
	system("pause");
	system("cls");

};

//析构函数
WorkerManager::~WorkerManager() 
{
	//程序运行完把堆区数据清空
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
