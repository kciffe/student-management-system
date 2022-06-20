#pragma once
#include<iostream>
#include<string>

using namespace std;
#include <vector>


//ѧ����
struct student
{
	string name;
	string ID;
	string sex;
	int age;
	string major;
	
};

//ѧ���ڵ���
class Node {
public:
	student data;
	Node* next;
};

//�ɼ���
struct score
{
	string ID;
	string courseID;
	double socres;
};

//�ɼ��ڵ���
class NodeSc {
public:
	score data;
	NodeSc* next;
};

//�γ���
struct course {
	string courseID;
	string courseName;
	float credit;
	int time;
};

//�γ̽ڵ���
class NodeCo {
public:
	course data;
	NodeCo* next;
};

//�ɼ��ּ���
struct scoreLevel {
	int A = 0, B = 0, C = 0, D = 0, E = 0;
};


//ѧ������ϵͳ
class StudentsManager
{
public:

	//�����ļ�
	void InputFile(string ss);

	//����ļ�
	void OutputFile(string ss);

	//���캯��
	StudentsManager();

	//չʾ�˵�
	void ShowMenu();


	//��ʾ����
	void display();

	//¼��ѧ����Ϣ
	void inputStudent();

	//¼��γ���Ϣ
	void inputCourse();

	//¼��ɼ���Ϣ
	void inputScore();

	//ɾ����Ϣ
	void DeleteStudent();

	//��ѧ��ɾ��ѧ��
	void AccurateDelete();

	//�ݿγ̺�ɾ���γ�
	void deleteCourse();

	//������Ϣ
	void SeachStudent();
	//��׼����
	void AccurateSearch();

	//��ѧ�ž�׼�������ɷ���ֵ
	int AccurateSearchInt(string ID);

	//��ѧ�Ų��Ҹ��Ƴɼ�
	void FuzzySearchScores();

	//��ѧ��+�γ̺Ų��ҳɼ�
	void AccurateSearchScores();

	//�ݿγ̺Ų�ѯ�γ���Ϣ
	void SearchByCoID();

	//�ݿγ̺ž�ȷ�������ɷ���ֵ
	int AccurateSearchCo(string CoID);

	//�޸���Ϣ
	void modifyInformation();

	//����ѧ����Ϣ
	void modifyStudents();

	//���ĳɼ���Ϣ
	void modifyScores();

	//�޸Ŀγ���Ϣ
	void modifyCourse();

	//ͳ��ĳ�༶����������
	void numberOfFailed();

	//ͳ��ĳ�ſγ̸��ɼ����������ٷֱȡ�
	void persentOfScore();


	//���ּ��ɼ���������ɼ��ּ���
	void divideLevelP(double scores, scoreLevel *scoreLevel);

	//��óɼ��ּ�
	string divideLevel(double scores);

	//�˳�ϵͳ
	void exitSystem();
	

	//��������
	~StudentsManager();

	//ѧ����Ϣͷ
	void studentstitle();

	//������Ŀ��Ϣͷ
	void studentScoresTitle();

	//�γ���Ϣͷ
	void courseTitle();



private:
	Node* first;
	NodeSc* firstSc;
	NodeCo* firstCo;
	int Max = 0;
	int Max1 = 0;
	int Max2 = 0;
	
	
};