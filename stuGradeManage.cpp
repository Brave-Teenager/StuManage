#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<math.h>
#include <algorithm>
const int TMAX = 50;
using namespace std;
const string collegeFile = "collegefile.txt";
const string middleFile = "middlefile.txt";
const string pupilFile = "pupilfile.txt";


class Student  //���ڻ���Ķ���
{
public:
	int num;  //�������ݳ�Ա���ڼ�¼���Ա�ı��
	string name;
	string sex;
	int age;
public:
	Student(int n = 0, string nm = "", string s ="��", int a = 0) :num(n), name(nm), sex(s), age(a) {};
	virtual void Input() {};
	virtual void Output() {};
	int GetNum() { return num; }//�������ݳ�Ա�������ڻ�ó�Ա���
	string GetName() { return name; }//�������ݳ�Ա�������ڻ�ó�Ա����
};
class Pupil :public Student//��Сѧ��������Ķ���
{
public:
	int Chinese;//�������ݳ�Ա���ڼ�¼Сѧ�������ĳɼ�
	int Math;//�������ݳ�Ա���ڼ�¼���Ա����ѧ�ɼ�
	int choice2;//�������ݳ�Ա����ѡ�����Ա���Ա�
public:
	Pupil(int n = 0, string nm = "", string s = "", int a = 0, int l = 0, int z = 0)
		:Student(n, nm, s, a), Chinese(l), Math(z) {};
	void Input()//��Ա�������������Ա��Ϣ
	{
		cout << "input the Strdent num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������." << endl; break;
		}
		cout << "input the age" << endl;
		cin >> age;
		cout << "input the Chinese" << endl;
		cin >> Chinese;
		cout << "input the Math" << endl;
		cin >> Math;
	}
	void Output()//��Ա�������������Ա��Ϣ
	{
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << Chinese
			<< setw(10) << Math
			<< endl;
	}
};
class Middle :virtual public Student//������ѧ��������Ķ���
{
public:
	int geography;//����ɼ�
	int history;//��ʷ�ɼ�
	int choice2;//�Ա�
public:
	Middle(int  n = 0, string nm = "", string s = "", int a = 0, int ge = 0, int hi = 0)
		:Student(n, nm, s, a), geography(ge), history(hi) {};
	void Input()//��Ա�������������Ա��Ϣ
	{
		cout << "input the num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "input the age" << endl;
		cin >> age;
		cout << "input the geography" << endl;
		cin >> geography;
		cout << "input the history" << endl;
		cin >> history;
	}
	void Output()//��Ա�������������Ա��Ϣ
	{
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << geography
			<< setw(10) << history
			<< endl;
	}
};
class College :virtual public Student//���ڴ�ѧ��������Ķ���
{
public:
	int speciailty;
	int english;
	int c_lan;
	int hightmath;
	int choice2;
public:
	College(int n = 0, string nm = "", string s = "��", int a = 0, int speciailty = 0, int english = 0, int c_lan = 0, int hightmath = 0)
		:Student(n, nm, s, a), speciailty(), english(english), c_lan(c_lan), hightmath(hightmath) {};
	void Input()//��Ա�������������Ա��Ϣ
	{
		cout << "input the num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "input the age" << endl;
		cin >> age;
		cout << "input the speciailty" << endl;
		cin >> speciailty;
		cout << "input the english" << endl;
		cin >> english;
		cout << "input the c_lan" << endl;
		cin >> c_lan;
		cout << "input the hightmath" << endl;
		cin >> hightmath;
	}
	void Output()
	{
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << speciailty
			<< setw(10) << english
			<< setw(10) << c_lan
			<< setw(10) << hightmath
			<< endl;
	}
	void sort(College a, College b);
};

class Pup_Manage
{
	Pupil Mid[TMAX];   //TMAXΪ������Ϊ�����пɴ洢����ѧ����¼���������
	int top;            //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	Pup_Manage() { top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //ʵ�ָ����¼����ӣ�
	void Show();         //ʵ�ָ������м�¼����ʾ�� 
	void Search();       //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();         //ʵ�ָ����¼���޸ģ�
	void Delete();       //ʵ�ָ����¼��ɾ����
	void Total();        //ʵ�ָ����¼��ͳ�ƣ�
	void Save();         //�������¼���浽�ļ���
	void Read();
	void sort1();
	//�ɴ��ļ��н���¼��ȡ������������У�
	void Sort();
};

void Pup_Manage::Add()//������ʵ�ֽ�����ӹ���
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	Pupil t;
	cout << "��������ӵ�ѧ������Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "�ñ�ŵ�ѧ���Ѵ���" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void Pup_Manage::Show()//��ʾ���ܣ�����ʾ��ǰϵͳ�����м�¼��ÿ����¼ռ��һ�С�
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	cout << setw(10) << "���"
		<< setw(10) << "����"
		<< setw(10) << "�Ա�"
		<< setw(10) << "����"
		<< setw(10) << "����"
		<< setw(10) << "��ѧ"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void Pup_Manage::Search()//��ѯ���ܣ��ɸ��ݱ�š���������Ϣ������ӵļ�¼���в�ѯ�����δ�ҵ���������Ӧ����ʾ��Ϣ������ҵ�������ʾ��Ӧ�ļ�¼��Ϣ��
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "������Ҫ���ҵı��:" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetNum() == num)
			{
				Mid[i].Output();
				return;
			}
		}
		cout << "���޴��ˣ�" << endl;
	}break;
	case 2: {
		cout << "������Ҫ���ҵ�����" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetName() == name)
			{
				Mid[i].Output();
			}
		}
		for (int i = 0; i < top; i++)
			if (Mid[i].GetName() == name)
				return;
		cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void Pup_Manage::Edit()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵ�ѧ�����:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "�����λСѧ������Ϣ�����޸�:" << endl;
			Mid[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void Pup_Manage::Delete()//ɾ�����ܣ���Ҫʵ�ֶ�����ӵ���Ա��¼����ɾ���������ǰϵͳ��û����Ӧ����Ա��¼������ʾ"��¼Ϊ�գ�"�����ز�������������Ҫɾ������Ա�ı�Ż��������������������Ϣɾ������Ա��¼�����û���ҵ�����Ա��Ϣ������ʾ��Ӧ�ļ�¼�����ڡ�
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "�������ţ�";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "ɾ���ɹ���" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "�޴��ʧ�ܣ�" << endl; break;
				}return;
			}
		}
		cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{
		cout << "������������";
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (name == Mid[i].name)
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "ɾ���ɹ���" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "�޴��ʧ�ܣ�" << endl; break;
				}return;
			}
		}
		cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void Pup_Manage::Total()//ͳ�ƹ��ܣ��ܸ��ݶ��ֲ���������Ա��ͳ�ơ����磬ͳ��������Ա�����Լ�����������ͳ���С�ŮԱ������������ͬ����Ա�������ȡ�

{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "ѧ������Ϊ:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "��") a++;
			if (Mid[i].sex == "Ů") b++;
		}
		cout << "��ѧ������Ϊ" << a << endl;
		cout << "Ůѧ����Ϊ" << b << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void Pup_Manage::Save()//���湦�ܣ��ɽ���ǰϵͳ�и�����Ա��¼�����ļ��У����뷽ʽ���⡣
{
	ofstream out("pupilFile.txt", ios::out);
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << Mid[i].num << " "
			<< Mid[i].name << " "
			<< Mid[i].sex << " "
			<< Mid[i].age << " "
			<< Mid[i].Chinese << " "
			<< Mid[i].Math
			<< endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void Pup_Manage::Read()//��ȡ���ܣ��ɽ��������ļ��е���Ա��Ϣ���뵽��ǰϵͳ�У����û�����ʹ�á�
{
	ifstream in(pupilFile, ios::in);
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> Mid[i].num
		>> Mid[i].name
		>> Mid[i].sex
		>> Mid[i].age
		>> Mid[i].Chinese
		>> Mid[i].Math)
	{
		Mid[i].Output();
		i++;
		top++;
	}
	in.close();
};
class Mid_Manage
{
	Middle Mid[TMAX];   //TMAXΪ������Ϊ�����пɴ洢�Ľ�ʦ��¼���������
	int top;             //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	Mid_Manage() { top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //ʵ�ָ����¼����ӣ�
	void Show();         //ʵ�ָ������м�¼����ʾ�� 
	void Search();       //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();         //ʵ�ָ����¼���޸ģ�
	void Delete();       //ʵ�ָ����¼��ɾ����
	void Total();        //ʵ�ָ����¼��ͳ�ƣ�
	void Save();         //�������¼���浽�ļ���
	void Read();
	void sort1();
	//�ɴ��ļ��н���¼��ȡ������������У�
	void Sort();
};
void Mid_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	Middle t;
	cout << "��������ӵ�ѧ������Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "�ñ�ŵ�ѧ���Ѵ���" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void Mid_Manage::Show()
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	cout << setw(10) << "���"
		<< setw(10) << "����"
		<< setw(10) << "�Ա�"
		<< setw(10) << "����"
		<< setw(10) << "����"
		<< setw(10) << "��ʷ"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void Mid_Manage::Search()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "������Ҫ���ҵı��:" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetNum() == num)
			{
				Mid[i].Output();
				return;
			}
		}
		cout << "���޴��ˣ�" << endl;
	}break;
	case 2: {
		cout << "������Ҫ���ҵ�����" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetName() == name)
			{
				Mid[i].Output();
			}
		}
		for (int i = 0; i < top; i++)
			if (Mid[i].GetName() == name)
				return;
		cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void Mid_Manage::Edit()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵ�ѧ�����:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "�����λ��ѧ������Ϣ�����޸�:" << endl;
			Mid[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void Mid_Manage::Delete()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "�������ţ�";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "ɾ���ɹ���" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "�޴��ʧ�ܣ�" << endl; break;
				}return;
			}
		}
		cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{
		cout << "������������";
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (name == Mid[i].name)
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "ɾ���ɹ���" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "�޴��ʧ�ܣ�" << endl; break;
				}return;
			}
		}
		cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void Mid_Manage::Total()
{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��     " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "��ѧ������Ϊ:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "��") a++;
			if (Mid[i].sex == "Ů") b++;
		}
		cout << "��ѧ������Ϊ" << a << endl;
		cout << "Ůѧ������Ϊ" << b << endl;
	}break;

	default:cout << "�����������������" << endl; break;
	}
}
void Mid_Manage::Save()
{
	ofstream out("middleFile.txt", ios::out);
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << Mid[i].num << " "
			<< Mid[i].name << " "
			<< Mid[i].sex << " "
			<< Mid[i].age << " "
			<< Mid[i].geography << " "
			<< Mid[i].history << " "
			<< endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void Mid_Manage::Read()
{
	ifstream in(middleFile, ios::in);
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> Mid[i].num
		>> Mid[i].name
		>> Mid[i].sex
		>> Mid[i].age
		>> Mid[i].geography
		>> Mid[i].history)
	{
		Mid[i].Output();
		i++;
		top++;
	}
	in.close();
};
class College_Manage
{
	College Mid[TMAX];   //TMAXΪ������Ϊ�����пɴ洢����ѧ����¼���������
	int top;             //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	College_Manage() { top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //ʵ�ָ����¼����ӣ�
	void Show();         //ʵ�ָ������м�¼����ʾ�� 
	void Search();       //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();         //ʵ�ָ����¼���޸ģ�
	void Delete();       //ʵ�ָ����¼��ɾ����
	void Total();        //ʵ�ָ����¼��ͳ�ƣ�
	void Save();         //�������¼���浽�ļ���
	void Read();         //�ɴ��ļ��н���¼��ȡ������������У�
	void Sort();         //�����ܣ�
	void sort1();
	void sort2();
};
void College_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	College t;
	cout << "��������ӵ�ѧ������Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "�ñ�ŵ�ѧ���Ѵ���" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void College_Manage::Show()
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	cout << setw(10) << "���"
		<< setw(10) << "����"
		<< setw(10) << "�Ա�"
		<< setw(10) << "����"
		<< setw(10) << "רҵ"
		<< setw(10) << "��ϵ��ʽ"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void College_Manage::Search()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "������Ҫ���ҵı��:" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetNum() == num)
			{
				Mid[i].Output();
				return;
			}
		}
		cout << "���޴��ˣ�" << endl;
	}break;
	case 2: {
		cout << "������Ҫ���ҵ�����" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].GetName() == name)
			{
				Mid[i].Output();
			}
		}
		for (int i = 0; i < top; i++)
			if (Mid[i].GetName() == name)
				return;
		cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void College_Manage::Delete()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "�������ţ�";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "ɾ���ɹ���" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "�޴��ʧ�ܣ�" << endl; break;
				}return;
			}
		}
		cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{cout << "������������";
	string name;
	cin >> name;
	for (int i = 0; i < top; i++)
	{
		if (name == Mid[i].name)
		{
			cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				for (int j = i; j < top - 1; j++)
					Mid[j] = Mid[j + 1];
				cout << "ɾ���ɹ���" << endl;
				top--;
			}; break;
			case 2:return;
			default:cout << "�޴��ʧ�ܣ�" << endl; break;
			}return;
		}
	}
	cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void College_Manage::Edit()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵ�ѧ�����:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "�����λ��ѧ������Ϣ�����޸�:" << endl;
			Mid[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void College_Manage::Total()
{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "��ѧ������Ϊ:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "��") a++;
			if (Mid[i].sex == "Ů") b++;
		}
		cout << "��������Ϊ" << a << endl;
		cout << "Ů������Ϊ" << b << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}


void College_Manage::Save()
{
	ofstream out(collegeFile, ios::out);
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << Mid[i].num << " "
			<< Mid[i].name << " "
			<< Mid[i].sex << " "
			<< Mid[i].age << " "
			<< Mid[i].speciailty << " "
			<< Mid[i].english << " "
			<< Mid[i].c_lan << " "
			<< Mid[i].hightmath << " "
			<< endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void College_Manage::Read()
{
	ifstream in(collegeFile, ios::in);
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> Mid[i].num
		>> Mid[i].name
		>> Mid[i].sex
		>> Mid[i].age
		>> Mid[i].speciailty
		>> Mid[i].english
		>> Mid[i].c_lan
		>> Mid[i].hightmath)
	{
		Mid[i].Output();
		i++;
		top++;
	}
	in.close();
};

void College_Manage::sort1() {
	int sum[10];
	for (int i = 0; i < top; i++) {
		sum[i] = Mid[i].english + Mid->c_lan + Mid[i].hightmath + Mid[i].speciailty;
	}
	sort(sum, sum + 4);

	for (int i = 0; i < 4; i++)
		cout << "�ܳɼ�����" << sum[i] << endl;
}

void   Mid_Manage::sort1() {
	int sum[10];
	for (int i = 0; i < top; i++) {
		sum[i] = Mid[i].history + Mid->geography;
	}
	sort(sum, sum + 2);

	for (int i = 0; i < 4; i++)
		cout << "�ܳɼ�����" << sum[i] << endl;
}

void   Pup_Manage::sort1() {
	int sum[10];
	for (int i = 0; i < top; i++) {
		sum[i] = Mid[i].Chinese + Mid[i].Math;
	}
	sort(sum, sum + 2);

	for (int i = 0; i < 4; i++)
		cout << "�ܳɼ�����" << sum[i] << endl;
}



void College_Manage::Sort() {
	cout << "1  �����Ƴɼ�����    2  ���ֳܷɼ�����    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "���Ƴɼ�����:" << endl;
		break;
	case 2:cout << "�ֳܷɼ�����:" << endl;

		for (int i = 0; i < top; i++)
		{

		}
	}
}


void Mid_Manage::Sort() {
	cout << "1  �����Ƴɼ�����    2  ���ֳܷɼ�����    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "���Ƴɼ�����:" << endl;
		break;
	case 2:cout << "�ֳܷɼ�����:" << endl;

		for (int i = 0; i < top; i++)
		{

		}
	}

}
void Pup_Manage::Sort() {
	cout << "1  �����Ƴɼ�����    2  ���ֳܷɼ�����    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "���Ƴɼ�����:" << endl;
		break;
	case 2:cout << "�ֳܷɼ�����:" << endl;

		for (int i = 0; i < top; i++)
		{

		}
	}
}

void PupMenu();
void MidMenu();
void CollegeMenu();
int main()
{
	cout << "                ***��ӭ���� ѧ������ϵͳ***" << endl;
	int choice;

	do {
		cout << "                          *****���˵�*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||1=>Сѧ������ 2=>��ѧ������  3=>��ѧ������   0=>�˳�ϵͳ      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n����������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:PupMenu(); break;
		case 2:MidMenu(); break;
		case 3:CollegeMenu(); break;
		case 0:cout << "\n���Ѱ�ȫ�˳�ϵͳ." << endl; exit(1); break;
		default:cout << "\nû�д�ѡ��.����ѡ." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***��ӭ���´���ʹ�ñ�ϵͳ!***" << endl;
	return 0;
}
void PupMenu()//Сѧ������������Ķ���
{
	Pup_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***Сѧ������***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.���  2.����  3.�޸�   4.ɾ��  5.��ʾ  6.����  7.��ȡ 8.ͳ�� 9.����  0=>�˳� |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 9:t.Sort(); break;
		case 0:cout << "�˳��ɹ�!" << endl;  exit(1); break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
void MidMenu()//��ѧ������������Ķ���
{
	Mid_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***��ѧ������***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.���  2.����  3.�޸�   4.ɾ��  5.��ʾ  6.����  7.��ȡ 8.ͳ�� 9.����  0=>�˳� |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 9:t.Sort(); break;
		case 0:cout << "�˳��ɹ�!" << endl; exit(1); break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
void CollegeMenu()//��ѧ��������Ķ���
{
	College_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***��ѧ������***                   " << endl;;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.���  2.����  3.�޸�   4.ɾ��  5.��ʾ  6.����  7.��ȡ 8.ͳ�� 9.����  0=>�˳� |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 9:t.Sort(); break;
		case 0:cout << "�˳��ɹ�!" << endl; exit(1); break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
