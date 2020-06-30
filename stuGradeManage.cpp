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


class Student  //对于基类的定义
{
public:
	int num;  //公用数据成员用于记录类成员的编号
	string name;
	string sex;
	int age;
public:
	Student(int n = 0, string nm = "", string s ="男", int a = 0) :num(n), name(nm), sex(s), age(a) {};
	virtual void Input() {};
	virtual void Output() {};
	int GetNum() { return num; }//公有数据成员函数用于获得成员编号
	string GetName() { return name; }//公有数据成员函数用于获得成员姓名
};
class Pupil :public Student//对小学生派生类的定义
{
public:
	int Chinese;//公有数据成员用于记录小学生的语文成绩
	int Math;//公有数据成员用于记录类成员的数学成绩
	int choice2;//公有数据成员用于选择类成员的性别
public:
	Pupil(int n = 0, string nm = "", string s = "", int a = 0, int l = 0, int z = 0)
		:Student(n, nm, s, a), Chinese(l), Math(z) {};
	void Input()//成员函数用于输入成员信息
	{
		cout << "input the Strdent num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误." << endl; break;
		}
		cout << "input the age" << endl;
		cin >> age;
		cout << "input the Chinese" << endl;
		cin >> Chinese;
		cout << "input the Math" << endl;
		cin >> Math;
	}
	void Output()//成员函数用于输出成员信息
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
class Middle :virtual public Student//对于中学生派生类的定义
{
public:
	int geography;//地理成绩
	int history;//历史成绩
	int choice2;//性别
public:
	Middle(int  n = 0, string nm = "", string s = "", int a = 0, int ge = 0, int hi = 0)
		:Student(n, nm, s, a), geography(ge), history(hi) {};
	void Input()//成员函数用于输入成员信息
	{
		cout << "input the num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "input the age" << endl;
		cin >> age;
		cout << "input the geography" << endl;
		cin >> geography;
		cout << "input the history" << endl;
		cin >> history;
	}
	void Output()//成员函数用于输出成员信息
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
class College :virtual public Student//对于大学生派生类的定义
{
public:
	int speciailty;
	int english;
	int c_lan;
	int hightmath;
	int choice2;
public:
	College(int n = 0, string nm = "", string s = "男", int a = 0, int speciailty = 0, int english = 0, int c_lan = 0, int hightmath = 0)
		:Student(n, nm, s, a), speciailty(), english(english), c_lan(c_lan), hightmath(hightmath) {};
	void Input()//成员函数用于输入成员信息
	{
		cout << "input the num" << endl;
		cin >> num;
		cout << "input the name" << endl;
		cin >> name;
		cout << "input the sex";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误。" << endl; break;
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
	Pupil Mid[TMAX];   //TMAX为常量，为数组中可存储的中学生记录的最大数；
	int top;            //top表示当前系统中存储的记录个数；
public:
	Pup_Manage() { top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //实现该类记录的添加；
	void Show();         //实现该类所有记录的显示； 
	void Search();       //实现该类记录的查询；
	void Edit();         //实现该类记录的修改；
	void Delete();       //实现该类记录的删除；
	void Total();        //实现该类记录的统计；
	void Save();         //将该类记录保存到文件；
	void Read();
	void sort1();
	//可从文件中将记录读取到该类的数组中；
	void Sort();
};

void Pup_Manage::Add()//函数的实现进行添加功能
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	Pupil t;
	cout << "输入新添加的学生的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "该编号的学生已存在" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void Pup_Manage::Show()//显示功能：可显示当前系统中所有记录，每条记录占据一行。
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	cout << setw(10) << "编号"
		<< setw(10) << "姓名"
		<< setw(10) << "性别"
		<< setw(10) << "年龄"
		<< setw(10) << "语文"
		<< setw(10) << "数学"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void Pup_Manage::Search()//查询功能：可根据编号、姓名等信息对已添加的记录进行查询，如果未找到，给出相应的提示信息，如果找到，则显示相应的记录信息。
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "请输入要查找的编号:" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	case 2: {
		cout << "请输入要查找的姓名" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void Pup_Manage::Edit()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的学生编号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "请对这位小学生的信息进行修改:" << endl;
			Mid[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void Pup_Manage::Delete()//删除功能：主要实现对已添加的人员记录进行删除。如果当前系统中没有相应的人员记录，则提示"记录为空！"并返回操作；否则，输入要删除的人员的编号或姓名，根据所输入的信息删除该人员记录，如果没有找到该人员信息，则提示相应的记录不存在。
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入编号：";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "删除成功！" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "无此项，失败！" << endl; break;
				}return;
			}
		}
		cout << "无此人！" << endl;

	}; break;
	case 2:
	{
		cout << "请输入姓名：";
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (name == Mid[i].name)
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "删除成功！" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "无此项，失败！" << endl; break;
				}return;
			}
		}
		cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void Pup_Manage::Total()//统计功能：能根据多种参数进行人员的统计。例如，统计类中人员数量以及总数，或者统计男、女员工的数量，不同部门员工数量等。

{
	cout << "1  按人数统计    2  按性别统计    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "学生人数为:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "男") a++;
			if (Mid[i].sex == "女") b++;
		}
		cout << "男学生人数为" << a << endl;
		cout << "女学生数为" << b << endl;
	}break;
	default:cout << "输入错误。请重新输入" << endl; break;
	}
}
void Pup_Manage::Save()//保存功能：可将当前系统中各类人员记录存入文件中，存入方式任意。
{
	ofstream out("pupilFile.txt", ios::out);
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
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
	cout << "写入成功！" << endl;
	out.close();
}
void Pup_Manage::Read()//读取功能：可将保存在文件中的人员信息读入到当前系统中，供用户进行使用。
{
	ifstream in(pupilFile, ios::in);
	if (!in)
	{
		cout << "打开失败!" << endl;
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
	Middle Mid[TMAX];   //TMAX为常量，为数组中可存储的教师记录的最大数；
	int top;             //top表示当前系统中存储的记录个数；
public:
	Mid_Manage() { top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //实现该类记录的添加；
	void Show();         //实现该类所有记录的显示； 
	void Search();       //实现该类记录的查询；
	void Edit();         //实现该类记录的修改；
	void Delete();       //实现该类记录的删除；
	void Total();        //实现该类记录的统计；
	void Save();         //将该类记录保存到文件；
	void Read();
	void sort1();
	//可从文件中将记录读取到该类的数组中；
	void Sort();
};
void Mid_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	Middle t;
	cout << "输入新添加的学生的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "该编号的学生已存在" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void Mid_Manage::Show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	cout << setw(10) << "编号"
		<< setw(10) << "姓名"
		<< setw(10) << "性别"
		<< setw(10) << "年龄"
		<< setw(10) << "地理"
		<< setw(10) << "历史"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void Mid_Manage::Search()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "请输入要查找的编号:" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	case 2: {
		cout << "请输入要查找的姓名" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void Mid_Manage::Edit()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的学生编号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "请对这位中学生的信息进行修改:" << endl;
			Mid[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void Mid_Manage::Delete()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入编号：";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "删除成功！" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "无此项，失败！" << endl; break;
				}return;
			}
		}
		cout << "无此人！" << endl;

	}; break;
	case 2:
	{
		cout << "请输入姓名：";
		string name;
		cin >> name;
		for (int i = 0; i < top; i++)
		{
			if (name == Mid[i].name)
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "删除成功！" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "无此项，失败！" << endl; break;
				}return;
			}
		}
		cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void Mid_Manage::Total()
{
	cout << "1  按人数统计    2  按性别统计     " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "中学生人数为:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "男") a++;
			if (Mid[i].sex == "女") b++;
		}
		cout << "男学生人数为" << a << endl;
		cout << "女学生人数为" << b << endl;
	}break;

	default:cout << "输入错误。请重新输入" << endl; break;
	}
}
void Mid_Manage::Save()
{
	ofstream out("middleFile.txt", ios::out);
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
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
	cout << "写入成功！" << endl;
	out.close();
}
void Mid_Manage::Read()
{
	ifstream in(middleFile, ios::in);
	if (!in)
	{
		cout << "打开失败!" << endl;
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
	College Mid[TMAX];   //TMAX为常量，为数组中可存储的中学生记录的最大数；
	int top;             //top表示当前系统中存储的记录个数；
public:
	College_Manage() { top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //实现该类记录的添加；
	void Show();         //实现该类所有记录的显示； 
	void Search();       //实现该类记录的查询；
	void Edit();         //实现该类记录的修改；
	void Delete();       //实现该类记录的删除；
	void Total();        //实现该类记录的统计；
	void Save();         //将该类记录保存到文件；
	void Read();         //可从文件中将记录读取到该类的数组中；
	void Sort();         //排序功能；
	void sort1();
	void sort2();
};
void College_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	College t;
	cout << "输入新添加的学生的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
		if (t.GetNum() == Mid[i].GetNum())
		{
			cout << "该编号的学生已存在" << endl;
			return;
		}
	Mid[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void College_Manage::Show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	cout << setw(10) << "编号"
		<< setw(10) << "姓名"
		<< setw(10) << "性别"
		<< setw(10) << "年龄"
		<< setw(10) << "专业"
		<< setw(10) << "联系方式"
		<< endl;
	for (int i = 0; i < top; i++)
		Mid[i].Output();
}
void College_Manage::Search()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "请输入要查找的编号:" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	case 2: {
		cout << "请输入要查找的姓名" << endl;
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
		cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void College_Manage::Delete()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入编号：";
		int num;
		cin >> num;
		for (int i = 0; i < top; i++)
		{
			if (num == Mid[i].num)
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j < top - 1; j++)
						Mid[j] = Mid[j + 1];
					cout << "删除成功！" << endl;
					top--;
				}; break;
				case 2:return;
				default:cout << "无此项，失败！" << endl; break;
				}return;
			}
		}
		cout << "无此人！" << endl;

	}; break;
	case 2:
	{cout << "请输入姓名：";
	string name;
	cin >> name;
	for (int i = 0; i < top; i++)
	{
		if (name == Mid[i].name)
		{
			cout << "是否确认删除？     1、是    2、否  " << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				for (int j = i; j < top - 1; j++)
					Mid[j] = Mid[j + 1];
				cout << "删除成功！" << endl;
				top--;
			}; break;
			case 2:return;
			default:cout << "无此项，失败！" << endl; break;
			}return;
		}
	}
	cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void College_Manage::Edit()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的学生编号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (Mid[i].GetNum() == num)
		{
			cout << "请对这位中学生的信息进行修改:" << endl;
			Mid[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void College_Manage::Total()
{
	cout << "1  按人数统计    2  按性别统计    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "大学生人数为:" << top << endl; break;
	case 2:
	{
		int a = 0, b = 0;
		for (int i = 0; i < top; i++)
		{
			if (Mid[i].sex == "男") a++;
			if (Mid[i].sex == "女") b++;
		}
		cout << "男生人数为" << a << endl;
		cout << "女生人数为" << b << endl;
	}break;
	default:cout << "输入错误。请重新输入" << endl; break;
	}
}


void College_Manage::Save()
{
	ofstream out(collegeFile, ios::out);
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
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
	cout << "写入成功！" << endl;
	out.close();
}
void College_Manage::Read()
{
	ifstream in(collegeFile, ios::in);
	if (!in)
	{
		cout << "打开失败!" << endl;
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
		cout << "总成绩排序：" << sum[i] << endl;
}

void   Mid_Manage::sort1() {
	int sum[10];
	for (int i = 0; i < top; i++) {
		sum[i] = Mid[i].history + Mid->geography;
	}
	sort(sum, sum + 2);

	for (int i = 0; i < 4; i++)
		cout << "总成绩排序：" << sum[i] << endl;
}

void   Pup_Manage::sort1() {
	int sum[10];
	for (int i = 0; i < top; i++) {
		sum[i] = Mid[i].Chinese + Mid[i].Math;
	}
	sort(sum, sum + 2);

	for (int i = 0; i < 4; i++)
		cout << "总成绩排序：" << sum[i] << endl;
}



void College_Manage::Sort() {
	cout << "1  按单科成绩排序    2  按总分成绩排序    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "单科成绩排序:" << endl;
		break;
	case 2:cout << "总分成绩排序:" << endl;

		for (int i = 0; i < top; i++)
		{

		}
	}
}


void Mid_Manage::Sort() {
	cout << "1  按单科成绩排序    2  按总分成绩排序    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "单科成绩排序:" << endl;
		break;
	case 2:cout << "总分成绩排序:" << endl;

		for (int i = 0; i < top; i++)
		{

		}
	}

}
void Pup_Manage::Sort() {
	cout << "1  按单科成绩排序    2  按总分成绩排序    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "单科成绩排序:" << endl;
		break;
	case 2:cout << "总分成绩排序:" << endl;

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
	cout << "                ***欢迎进入 学生管理系统***" << endl;
	int choice;

	do {
		cout << "                          *****主菜单*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||1=>小学生管理 2=>中学生管理  3=>大学生管理   0=>退出系统      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n请输入您的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:PupMenu(); break;
		case 2:MidMenu(); break;
		case 3:CollegeMenu(); break;
		case 0:cout << "\n您已安全退出系统." << endl; exit(1); break;
		default:cout << "\n没有此选项.请重选." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***欢迎您下次再使用本系统!***" << endl;
	return 0;
}
void PupMenu()//小学生函数主界面的定义
{
	Pup_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***小学生管理***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.添加  2.查找  3.修改   4.删除  5.显示  6.保存  7.读取 8.统计 9.排序  0=>退出 |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl;  exit(1); break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
void MidMenu()//中学生函数主界面的定义
{
	Mid_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***中学生管理***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.添加  2.查找  3.修改   4.删除  5.显示  6.保存  7.读取 8.统计 9.排序  0=>退出 |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl; exit(1); break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
void CollegeMenu()//大学生主界面的定义
{
	College_Manage t;
	int choice;
	while (true)
	{
		cout << " \n                          ***大学生管理***                   " << endl;;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "|  1.添加  2.查找  3.修改   4.删除  5.显示  6.保存  7.读取 8.统计 9.排序  0=>退出 |" << endl;
		cout << "|                                                                                 |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl; exit(1); break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
