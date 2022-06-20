#include "StudentsManager.h"
#include<fstream>
#include<string>

bool AllisNum(string str);
bool isChinese(string str);

//չʾ�˵�����
void StudentsManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ѧ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ѧ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾѧ����Ϣ  *************" << endl;
	cout << "*************  3.��������ɾ����Ϣ  *********" << endl;
	cout << "*************  4.���������޸���Ϣ  *********" << endl;
	cout << "*************  5.����������ѯ��Ϣ  *********" << endl;
	cout << "*************  6.ͳ�ư༶����������  *******" << endl;
	cout << "*************  7.ͳ�ƿγ̳ɼ��ֲ���  *******" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//���캯��
StudentsManager::StudentsManager()
{
	OutputFile("ѧ����Ϣ.txt");
	OutputFile("�ɼ���Ϣ.txt");
	OutputFile("�γ���Ϣ.txt");
}

//����ļ�
void StudentsManager::OutputFile(string ss) {
	Max = 0;

	//��ȡ�ļ�����
	ifstream ifs;
	ifs.open(ss, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ��򿪴���" << endl;
	}


	if (ss == "ѧ����Ϣ.txt"){
		//��������ѧ���ļ�
		first = new Node;		//����ͷָ��
		first->next = NULL;
		Node* s = NULL;
		Node* r = first;
		int flag = 1;                         //���жϱ�׼���Ա��˳�ѭ��

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
	else if (ss == "�ɼ���Ϣ.txt") {
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
	else if(ss == "�γ���Ϣ.txt") {
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
	else {					//����δ֪����
		printf("error of ss�������");
	}

	//�ر��ļ�
	ifs.close();
}


//�����ļ�
void StudentsManager::InputFile(string ss) {
	ofstream ofs;

	ofs.open(ss, ios::out);
	if (ss == "ѧ����Ϣ.txt") {
		Node* p = first->next;
		while (p->next != NULL)
		{
			ofs << p->data.ID << " " << p->data.name << " " << p->data.sex << " " << p->data.major << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else if (ss == "�ɼ���Ϣ.txt") {
		NodeSc* p = firstSc->next;
		while (p->next!=NULL)
		{
			ofs << p->data.ID << " " << p->data.courseID << " " << p->data.socres << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else if (ss == "�γ���Ϣ.txt") {
		NodeCo* p = firstCo->next;
		while (p->next != NULL)
		{
			ofs << p->data.courseID << " " << p->data.courseName << " " << p->data.credit << " " << p->data.time<< endl;
			p = p->next;
		}
		p = NULL;
		delete p;
	}
	else { printf("����ļ����б���Ϣ����"); };

	ofs.close();
}


StudentsManager::~StudentsManager(){}

//��ʾѧ����Ϣͷ
void StudentsManager::studentstitle() {			//needModify!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "ѧ��" << "\t" << "\t" << "\t" << "����" << "\t" << "\t" << "�Ա�"<< "\t" << "\t" << "רҵ" /* << "\t" << "\t" << "\t" << "����" << "\t" << "\t" << "��Ӣ" << "\t" "\t" << "����" << "\t""\t" << "�ܷ�" */ << endl;
}

//��ʾ��Ŀ��Ϣͷ
void StudentsManager::studentScoresTitle() {			
	cout << "ѧ��" << "\t" << "\t" << "\t" << "����" << "\t" << "\t" << "��ĿID" << "\t" << "\t" << "\t" << "��Ŀ" << "\t" << "\t" << "\t" << "����" /* << "\t" << "\t" << "\t" << "����" << "\t" << "\t" << "��Ӣ" << "\t" "\t" << "����" << "\t""\t" << "�ܷ�" */ << endl;
}

//��ʾ�γ���Ϣͷ
void StudentsManager::courseTitle(){
	cout << "�γ̺�" << "\t" << "\t" << "\t" << "�γ���" << "\t" << "\t" << "ѧ��" << "\t" << "\t" << "\t" << "ѧʱ" << endl;
}
//��ʾѧ����Ϣ
void StudentsManager::display() {
	OutputFile("ѧ����Ϣ.txt");
	
	//�����ʾѧ����Ϣ
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

//���ѧ��
void StudentsManager::inputStudent() {
	int flag = 1;//�Ƿ�������ѧ����Ϣ������
	
	while (flag==1)
	{
		int flag1 = 0;
		int flag2 = 0;
		Node* s = NULL;
		s = new Node;
		s->next = first->next;
		first->next = s;
		//ѧ����ȷ�ԣ��ظ��Լ���
		string num = "";
		cout << "������12λ��Чѧ��ѧ�ţ�";
		while (flag1 == 0)
		{
			flag1 = 1;
			cin >> num;
			if (num.length() != 12 ||  stoi(num.substr(0, 4)) > 2021 || !AllisNum(num)) {
				flag1 = 0;
				cout << "����������������룺";
				continue;
			}

			Node* z = first->next;
			while (z->next != NULL)
			{
				if (num == z->data.ID) {
					flag1 = 0;
					cout << "��ѧ���Ѵ��ڣ����������룺";
					break;
				}
				z = z->next;
			}
		}
		s->data.ID = num;

		int flag11 = 0;
		while(flag11==0){
			cout << "������ѧ��������";
			cin >> s->data.name;
			if (!isChinese(s->data.name) && s->data.name.length() > 20 || s->data.name.length() > 8) {
				cout << "��������������������룺";
			}
			else { flag11 = 1; }
		}
		
		//�Ա���ȷ�Լ���
		string sex = "";
		cout << "������ѧ���Ա���/Ů/M/F����";
		while (flag2 == 0)
		{

			cin >> sex;
			if (sex == "��" || sex == "Ů" || sex=="M" || sex=="F") {
				break;
			}
			cout << "����������������룺";
		}
		s->data.sex = sex;

		string co = "";
		while (1) {
			cout << "������ѧ���༶��";
			cin >> co;
			if (co.length() > 8) {
				cout << "�༶����������������룺";
			}
			else { break; }
		}
		s->data.major = co;
		s = NULL;
		delete s;
		Max++;

		ofstream ofs;

		ofs.open("ѧ����Ϣ.txt", ios::out);//����ȷ����������뵽�ļ���

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
		
		cout << "����1�������ѧ��������0�򷵻���ҳ";
		cin >> flag;
		while (flag !=0 && flag!=1)
		{
			
			if (flag != 0  &&  flag != 1) {
				cout << "��������ȷ������������1�������ѧ��������0���˳�������ҳ";
				cin >> flag;
			}
		}
	}
	
}
//��ӿγ�
void StudentsManager::inputCourse() {
	int flag = 1;//�Ƿ���������Ϣ������
	int flag1 = 0;
	while (flag == 1)
	{
		Max1++;
		NodeCo* s = NULL;
		s = new NodeCo;
		s->next = firstCo->next;
		firstCo->next = s;
		//�γ̺���ȷ�ԣ��ظ��Լ���
		string num = "";
		cout << "������8λ��Ч�γ̺ţ�";
		while (flag1 == 0)
		{
			flag1 = 1;
			cin >> num;
			if (num.length()!=8) {
				flag1 = 0;
				cout << "����������������룺";
				continue;
			}

			NodeCo* z = firstCo->next;
			while (z->next != NULL)
			{
				if (num == z->data.courseID) {
					flag1 = 0;
					cout << "�ÿγ̺��Ѵ��ڣ����������룺";
					break;
				}
				z = z->next;
			}
			z = NULL;
			delete z;
		}
		s->data.courseID = num;

		cout << "������γ�����";
		cin >> s->data.courseName;
		cout << "������ѧ��";
		cin >> s->data.credit;
		cout << "������ѧʱ";
		cin >> s->data.time;
		s = NULL;
		delete s;
		ofstream ofs;

		ofs.open("�γ���Ϣ.txt", ios::out);//����ȷ����������뵽�ļ���

		NodeCo* p = firstCo->next;
		for (int j = 0; j < Max1; j++)
		{
			ofs << p->data.courseID << " " << p->data.courseName << " " << p->data.credit << " " << p->data.time << endl;
			p = p->next;
		}
		p = NULL;
		delete p;
		ofs.close();

		cout << "����1������ӿγ̣�����0�򷵻���ҳ";
		cin >> flag;
		while (flag != 0 && flag != 1)
		{

			if (flag != 0 && flag != 1) {
				cout << "��������ȷ������������1������ӿγ̣�����0���˳�������ҳ";
				cin >> flag;
			}
		}

	}

}
//��ӳɼ� 
void StudentsManager::inputScore() {
	int flag = 1;//�Ƿ���������Ϣ������

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
		//ѧ����ȷ�ԣ��ظ��Լ���
		string num="", num1 = "";
		cout << "������12λ��Чѧ��ѧ�ţ�";
		while (flag1 == 0)
		{
			flag1 = 1;
			if(flag2==0){
				cin >> num;
				if (num.length() != 12 || stoi(num.substr(0, 4)) > 2021 || !AllisNum(num)) {
					flag1 = 0;
					cout << "ѧ�Ÿ�ʽ��������������,";
					continue;		
				}
				else if (!AccurateSearchInt(num)) {
					flag1 = 0;
					cout << "ѧ�Ų����ڣ�����������,";
					continue;
				}
			}
			flag2 = 1;
			//���γ̺�
			cout << "������γ̺�:";
			cin >> num1;
			if (num1.length() != 8) {
				flag1 = 0;
				cout << "�γ̺Ÿ�ʽ��������������,";
				continue;
			}
			else if (!AccurateSearchCo(num1)) {
				flag1 = 0;
				cout << "�γ̺Ų����ڣ�����������,";
				continue;
			}

			NodeSc* z = firstSc->next;
			while (z->next != NULL)
			{
				if (num == z->data.ID && num1==z->data.courseID) {
					flag3 = 1;
					cout << "��ѧ���µĿγ̳ɼ��Ѵ���"<<endl;
					break;
				}
				z = z->next;
			}
			z = NULL;
			delete z;
		}
		//�ɼ�������ʱ��¼��
		if (flag3 == 0) {
			s->data.ID = num;
			s->data.courseID = num1;

			//������ȷ�Լ���
			cout << "���������:";
			int num2 = 0;
			while (1)
			{

				cin >> num2;
				if (num2 >= 0 && num2 <= 100) {
					break;
				}
				else {
					cout << "����������������������";
				}
			}
			s->data.socres = num2;

			ofstream ofs;

			ofs.open("�ɼ���Ϣ.txt", ios::out);//����ȷ����������뵽�ļ���

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
		
		cout << "����1������ӳɼ�������0�򷵻���ҳ:";
		cin >> flag;
		while (flag != 0 && flag != 1)
		{

			if (flag != 0 && flag != 1) {
				cout << "��������ȷ������������1������ӳɼ�������0���˳�������ҳ";
				cin >> flag;
			}
		}
		s = NULL;
		delete s;
	}

}
//ɾ������
void StudentsManager::DeleteStudent() {

	int flag = 1;
	string choice = "123";
	while (flag == 1)
	{
		cout << "���������ģʽ"<<endl<<"��1����ѧ��ɾ��ѧ��"<<endl<<"��2���ݿγ̺�ɾ���γ�"<<endl<<"��0��������ҳ:";
		cin >> choice;
		if (choice!="1"&& choice!="2"&& choice!="0") {
			cout << "���������������������" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //�˳�����
			flag = 0;
			break;
		case 1: //��ѧ��ɾ��ѧ��
			AccurateDelete();
			flag = 0;
			break;
		case 2: //�ݿγ̺�ɾ���γ�
			deleteCourse();
			flag = 0;
			break;
		default:
			//���½��뱾ѭ��
			cout << "���������������������" << endl;
			continue;
		}
	}
}

//��ѧ��ɾ��ѧ��
void StudentsManager::AccurateDelete() {
	int flag = 0;
	string studentId = "1";
	while(flag==0){
		cout << "��������Ҫɾ����ѧ��ѧ��";
		cin >> studentId;
		cout << endl;
		Node* p = first->next, * q = first;
		NodeSc* ps = firstSc->next, * qs = firstSc;
		//ɾ��ѧ���ļ�����Ϣ
		while (p->next != NULL)
		{
			if (p->data.ID == studentId) {
				flag = 1;
				q->next = p->next;
				delete p;
				p = NULL;//����Ұָ��
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			q = q->next;
			p = p->next;
		}
		if (flag == 0) {
			cout << "�����ڸ�ѧ����Ϣ�������²���" << endl;
			continue;
		}
		//���ı����ļ�
		InputFile("ѧ����Ϣ.txt");
		//ɾ���ɼ��ļ�����Ϣ
		while (ps->next != NULL)
		{
			if (ps->data.ID == studentId) {
				qs->next = ps->next;
				delete ps;
				ps = NULL;//����Ұָ��
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			qs = qs->next;
			ps = ps->next;
		}
		InputFile("�ɼ���Ϣ.txt");
		p = NULL;
		delete p;
		ps = NULL;
		delete ps;
		qs = NULL;
		delete qs;
	}
	cout << "����1����ɾ��������0�˳���";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "��������������룺";
		cin >> flag;
	}
	if (flag == 1) {
		AccurateDelete();
	}
}

//�ݿγ̺�ɾ���γ�
void StudentsManager::deleteCourse() {
	int flag = 0;
	string cI = "1";
	while (flag == 0) {
		cout <<endl<< "��������Ҫɾ���Ŀγ̺�";
		cin >> cI;
		cout << endl;
		NodeCo* pc = firstCo->next, * qc = firstCo;
		NodeSc* ps = firstSc->next, * qs = firstSc;
		//ɾ��ѧ���ļ�����Ϣ
		while (pc->next != NULL)
		{
			if (pc->data.courseID == cI) {
				flag = 1;
				qc->next = pc->next;
				delete pc;
				pc = NULL;//����Ұָ��
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			qc = qc->next;
			pc = pc->next;
		}
		if (flag == 0) {
			cout << "�����ڸÿγ���Ϣ�������²���" << endl;
			continue;
		}
		//���ı����ļ�
		InputFile("�γ���Ϣ.txt");
		//ɾ���ɼ��ļ�����Ϣ
		while (ps->next != NULL)
		{
			if (ps->data.courseID == cI) {
				qs->next = ps->next;
				delete ps;
				ps = NULL;//����Ұָ��
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			qs = qs->next;
			ps = ps->next;
		}
		InputFile("�ɼ���Ϣ.txt");
		pc = NULL;
		delete pc;
		ps = NULL;
		delete ps;
		qc = NULL;
		delete qc;
		qs = NULL;
		delete qs;
	}
	cout << "����1�������ң�����0�˳���";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "��������������룺";
		cin >> flag;
	}
	if (flag == 1) {
		deleteCourse();
	}
}


//������Ϣ
void StudentsManager::SeachStudent() {
	int flag = 1;
	string choice = "123";
	//cout << AllisNum(choice);
	while (flag == 1)
	{
		cout << "���������ģʽ:"<<endl<<"��1����ѧ�Ų���ѧ����Ϣ"<<endl<<"��2����ѧ�Ų�ѯ��ѧ�����Ƴɼ�"<<endl<<"��3����ѧ�� + �γ̺Ų�ѯ��Ŀ�ɼ�"<<endl<<"��4���ݿγ̺Ų�ѯ�γ���Ϣ"<<endl<<"��0��������ҳ"<<endl;
		cin >> choice;
		if (!AllisNum(choice)) {
			cout << "���������������������" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //�˳�����
			flag = 0;
			break;
		case 1: //��ѧ�Ų���ѧ����Ϣ
			AccurateSearch();
			flag = 0;
			break;
		case 2: //��ѧ�Ų�ѯ��ѧ�����Ƴɼ�
			FuzzySearchScores();
			flag = 0;
			break;
		case 3: //��ѧ��+�γ̺Ų�ѯ��Ŀ�ɼ�
			AccurateSearchScores();
			flag = 0;
			break;
		case 4://�ݿγ̺Ų�ѯ�γ���Ϣ
			SearchByCoID();
			flag = 0;
			break;
		default:
			//���½��뱾ѭ��
			cout << "���������������������" << endl;
			continue;
		}
	}
}

//��ѧ�ž�׼����ѧ����Ϣ
void StudentsManager::AccurateSearch() {
	int flag = 0;
	string studentId = "1";
	cout << "��������Ҫ���ҵ�ѧ��ѧ��";
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
		cout << "�����ڸ�ѧ����Ϣ�������²���" << endl;
		SeachStudent();
	}
	p = NULL;
	delete p;
}

//��ѧ�ž�׼�������ɷ���ֵ
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

//��ѧ�Ų��Ҹ��Ƴɼ�
void StudentsManager::FuzzySearchScores() {
	int flag = 0, flag1 = 0;
	while(flag==0){
		int num = 0;
		string ID = "";
		string courseID = "";
		NodeSc* ps = firstSc->next;
		cout << "������ѧ��";
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
				//�ж��ǲ����״ν��룬�״δ�ӡͷ��Ϣ
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
			cout << "----------------------------------�������Ϣ���޷�Ѱ�һ򲻴��ڸ�ѧ����Ϣ�������²���--------------------------------" << endl;
			cout << endl;
			FuzzySearchScores();
			continue;
		}
		else {
			cout << "����0�������ң�����1�˳���";
			cin >> flag;
			while (flag != 0 && flag != 1) {
				cout << "��������������룺";
				cin >> flag;
			}
		}
	
		ps = NULL;
		delete ps;
	}
}

//��ѧ��+�γ̺Ų��ҳɼ�
void StudentsManager::AccurateSearchScores() {
	int flag = 0,flag1 = 0, flag2=0;
	int num = 0;
	string ID = "";
	string courseID = "";
	NodeSc* ps = firstSc->next;
	Node* p = first->next;
	NodeCo* pc = firstCo->next;
	cout << "������ѧ�ţ�";
	cin >> ID;
	cout << endl;
	cout << "������γ̺ţ�";
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
			//�ж��ǲ����״ν��룬�״δ�ӡͷ��Ϣ
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
		cout << "----------------------------------�������Ϣ���޷�Ѱ�һ򲻴��ڸ�ѧ����Ϣ�������²���--------------------------------" << endl;
		cout << endl;
		cout << endl;
		AccurateSearchScores();
	}else{
		cout << "����1�������ң�����0�˳���";
		cin >> flag2;
		while (flag2 != 0 && flag2 != 1) {
			cout << "���������Ҫ�������룺";
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

//�ݿγ̺Ų��ҿγ���Ϣ
void StudentsManager::SearchByCoID() {
	int flag = 0;
	while(flag==0){
		string courseID = "";
		cout << "��������Ҫ���ҵĿγ̺�:";
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
			cout << "�����ڸÿγ���Ϣ�������²���" << endl << endl;
			SeachStudent();
		}
		cout << "����0�������ң�����1�˳���";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "������������������룺";
			cin >> flag;
		}
	}
	
}

//�ݿγ̺ž�׼�������ɷ���ֵ
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

//�޸���Ϣ
void StudentsManager::modifyInformation() {
	int flag = 1;
	string choice = "";
	while (flag == 1)
	{
		cout << "�������޸�ģʽ:" << endl << "��1����ѧ���޸�ѧ����Ϣ" << endl << "��2���ݿγ̺��޸Ŀγ���Ϣ" << endl << "��3����ѧ��+�γ̺��޸ĳɼ���Ϣ" << endl << "��0��������ҳ" << endl;
		cin >> choice;
		if (!AllisNum(choice)) {
			cout << "���������������������" << endl;
			continue;
		}

		switch (stoll(choice))
		{
		case 0: //�˳�����
			flag = 0;
			break;
		case 1: //��ѧ���޸�ѧ����Ϣ
			modifyStudents();
			flag = 0;
			break;
		case 2: //�ݿγ̺��޸Ŀγ���Ϣ
			modifyCourse();
			flag = 0;
			break;
		case 3: //��ѧ��+�γ̺��޸ĳɼ���Ϣ
			modifyScores();
			flag = 0;
			break;
		default:
			//���½��뱾ѭ��
			cout << "���������������������" << endl;
			continue;
		}
	}
}

//�޸�ѧ����Ϣ
void StudentsManager::modifyStudents() {
	long long flag = 0;
	while(flag==0){
		string studentId = "";
		string s = "";
		cout << "��������Ҫ�޸ĵ�ѧ��ѧ��:";
		cin >> studentId;
		cout << endl;
		Node* p = first->next;
		while (p->next != NULL)
		{
			if (p->data.ID == studentId) {
				flag = 1;
				int choice = 1;
				cout << "������Ҫ�޸���Ϣ���͡�1����������2���Ա𣬡�3��רҵ����0���˳��޸�";
				cin >> choice;
				cout << endl;

				string sex = "";
				switch (choice) {
				case 0:
					break;
				case 1:
					cout << "������ѧ��������";
					cin >> p->data.name;
					cout << "�޸ĳɹ���" << endl;
					continue;
				case 2:
					//�Ա���ȷ�Լ���

					cout << "������ѧ���Ա���/Ů/M/F����";
					while (1)
					{
						cin >> sex;
						if (sex == "��" || sex == "Ů" || sex == "M" || sex == "F") {
							break;
						}
						cout << "����������������룺";
					}
					p->data.sex = sex;
					cout << "�޸ĳɹ���" << endl;
					continue;
				case 3:
					while(1){
						cout << "������ѧ���༶��";
						cin >> s;
						if (s.length() > 8) {
							cout << "�༶����������������룺";
						}
						else { break; }
					}
					p->data.major=s;
					cout << "�޸ĳɹ���" << endl;
					continue;
				default:
					cout << "��������ȷ��������";
					continue;
				}
				break;
			}
			p = p->next;
		}
		p = NULL;
		delete p;
		if (flag == 0) {
			cout << "ѧ�Ÿ�ʽ����/�����ڸ�ѧ����Ϣ�������²���" << endl;
		}
		//���ı����ļ�
		InputFile("ѧ����Ϣ.txt");

	}		
	cout << "����0�����޸ģ�����1�˳���";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "������������������룺";
		cin >> flag;
	}
	if (flag == 0) {
		modifyScores();
	}
	
}

//�޸ĳɼ���Ϣ
void StudentsManager::modifyScores() {
	int flag = 0,flag1=0;
	string studentId = "1";
	while(flag==0){
		cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
		cin >> studentId;
		cout << endl;
		Node* p = first->next;
		NodeSc* ps = firstSc->next;
		//Ѱ��ѧ�Ÿ�ʽ�Ƿ�Ϸ��Լ��Ƿ��б�ѧ��ѧ��
		if (studentId.length() != 12) {
			cout << "ѧ�Ÿ�ʽ����ȷ�����������룬";
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
			cout << "�����ڸ�ѧ�ţ������²�����" << endl;
			continue;
		}
		while (ps->next != NULL) {
			//���տγ̺Ų����гɼ��޸�
			if (ps->data.ID == studentId) {
				string cI;
				cout << "��������Ҫ�޸ĳɼ��Ŀγ̺�:";
				cin >> cI;
				if (ps->data.courseID == cI) {
					flag1 = 1;
					int scores=0;
					cout << "��ǰ�ɼ�Ϊ��"<<ps->data.socres<<endl<<"��������Ҫ�޸ĵĳɼ�:";
					cin >> scores;
					ps->data.socres = scores;
					cout << "�޸ĳɹ�"<<endl;
					break;
				}	
			}
			else {			//�ж��Ƿ�¼���˸�ѧ���Ŀγ���Ϣ
				cout << "δ¼���ѧ���γ���Ϣ�����������룬";
				continue;
			}
			if (flag1 == 0) {
				cout << "��ѧ���޸��ſγ�";
			}
		}
		p = NULL;
		delete p;
		ps = NULL;
		delete ps;
	}
	//���ı����ļ�
	InputFile("�ɼ���Ϣ.txt");

	cout << "����1�����޸ģ�����0�˳���";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "������������������룺";
		cin >> flag;
	}
	if (flag == 1) {
		modifyScores();
	}
}

//�޸Ŀγ���Ϣ
void StudentsManager::modifyCourse() {
	int flag = 0;
	string cI = "";
	while (flag == 0) {
		cout << "��������Ҫ�޸ĵĿγ̺ţ�";
		cin >> cI;
		cout << endl;
		NodeCo* p = firstCo->next;
		//Ѱ�ҿγ̸�ʽ�Ƿ�Ϸ��Լ��Ƿ��б��γ̺�
		if (cI.length() != 8) {
			cout << "�γ̸�ʽ����ȷ�����������룬";
			continue;
		}
		while (p->next != NULL)
		{//���տγ̺Ų������޸�
			if (p->data.courseID == cI) {
				flag = 1;
				int num=0;
				cout << "������Ҫ�޸���Ϣ���͡�1���γ�������2��ѧ�֣���3��ѧʱ����0���˳��޸�:";
				cin >> num;
				switch (num) {
				case 0:
					break;
				case 1:
					cout << "������γ�����";
					cin >> p->data.courseName;
					cout << "�޸ĳɹ���" << endl;
					continue;
				case 2:
					//�Ա���ȷ�Լ���

					cout << "������ѧ�֣�";
					cin >> p->data.credit;
					cout << "�޸ĳɹ���" << endl;
					continue;
				case 3:
					cout << "������ѧʱ��";
					cin >> p->data.time;
					cout << "�޸ĳɹ���" << endl;
					continue;
				default:
					cout << "��������ȷ��������";
					continue;
				}
				break;
			}
			p = p->next;
		}
		if (flag == 0) {
			cout << "�����ڸÿγ̺ţ������²�����" << endl;
			continue;
		}
		p = NULL;
		delete p;
	}
	//���ı����ļ�
	InputFile("�γ���Ϣ.txt");

	cout << "����1�����޸ģ�����0�˳���";
	cin >> flag;
	while (flag != 0 && flag != 1) {
		cout << "������������������룺";
		cin >> flag;
	}
	if (flag == 1) {
		modifyCourse();
	}
}

//ͳ��ĳ�༶����������
void StudentsManager::numberOfFailed() {
	static int flag = 0, flag1=0 ;
	while(flag==0){
		int num = 0;
		string classes = "";
		string ID = "";
		Node* p = first->next;
		cout << "������༶����";
		cin >> classes;
		cout << endl;

		while (p->next != NULL)
		{
			if (p->data.major == classes) {
				flag1 = 1;
				NodeSc* ps = firstSc->next;
				while (ps->next != NULL) {
					if (ps->data.ID == p->data.ID) { 
						if (ps->data.socres < 60) { num++; break; }//ʵ�ֶ����Ŀֻ��һ����
						 }
					ps = ps->next;
				}
			}
			p = p->next;
		}

		if (flag1 == 0) {
			cout << endl;
			cout << "----------------------------------�޴˰༶�������²���--------------------------------" << endl;
			cout << endl;
			cout << endl;
			continue;
		}
		cout << "�༶" << p->data.major << "�Ĳ���������Ϊ " << num << endl<<endl;
		cout << "����0�������ң�����1�˳���";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "���������Ҫ�������룺";
			cin >> flag;
		}
		p = NULL;
		delete p;
	}	
}

//ͳ��ĳ�ſγ̸��ɼ����������ٷֱȡ�
void StudentsManager::persentOfScore() {
	int flag = 0;
	while (flag == 0) {
		static int ze;
		int num = 0, flag1 = 0;
		scoreLevel *sl = new scoreLevel;
		string course = "";
		string ID = "";
		NodeCo* p = firstCo->next;
		cout << "������γ�����";
		cin >> course;
		cout << endl;

		while (p->next != NULL)
		{	//��ѯ�γ�
			if (p->data.courseName == course) {
				flag1 = 1;
				NodeSc* ps = firstSc->next;
				while (ps->next != NULL) {
					if (ps->data.courseID == p->data.courseID) {	//�ҵ��γ��ڳɼ���������Ϣ
						divideLevelP(ps->data.socres, sl);			//���ݷ����ȼ����������Ŀ
					}
					ps = ps->next;
				}
			}
			p = p->next;
		}

		if (flag1 == 0) {
			cout << endl;
			cout << "----------------------------------�޴˿γ̣������²���--------------------------------" << endl;
			cout << endl;
			cout << endl;
			persentOfScore();
			break;
		}
		//cout << "3: " << sl->A << "!E:" << sl->E <<sl->A+sl->E<< endl;
		//��ֹ��0
		if ((sl->A + sl->B + sl->C + sl->D + sl->E) == 0) { ze = 1; }
		else { ze = 0; }
		cout <<" �γ���: "<<course<<endl;
		cout << "����ռ��: " << sl->A *100/(sl->A+ sl->B+ sl->C+ sl->D+ sl->E + ze) <<"%" << endl;
		cout << "����ռ��: " << sl->B *100/ (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "�е�ռ��: " << sl->C * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "����ռ��: " << sl->D * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "������ռ��: " << sl->E * 100 / (sl->A + sl->B + sl->C + sl->D + sl->E + ze) << "%" << endl;
		cout << "����0�������ң�����1�˳���";
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "���������Ҫ�������룺";
			cin >> flag;
		}
		p = NULL;
		delete p;

	}
}


//���ּ��ɼ���������ɼ��ּ���
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
//��óɼ��ּ�
string  StudentsManager::divideLevel(double scores) {
	if (scores <60) {
		return "������";
	}
	else if (scores <70) {
		return "����";
	}
	else if (scores <80) {
		return "�е�";
	}
	else if (scores <90) {
		return "����";
	}
	else if (scores <=100) {
		return "����";
	}
}

//�˳�ϵͳ����
void StudentsManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


// �ж��Ƿ�Ϊ���ֹ���
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
// �ж��Ƿ���ں���
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

////�ͷ�����ָ��
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
