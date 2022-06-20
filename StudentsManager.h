#pragma once
#include<iostream>
#include<string>

using namespace std;
#include <vector>


//学生类
struct student
{
	string name;
	string ID;
	string sex;
	int age;
	string major;
	
};

//学生节点类
class Node {
public:
	student data;
	Node* next;
};

//成绩类
struct score
{
	string ID;
	string courseID;
	double socres;
};

//成绩节点类
class NodeSc {
public:
	score data;
	NodeSc* next;
};

//课程类
struct course {
	string courseID;
	string courseName;
	float credit;
	int time;
};

//课程节点类
class NodeCo {
public:
	course data;
	NodeCo* next;
};

//成绩分级类
struct scoreLevel {
	int A = 0, B = 0, C = 0, D = 0, E = 0;
};


//学籍管理系统
class StudentsManager
{
public:

	//输入文件
	void InputFile(string ss);

	//输出文件
	void OutputFile(string ss);

	//构造函数
	StudentsManager();

	//展示菜单
	void ShowMenu();


	//显示数据
	void display();

	//录入学生信息
	void inputStudent();

	//录入课程信息
	void inputCourse();

	//录入成绩信息
	void inputScore();

	//删除信息
	void DeleteStudent();

	//据学号删除学生
	void AccurateDelete();

	//据课程号删除课程
	void deleteCourse();

	//查找信息
	void SeachStudent();
	//精准查找
	void AccurateSearch();

	//据学号精准查找生成返回值
	int AccurateSearchInt(string ID);

	//据学号查找各科成绩
	void FuzzySearchScores();

	//据学号+课程号查找成绩
	void AccurateSearchScores();

	//据课程号查询课程信息
	void SearchByCoID();

	//据课程号精确查找生成返回值
	int AccurateSearchCo(string CoID);

	//修改信息
	void modifyInformation();

	//更改学生信息
	void modifyStudents();

	//更改成绩信息
	void modifyScores();

	//修改课程信息
	void modifyCourse();

	//统计某班级不及格名单
	void numberOfFailed();

	//统计某门课程各成绩段人数及百分比。
	void persentOfScore();


	//将分级成绩人数加入成绩分级类
	void divideLevelP(double scores, scoreLevel *scoreLevel);

	//获得成绩分级
	string divideLevel(double scores);

	//退出系统
	void exitSystem();
	

	//析构函数
	~StudentsManager();

	//学生信息头
	void studentstitle();

	//检索科目信息头
	void studentScoresTitle();

	//课程信息头
	void courseTitle();



private:
	Node* first;
	NodeSc* firstSc;
	NodeCo* firstCo;
	int Max = 0;
	int Max1 = 0;
	int Max2 = 0;
	
	
};