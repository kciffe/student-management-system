#include<iostream>
using namespace std;
#include "StudentsManager.h"


bool AllisNum(string str);

int main() {


	//�����ࡪ������ѧ������ϵͳ
	StudentsManager start;

	//�򿪲˵�����
	string choice = "123";
	//cout<<AllisNum(choice);
		while (true)
		{
			//չʾ�˵�
			start.ShowMenu();
			cout << "����������ѡ��:" << endl;
			cin >> choice;
			if (!AllisNum(choice)) {
				cout << "���������������������"<<endl;
				continue;
			}

			switch (stoll(choice))
			{
			case 0: //�˳�ϵͳ
				start.exitSystem();
				break;
			case 1: //���ѧ��
				start.inputStudent();
				break;
			case 2: //��ʾѧ��
				start.display();
				break;
			case 3: //ɾ��ѧ��
				start.DeleteStudent();
				break;
			case 4: //�޸���Ϣ
				start.modifyInformation();
				break;
			case 5: //����ѧ��
				start.SeachStudent();
				break;
			case 6: //ͳ�ư༶����������
				start.numberOfFailed();
				break;
			case 7: //ͳ�ƿγ̳ɼ��ֲ���
				start.persentOfScore();
				break;
			default:
				//���½��뱾ѭ��
				cout << "���������������������" << endl;
				continue;
			}
		}
	system("pause");

	return 0;
}