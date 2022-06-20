#include<iostream>
using namespace std;
#include "StudentsManager.h"


bool AllisNum(string str);

int main() {


	//创建类——进入学籍管理系统
	StudentsManager start;

	//打开菜单功能
	string choice = "123";
	//cout<<AllisNum(choice);
		while (true)
		{
			//展示菜单
			start.ShowMenu();
			cout << "请输入您的选择:" << endl;
			cin >> choice;
			if (!AllisNum(choice)) {
				cout << "输入操作错误，请重新输入"<<endl;
				continue;
			}

			switch (stoll(choice))
			{
			case 0: //退出系统
				start.exitSystem();
				break;
			case 1: //添加学生
				start.inputStudent();
				break;
			case 2: //显示学生
				start.display();
				break;
			case 3: //删除学生
				start.DeleteStudent();
				break;
			case 4: //修改信息
				start.modifyInformation();
				break;
			case 5: //查找学生
				start.SeachStudent();
				break;
			case 6: //统计班级不及格人数
				start.numberOfFailed();
				break;
			case 7: //统计课程成绩分布比
				start.persentOfScore();
				break;
			default:
				//从新进入本循环
				cout << "输入操作错误，请重新输入" << endl;
				continue;
			}
		}
	system("pause");

	return 0;
}