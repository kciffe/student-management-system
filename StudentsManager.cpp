#include "StudentsManager.h"
#include<fstream>
#include<string>

bool AllisNum(string str);
bool isChinese(string str);

//展示菜单功能
void StudentsManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用学籍管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加学生信息  *************" << endl;
	cout << "*************  2.显示学生信息  *************" << endl;
	cout << "*************  3.依据条件删除信息  *********" << endl;
	cout << "*************  4.依据条件修改信息  *********" << endl;
	cout << "*************  5.依据条件查询信息  *********" << endl;
	cout << "*************  6.统计班级不及格人数  *******" << endl;
	cout << "*************  7.统计课程成绩分布比  *******" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//构造函数
StudentsManager::StudentsManager()
{
	OutputFile("学生信息.txt");
	OutputFile("成绩信息.txt");
	OutputFile("课程信息.txt");
}

//输出文件
void StudentsManager::OutputFile(string ss) {
	Max = 0;

	//读取文件操作
	ifstream ifs;
	ifs.open(ss, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开错误" << endl;
	}


	if (ss == "学生信息.txt"){
		//建立链表学生文件
		first = new Node;		//定义头指针
		first->next = NULL;
		Node* s = NULL;
		Node* r = first;
		int flag = 1;                         //做判断标准，以便退出循环

		while (flag == 1)
		{

			s = new Node;
			r->next = s; r = s;
			if (ifs >> s->data.ID>> s->data.name >> s->data.sex>>s->data.major ) {
				flag = 1;
				Max++;
			}
			else {
				r->next = NULL;
				flag = 0;
			}
		}
		s = NULL;
		delete s;
		r = NULL;
		delete r;

	}
	else if (ss == "成绩信息.txt") {
		firstSc = new NodeSc;
		firstSc->next = NULL;
		NodeSc* s = NULL;
		NodeSc* r = firstSc;
		int flag = 1;

		while (flag == 1)
		{

			s = new NodeSc;
			r->next = s; r = s;
			if (ifs >> s->data.ID >> s->data.courseID >> s->data.socres) {
				flag = 1;
				Max1++;
			}
			else {
				r->next = NULL;
				flag = 0;
			}
		}
		s = NULL;
		delete s;
		r = NULL;
		delete r;
	}
	else if(ss == "课程信息.txt") {
		firstCo = new NodeCo;
		firstCo->next = NULL;
		NodeCo* s = NULL;
		NodeCo* r = firstCo;
		int flag = 1;

		while (flag == 1)
		{

			s = new NodeCo;
			r->next = s; r = s;
			if (ifs >> s->data.courseID >> s->data.courseName >> s->data.credit>>s->data.time) {
				flag = 1;
				Max2++;
			}
			else {
				r->next = NULL;
				flag = 0;
			}
		}

		s = NULL;
		delete s;
		r = NULL;
		delete r;
	}
	else {					//检验未知错误
		printf("error of ss表格名称");
	}

	//关闭文件
	ifs.close();
}


//输入文件
void StudentsManager::InputFile(string ss) {
	ofstream ofs;

	ofs.open(ss, ios::out);
	if (ss == "学生信息.txt") {
		Node* p = first->next;
		while (p->next != NULL)
		{
			ofs << p->data.ID << " " << p->data.name << " " << p->data.sex << " " << p->data.major << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else if (ss == "成绩信息.txt") {
		NodeSc* p = firstSc->next;
		while (p->next!=NULL)
		{
			ofs << p->data.ID << " " << p->data.courseID << " " << p->data.socres << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else if (ss == "课程信息.txt") {
		NodeCo* p = firstCo->next;
		while (p->next != NULL)
		{
			ofs << p->data.courseID << " " << p->data.courseName << " " << p->data.credit << " " << p->data.time<< endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else { printf("输出文件的判别信息错误"); };

	ofs.close();
}


StudentsManager::~StudentsManager(){}

//显示学生信息头
void StudentsManager::studentstitle() {			//needModify!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "学号" << "\t" << "\t" << "\t" << "姓名" << "\t" << "\t" << "性别"<< "\t" << "\t" << "专业" /* << "\t" << "\t" << "\t" << "高数" << "\t" << "\t" << "大英" << "\t" "\t" << "大物" << "\t""\t" << "总分" */ << endl;
}

//显示科目信息头
void StudentsManager::studentScoresTitle() {			
	cout << "学号" << "\t" << "\t" << "\t" << "姓名" << "\t" << "\t" << "科目ID" << "\t" << "\t" << "\t" << "科目" << "\t" << "\t" << "\t" << "分数" /* << "\t" << "\t" << "\t" << "高数" << "\t" << "\t" << "大英" << "\t" "\t" << "大物" << "\t""\t" << "总分" */ << endl;
}

//显示课程信息头
void StudentsManager::courseTitle(){
	cout << "课程号" << "\t" << "\t" << "\t" << "课程名" << "\t" << "\t" << "学分" << "\t" << "\t" << "\t" << "学时" << endl;
}
//显示学生信息
void StudentsManager::display() {
	OutputFile("学生信息.txt");
	
	//输出显示学生信息
	studentstitle();
	int num = 1;
	Node* p = first->next;

	while (p->next != NULL)
	{
		//p->data.sum = p->data.math + p->data.english + p->data.physics;
		cout << p->data.ID << "\t" << "\t" << p->data.name << "\t" "\t" << p->data.sex << "\t" "\t" << p->data.major /*<< "\t" "\t" << p->data.math << "\t" << "\t" << p->data.english << "\t" << "\t" << p->data.physics << "\t" << "\t" << p->data.sum */<< endl;
		p = p->next;
	}
	cout << endl;
}

//添加学生
void StudentsManager::inputStudent() {
	int flag = 1;//是否继续添加学生信息的条件
	
	while (flag==1)
	{
		int flag1 = 0;
		int flag2 = 0;
		Node* s = NULL;
		s = new Node;
		s->next = first->next;
		first->next = s;
		//学号正确性，重复性检验
		string num = "";
		cout << "请输入12位有效学生学号：";
		while (flag1 == 0)
		{
			flag1 = 1;
			cin >> num;
			if (num.length() != 12 ||  stoi(num.substr(0, 4)) > 2021 || !AllisNum(num)) {
				flag1 = 0;
				cout << "输入错误，请重新输入：";
				continue;
			}

			Node* z = first->next;
			while (z->next != NULL)
			{
				if (num == z->data.ID) {
					flag1 = 0;
					cout << "该学号已存在，请重新输入：";
					break;
				}
				z = z->next;
			}
		}
		s->data.ID = num;

		int flag11 = 0;
		while(flag11==0){
			cout << "请输入学生姓名：";
			cin >> s->data.name;
			if (!isChinese(s->data.name) && s->data.name.length() > 20 || s->data.name.length() > 8) {
				cout << "姓名输入错误，请重新输入：";
			}
			else { flag11 = 1; }
		}
		
		//性别正确性检验
		string sex = "";
		cout << "请输入学生性别“男/女/M/F”：";
		while (flag2 == 0)
		{

			cin >> sex;
			if (sex == "男" || sex == "女" || sex=="M" || sex=="F") {
				break;
			}
			cout << "输入错误，请重新输入：";
		}
		s->data.sex = sex;

		string co = "";
		while (1) {
			cout << "请输入学生班级：";
			cin >> co;
			if (co.length() > 8) {
				cout << "班级输入错误，请重新输入：";
			}
			else { break; }
		}
		s->data.major = co;
		s = NULL;
		delete s;
		Max++;

		ofstream ofs;

		ofs.open("学生信息.txt", ios::out);//内容确定无误后输入到文件中

		Node* p = first->next;
		//for (int j = 0; j < Max; j++)
		while(p->next!=NULL)
		{
			ofs << p->data.ID << " " << p->data.name << " " << p->data.sex << " " << p->data.major << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
		ofs.close();
		
		cout << "输入1继续添加学生，输入0则返回首页";
		cin >> flag;
		while (flag !=0 && flag!=1)
		{
			
			if (flag != 0  &&  flag != 1) {
				cout << "请输入正确操作——输入1继续添加学生，输入0则退出返回首页";
				cin >> flag;
			}
		}
	}
	
}
//添加课程
void StudentsManager::inputCourse() {
	int flag = 1;//是否继续添加信息的条件
	int flag1 = 0;
	while (flag == 1)
	{
		Max1++;
		NodeCo* s = NULL;
		s = new NodeCo;
		s->next = firstCo->next;
		firstCo->next = s;
		//课程号正确性，重复性检验
		string num = "";
		cout << "请输入8位有效课程号：";
		while (flag1 == 0)
		{
			flag1 = 1;
			cin >> num;
			if (num.length()!=8) {
				flag1 = 0;
				cout << "输入错误，请重新输入：";
				continue;
			}

			NodeCo* z = firstCo->next;
			while (z->next != NULL)
			{
				if (num == z->data.courseID) {
					flag1 = 0;
					cout << "该课程号已存在，请重新输入：";
					break;
				}
				z = z->next;
			}
			z = NULL;
			delete z;
		}
		s->data.courseID = num;

		cout << "请输入课程名：";
		cin >> s->data.courseName;
		cout << "请输入学分";
		cin >> s->data.credit;
		cout << "请输入学时";
		cin >> s->data.time;
		s = NULL;
		delete s;
		ofstream ofs;

		ofs.open("课程信息.txt", ios::out);//内容确定无误后输入到文件中

		NodeCo* p = firstCo->next;
		for (int j = 0; j < Max1; j++)
		{
			ofs << p->data.courseID << " " << p->data.courseName << " " << p->data.credit << " " << p->data.time << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
		ofs.close();

		cout << "输入1继续添加课程，输入0则返回首页";
		cin >> flag;
		while (flag != 0 && flag != 1)
		{

			if (flag != 0 && flag != 1) {
				cout << "请输入正确操作——输入1继续添加课程，输入0则退出返回首页";
				cin >> flag;
			}
		}

	}

}
//添加成绩 
void StudentsManager::inputScore() {
	int flag = 1;//是否继续添加信息的条件

	while (flag == 1)
	{
		Max2++;
		int flag1 = 0;
		int flag2 = 0;
		int flag3 = 0;
		//Max++;
		NodeSc* s = NULL;
		s = new NodeSc;
		s->next = firstSc->next;
		firstSc->next = s;
		//学号正确性，重复性检验
		string num="", num1 = "";
		cout << "请输入12位有效学生学号：";
		while (flag1 == 0)
		{
			flag1 = 1;
			if(flag2==0){
				cin >> num;
				if (num.length() != 12 || stoi(num.substr(0, 4)) > 2021 || !AllisNum(num)) {
					flag1 = 0;
					cout << "学号格式错误，请重新输入,";
					continue;		
				}
				else if (!AccurateSearchInt(num)) {
					flag1 = 0;
					cout << "学号不存在，请重新输入,";
					continue;
				}
			}
			flag2 = 1;
			//检查课程号
			cout << "请输入课程号:";
			cin >> num1;
			if (num1.length() != 8) {
				flag1 = 0;
				cout << "课程号格式错误，请重新输入,";
				continue;
			}
			else if (!AccurateSearchCo(num1)) {
				flag1 = 0;
				cout << "课程号不存在，请重新输入,";
				continue;
			}

			NodeSc* z = firstSc->next;
			while (z->next != NULL)
			{
				if (num == z->data.ID && num1==z->data.courseID) {
					flag3 = 1;
					cout << "该学号下的课程成绩已存在"<<endl;
					break;
				}
				z = z->next;
			}
			z = NULL;
			delete z;
		}
		//成绩不存在时可录入
		if (flag3 == 0) {
			s->data.ID = num;
			s->data.courseID = num1;

			//分数正确性检验
			cout << "请输入分数:";
			int num2 = 0;
			while (1)
			{

				cin >> num2;
				if (num2 >= 0 && num2 <= 100) {
					break;
				}
				else {
					cout << "输入错误，请重新输入分数：";
				}
			}
			s->data.socres = num2;

			ofstream ofs;

			ofs.open("成绩信息.txt", ios::out);//内容确定无误后输入到文件中

			NodeSc* p = firstSc->next;
			for (int j = 0; j < Max2; j++)
			{
				ofs << p->data.ID << " " << p->data.courseID << " " << p->data.socres << endl;
				p = p->next;
			}
			p = NULL;
			delete p;
			ofs.close();
		}
		
		cout << "输入1继续添加成绩，输入0则返回首页:";
		cin >> flag;
		while (flag != 0 && flag != 1)
		{

			if (flag != 0 && flag != 1) {
				cout << "请输入正确操作——输入1继续添加成绩，输入0则退出返回首页";
				cin >> flag;
			}
		}
		s = NULL;
		delete s;
	}

}
//删除数据
void StudentsManager::DeleteStudent() {

	int flag = 1;
	string choice = "123";
	while (flag == 1)
	{
		cout << "请输入查找模式"<<endl<<"【1】据学号删除学生"<<endl<<"【2】据课程号删除课程"<<endl<<"【0】返回首页:";
		cin >> choice;
		if (choice!="1"&& choice!="2"&& choice!="0") {
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //退出程序
			flag = 0;
			break;
		case 1: //据学号删除学生
			AccurateDelete();
			flag = 0;
			break;
		case 2: //据课程号删除课程
			deleteCourse();
			flag = 0;
			break;
		default:
			//从新进入本循环
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}
	}
}

//据学号删除学生
void StudentsManager::AccurateDelete() {
	int flag = 0;
	string studentId = "1";
	while(flag==0){
		cout << "请输入需要删除的学生学号";
		cin >> studentId;
		cout << endl;
		Node* p = first->next, * q = first;
		NodeSc* ps = firstSc->next, * qs = firstSc;
		//删除学生文件的信息
		while (p->next != NULL)
		{
			if (p->data.ID == studentId) {
				flag = 1;
				q->next = p->next;
				delete p;
				p = NULL;//消除野指针
				cout << "删除成功！" << endl;
				break;
			}
			q = q->next;
			p = p->next;
		}
		if (flag == 0) {
			cout << "不存在该学生信息，请重新操作" << endl;
			continue;
		}
		//更改本地文件
		InputFile("学生信息.txt");
		//删除成绩文件的信息
		while (ps->next != NULL)
		{
			if (ps->data.ID == studentId) {
				qs->next = ps->next;
				delete ps;
				ps = NULL;//消除野指针
				cout << "删除成功！" << endl;
				break;
			}
			qs = qs->next;
			ps = ps->next;
		}
		InputFile("成绩信息.txt");
		p = NULL;
		delete p;
		ps = NULL;
		delete ps;
		qs = NULL;
		delete qs;
	}
	cout << "输入1继续删除，输入0退出：";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "输入错误重新输入：";
		cin >> flag;
	}
	if (flag == 1) {
		AccurateDelete();
	}
}

//据课程号删除课程
void StudentsManager::deleteCourse() {
	int flag = 0;
	string cI = "1";
	while (flag == 0) {
		cout <<endl<< "请输入需要删除的课程号";
		cin >> cI;
		cout << endl;
		NodeCo* pc = firstCo->next, * qc = firstCo;
		NodeSc* ps = firstSc->next, * qs = firstSc;
		//删除学生文件的信息
		while (pc->next != NULL)
		{
			if (pc->data.courseID == cI) {
				flag = 1;
				qc->next = pc->next;
				delete pc;
				pc = NULL;//消除野指针
				cout << "删除成功！" << endl;
				break;
			}
			qc = qc->next;
			pc = pc->next;
		}
		if (flag == 0) {
			cout << "不存在该课程信息，请重新操作" << endl;
			continue;
		}
		//更改本地文件
		InputFile("课程信息.txt");
		//删除成绩文件的信息
		while (ps->next != NULL)
		{
			if (ps->data.courseID == cI) {
				qs->next = ps->next;
				delete ps;
				ps = NULL;//消除野指针
				cout << "删除成功！" << endl;
				break;
			}
			qs = qs->next;
			ps = ps->next;
		}
		InputFile("成绩信息.txt");
		pc = NULL;
		delete pc;
		ps = NULL;
		delete ps;
		qc = NULL;
		delete qc;
		qs = NULL;
		delete qs;
	}
	cout << "输入1继续查找，输入0退出：";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "输入错误重新输入：";
		cin >> flag;
	}
	if (flag == 1) {
		deleteCourse();
	}
}


//查找信息
void StudentsManager::SeachStudent() {
	int flag = 1;
	string choice = "123";
	//cout << AllisNum(choice);
	while (flag == 1)
	{
		cout << "请输入查找模式:"<<endl<<"【1】据学号查找学生信息"<<endl<<"【2】据学号查询该学生各科成绩"<<endl<<"【3】据学号 + 课程号查询科目成绩"<<endl<<"【4】据课程号查询课程信息"<<endl<<"【0】返回首页"<<endl;
		cin >> choice;
		if (!AllisNum(choice)) {
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //退出程序
			flag = 0;
			break;
		case 1: //据学号查找学生信息
			AccurateSearch();
			flag = 0;
			break;
		case 2: //据学号查询该学生各科成绩
			FuzzySearchScores();
			flag = 0;
			break;
		case 3: //据学号+课程号查询科目成绩
			AccurateSearchScores();
			flag = 0;
			break;
		case 4://据课程号查询课程信息
			SearchByCoID();
			flag = 0;
			break;
		default:
			//从新进入本循环
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}
	}
}

//据学号精准查找学生信息
void StudentsManager::AccurateSearch() {
	int flag = 0;
	string studentId = "1";
	cout << "请输入需要查找的学生学号";
	cin >> studentId;
	cout << endl;
	Node* p = first->next;
	while (p->next != NULL)
	{
		if (p->data.ID == studentId) {
			flag = 1;
			studentstitle();
			cout<< p->data.ID << "\t" << "\t" << p->data.name << "\t" "\t" << p->data.sex << "\t" "\t" << p->data.major /* << "\t" "\t" << p->data.math << "\t" << "\t" << p->data.english << "\t" << "\t" << p->data.physics << "\t" << "\t" << p->data.sum */ << endl;
			break;
		}
		p = p->next;
	}
	if (flag == 0) {
		cout << "不存在该学生信息，请重新操作" << endl;
		SeachStudent();
	}
	p = NULL;
	delete p;
}

//据学号精准查找生成返回值
int StudentsManager::AccurateSearchInt(string ID) {
	int flag = 0;
	Node* p = first->next;
	while (p->next != NULL)
	{
		if (p->data.ID == ID) {
			flag = 1;
			p = NULL;
			delete p;
			return 1;
		}
		p = p->next;
	}
	if (flag == 0) {
		p = NULL;
		delete p;
		return 0;
	}
}

//据学号查找各科成绩
void StudentsManager::FuzzySearchScores() {
	int flag = 0, flag1 = 0;
	while(flag==0){
		int num = 0;
		string ID = "";
		string courseID = "";
		NodeSc* ps = firstSc->next;
		cout << "请输入学号";
		cin >> ID;
		cout << endl;
		while (ps->next != NULL)
		{	
			Node* p = first->next;
			NodeCo* pc = firstCo->next;
			if (ps->data.ID ==ID) {
				while (p->next != NULL) {
					if (p->data.ID ==ID) {break;}
					p = p->next;
				}
				while (pc->next != NULL) {
					if (pc->data.courseID == ps->data.courseID) {break;}
					pc = pc->next;
				}
				flag = 1;
				num++;
				//判断是不是首次进入，首次打印头信息
				if (flag1 == 0) {
					flag1++;
					studentScoresTitle();
				}
				cout << ps->data.ID << "\t" << "\t" << p->data.name << "\t" << "\t" << ps->data.courseID << "\t" "\t" << pc->data.courseName << "\t" "\t" << ps->data.socres <<endl<<endl;
			}
			ps = ps->next;
			p = NULL;
			delete p;
			pc = NULL;
			delete pc;
		}

		if (flag == 0) {
			cout << endl;
			cout << "----------------------------------给与的信息不无法寻找或不存在该学生信息，请重新操作--------------------------------" << endl;
			cout << endl;
			FuzzySearchScores();
			continue;
		}
		else {
			cout << "输入0继续查找，输入1退出：";
			cin >> flag;
			while (flag != 0 && flag != 1) {
				cout << "输入错误重新输入：";
				cin >> flag;
			}
		}
	
		ps = NULL;
		delete ps;
	}
}

//据学号+课程号查找成绩
void StudentsManager::AccurateSearchScores() {
	int flag = 0,flag1 = 0, flag2=0;
	int num = 0;
	string ID = "";
	string courseID = "";
	NodeSc* ps = firstSc->next;
	Node* p = first->next;
	NodeCo* pc = firstCo->next;
	cout << "请输入学号：";
	cin >> ID;
	cout << endl;
	cout << "请输入课程号：";
	cin >> courseID;
	cout << endl;

	while (ps->next != NULL)
	{	
		if (ps->data.ID == ID) {
			while (p->next != NULL) {
				if (p->data.ID ==ID) { break; }
				p = p->next;
			}
			while (pc->next != NULL) {
				if (pc->data.courseID ==courseID) { break; }
				pc = pc->next;
			}
			flag = 1;
			//num++;
			//判断是不是首次进入，首次打印头信息
			if (flag1 == 0) {
				flag1++;
				studentScoresTitle();
			}
			cout << ps->data.ID << "\t" << "\t" << p->data.name << "\t" << "\t" << ps->data.courseID << "\t" "\t" << pc->data.courseName << "\t" "\t" << ps->data.socres << endl << endl;
			break;
		}
		ps = ps->next;
	}

	if (flag == 0) {
		cout << endl;
		cout << "----------------------------------给与的信息不无法寻找或不存在该学生信息，请重新操作--------------------------------" << endl;
		cout << endl;
		cout << endl;
		AccurateSearchScores();
	}else{
		cout << "输入1继续查找，输入0退出：";
		cin >> flag2;
		while (flag2 != 0 && flag2 != 1) {
			cout << "输入错误需要重新输入：";
			cin >> flag2;
		}
		if (flag2 == 1) {
			AccurateSearchScores();
		}

	}
	p = NULL;
	delete p;
	pc = NULL;
	delete pc;
	ps = NULL;
	delete ps;
}

//据课程号查找课程信息
void StudentsManager::SearchByCoID() {
	int flag = 0;
	while(flag==0){
		string courseID = "";
		cout << "请输入需要查找的课程号:";
		cin >> courseID;
		cout << endl;
		NodeCo* p = firstCo->next;
		while (p->next != NULL)
		{
			if (p->data.courseID == courseID) {
				flag = 1;
				courseTitle();
				cout << p->data.courseID << "\t" << "\t" << p->data.courseName << "\t" << p->data.credit << "\t"  "\t" "\t" << p->data.time << endl<< endl;
				break;
			}
			p = p->next;
		}
		p = NULL;
		delete p;
		if (flag == 0) {
			cout << "不存在该课程信息，请重新操作" << endl << endl;
			SeachStudent();
		}
		cout << "输入0继续查找，输入1退出：";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "输入错误请你重新输入：";
			cin >> flag;
		}
	}
	
}

//据课程号精准查找生成返回值
int StudentsManager::AccurateSearchCo(string CoID) {
	int flag = 0;
	NodeCo* p = firstCo->next;
	while (p->next != NULL)
	{
		if (p->data.courseID == CoID) {
			flag = 1;
			return 1;
		}
		p = p->next;
	}
	if (flag == 0) {
		return 0;
	}
	p = NULL;
	delete p;
}

//修改信息
void StudentsManager::modifyInformation() {
	int flag = 1;
	string choice = "";
	while (flag == 1)
	{
		cout << "请输入修改模式:" << endl << "【1】据学号修改学生信息" << endl << "【2】据课程号修改课程信息" << endl << "【3】据学号+课程号修改成绩信息" << endl << "【0】返回首页" << endl;
		cin >> choice;
		if (!AllisNum(choice)) {
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //退出程序
			flag = 0;
			break;
		case 1: //据学号修改学生信息
			modifyStudents();
			flag = 0;
			break;
		case 2: //据课程号修改课程信息
			modifyCourse();
			flag = 0;
			break;
		case 3: //据学号+课程号修改成绩信息
			modifyScores();
			flag = 0;
			break;
		default:
			//从新进入本循环
			cout << "输入操作错误，请重新输入" << endl;
			continue;
		}
	}
}

//修改学生信息
void StudentsManager::modifyStudents() {
	long long flag = 0;
	while(flag==0){
		string studentId = "";
		string s = "";
		cout << "请输入需要修改的学生学号:";
		cin >> studentId;
		cout << endl;
		Node* p = first->next;
		while (p->next != NULL)
		{
			if (p->data.ID == studentId) {
				flag = 1;
				int choice = 1;
				cout << "请输入要修改信息类型【1】姓名，【2】性别，【3】专业，【0】退出修改";
				cin >> choice;
				cout << endl;

				string sex = "";
				switch (choice) {
				case 0:
					break;
				case 1:
					cout << "请输入学生姓名：";
					cin >> p->data.name;
					cout << "修改成功！" << endl;
					continue;
				case 2:
					//性别正确性检验

					cout << "请输入学生性别“男/女/M/F”：";
					while (1)
					{
						cin >> sex;
						if (sex == "男" || sex == "女" || sex == "M" || sex == "F") {
							break;
						}
						cout << "输入错误，请重新输入：";
					}
					p->data.sex = sex;
					cout << "修改成功！" << endl;
					continue;
				case 3:
					while(1){
						cout << "请输入学生班级：";
						cin >> s;
						if (s.length() > 8) {
							cout << "班级输入错误，请重新输入：";
						}
						else { break; }
					}
					p->data.major=s;
					cout << "修改成功！" << endl;
					continue;
				default:
					cout << "请输入正确操作——";
					continue;
				}
				break;
			}
			p = p->next;
		}
		p = NULL;
		delete p;
		if (flag == 0) {
			cout << "学号格式错误/不存在该学生信息，请重新操作" << endl;
		}
		//更改本地文件
		InputFile("学生信息.txt");

	}		
	cout << "输入0继续修改，输入1退出：";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "输入错误请您重新输入：";
		cin >> flag;
	}
	if (flag == 0) {
		modifyScores();
	}
	
}

//修改成绩信息
void StudentsManager::modifyScores() {
	int flag = 0,flag1=0;
	string studentId = "1";
	while(flag==0){
		cout << "请输入需要修改的学生学号：";
		cin >> studentId;
		cout << endl;
		Node* p = first->next;
		NodeSc* ps = firstSc->next;
		//寻找学号格式是否合法以及是否有本学号学生
		if (studentId.length() != 12) {
			cout << "学号格式不正确，请重新输入，";
			continue;
		}
		while (p->next != NULL)
		{
			if (p->data.ID == studentId) {
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (flag == 0) {
			cout << "不存在该学号，请重新操作，" << endl;
			continue;
		}
		while (ps->next != NULL) {
			//接收课程号并进行成绩修改
			if (ps->data.ID == studentId) {
				string cI;
				cout << "请输入需要修改成绩的课程号:";
				cin >> cI;
				if (ps->data.courseID == cI) {
					flag1 = 1;
					int scores=0;
					cout << "当前成绩为："<<ps->data.socres<<endl<<"请输入您要修改的成绩:";
					cin >> scores;
					ps->data.socres = scores;
					cout << "修改成功"<<endl;
					break;
				}	
			}
			else {			//判断是否录入了该学生的课程信息
				cout << "未录入该学生课程信息，请重新输入，";
				continue;
			}
			if (flag1 == 0) {
				cout << "该学生无该门课程";
			}
		}
		p = NULL;
		delete p;
		ps = NULL;
		delete ps;
	}
	//更改本地文件
	InputFile("成绩信息.txt");

	cout << "输入1继续修改，输入0退出：";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "输入错误请您重新输入：";
		cin >> flag;
	}
	if (flag == 1) {
		modifyScores();
	}
}

//修改课程信息
void StudentsManager::modifyCourse() {
	int flag = 0;
	string cI = "";
	while (flag == 0) {
		cout << "请输入需要修改的课程号：";
		cin >> cI;
		cout << endl;
		NodeCo* p = firstCo->next;
		//寻找课程格式是否合法以及是否有本课程号
		if (cI.length() != 8) {
			cout << "课程格式不正确，请重新输入，";
			continue;
		}
		while (p->next != NULL)
		{//接收课程号并进行修改
			if (p->data.courseID == cI) {
				flag = 1;
				int num=0;
				cout << "请输入要修改信息类型【1】课程名，【2】学分，【3】学时，【0】退出修改:";
				cin >> num;
				switch (num) {
				case 0:
					break;
				case 1:
					cout << "请输入课程名：";
					cin >> p->data.courseName;
					cout << "修改成功！" << endl;
					continue;
				case 2:
					//性别正确性检验

					cout << "请输入学分：";
					cin >> p->data.credit;
					cout << "修改成功！" << endl;
					continue;
				case 3:
					cout << "请输入学时：";
					cin >> p->data.time;
					cout << "修改成功！" << endl;
					continue;
				default:
					cout << "请输入正确操作——";
					continue;
				}
				break;
			}
			p = p->next;
		}
		if (flag == 0) {
			cout << "不存在该课程号，请重新操作，" << endl;
			continue;
		}
		p = NULL;
		delete p;
	}
	//更改本地文件
	InputFile("课程信息.txt");

	cout << "输入1继续修改，输入0退出：";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "输入错误请您重新输入：";
		cin >> flag;
	}
	if (flag == 1) {
		modifyCourse();
	}
}

//统计某班级不及格名单
void StudentsManager::numberOfFailed() {
	static int flag = 0, flag1=0 ;
	while(flag==0){
		int num = 0;
		string classes = "";
		string ID = "";
		Node* p = first->next;
		cout << "请输入班级名：";
		cin >> classes;
		cout << endl;

		while (p->next != NULL)
		{
			if (p->data.major == classes) {
				flag1 = 1;
				NodeSc* ps = firstSc->next;
				while (ps->next != NULL) {
					if (ps->data.ID == p->data.ID) { 
						if (ps->data.socres < 60) { num++; break; }//实现多个科目只记一个人
						 }
					ps = ps->next;
				}
			}
			p = p->next;
		}

		if (flag1 == 0) {
			cout << endl;
			cout << "----------------------------------无此班级，请重新操作--------------------------------" << endl;
			cout << endl;
			cout << endl;
			continue;
		}
		cout << "班级" << p->data.major << "的不及格人数为 " << num << endl<<endl;
		cout << "输入0继续查找，输入1退出：";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "输入错误需要重新输入：";
			cin >> flag;
		}
		p = NULL;
		delete p;
	}	
}

//统计某门课程各成绩段人数及百分比。
void StudentsManager::persentOfScore() {
	int flag = 0;
	while (flag == 0) {
		static int ze;
		int num = 0, flag1 = 0;
		scoreLevel *sl = new scoreLevel;
		string course = "";
		string ID = "";
		NodeCo* p = firstCo->next;
		cout << "请输入课程名：";
		cin >> course;
		cout << endl;

		while (p->next != NULL)
		{	//查询课程
			if (p->data.courseName == course) {
				flag1 = 1;
				NodeSc* ps = firstSc->next;
				while (ps->next != NULL) {
					if (ps->data.courseID == p->data.courseID) {	//找到课程在成绩表的相关信息
						divideLevelP(ps->data.socres, sl);			//依据分数等级增加相关数目
					}
					ps = ps->next;
				}
			}
			p = p->next;
		}

		if (flag1 == 0) {
			cout << endl;
			cout << "----------------------------------无此课程，请重新操作--------------------------------" << endl;
			cout << endl;
			cout << endl;
			persentOfScore();
			break;
		}
		//cout << "3: " << sl->A << "!E:" << sl->E <<sl->A+sl->E<< endl;
		//防止除0
		if ((sl->A + sl->B + sl->C + sl->D + sl->E) == 0) { ze = 1; }
		else { ze = 0; }
		cout <<" 课程名: "<<course<<endl;
		cout << "优秀占比: " << sl->A *100/(sl->A+ sl->B+ sl->C+ sl->D+ sl->E + ze) <<"%" << endl;
		cout << "良好占比: " << sl->B *100/ (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "中等占比: " << sl->C * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "及格占比: " << sl->D * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "不及格占比: " << sl->E * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "输入0继续查找，输入1退出：";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "输入错误需要重新输入：";
			cin >> flag;
		}
		p = NULL;
		delete p;

	}
}


//将分级成绩人数加入成绩分级类
void  StudentsManager::divideLevelP(double scores,scoreLevel * scoreLevel) {
	if (scores < 60) {
		scoreLevel->E++;
	}
	else if (scores < 70) {
		scoreLevel->D++;
	}
	else if (scores < 80) {
		scoreLevel->C++;
	}
	else if (scores < 90) {
		scoreLevel->B++;
	}
	else if (scores <= 100) {
		scoreLevel->A++;
	}
}
//获得成绩分级
string  StudentsManager::divideLevel(double scores) {
	if (scores <60) {
		return "不及格";
	}
	else if (scores <70) {
		return "及格";
	}
	else if (scores <80) {
		return "中等";
	}
	else if (scores <90) {
		return "良好";
	}
	else if (scores <=100) {
		return "优秀";
	}
}

//退出系统功能
void StudentsManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


// 判断是否为数字构成
bool AllisNum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
// 判断是否存在汉字
bool isChinese(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char tmp = str[i];
		if (tmp >0x80)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

////释放链表指针
//void R(Node* a) {
//	delete a;
//	a = NULL;
//}
//void R1(NodeCo* a) {
//	delete a;
//	a = NULL;
//}
//void R2(NodeSc* a) {
//	delete a;
//	a = NULL;
//}
//
//
