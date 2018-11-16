#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Colleage
{
private:
	string name;
	string content;
public:
	Colleage(string n = " "):name(n){};
	void set_name(string name)
	{
		this->name = name;
	}
	string get_name()
	{
		return this->name;
	}
	void set_content(string content)
	{
		this->content = content;
	}
	string get_content()
	{
		if(content.size() != 0)
			return content;
		else return "Copy that";
	}
	virtual void talk(){};

};

class Monitor : public Colleage
{
public:
	Monitor(string n = ""):Colleage(n){};
	virtual void talk()
	{
		cout<<"�೤ "<<get_name()<<" ˵��"<<get_content()<<endl;
	}
};

class Secretary : public Colleage
{
public:
	Secretary(string n = ""):Colleage(n){};
	virtual void talk()
	{
		cout<<"��֧�� "<<get_name()<<" ˵��"<<get_content()<<endl;
	}
};

class StudentA : public Colleage
{
public:
	StudentA(string n = ""):Colleage(n){};
	virtual void talk()
	{
		cout<<"ѧ�� A "<<get_name()<<" ˵��"<<get_content()<<endl;
	}
};

class StudentB : public Colleage
{
public:
	StudentB(string n = ""):Colleage(n){};
	virtual void talk()
	{
		cout<<"ѧ�� B "<<get_name()<<" ˵��"<<get_content()<<endl;
	}
};

class Mediator
{
public:
	vector<Colleage*> studentList;
	virtual void add_student(Colleage *student)
	{
		studentList.push_back(student);
	};
	virtual void notify(Colleage *student){};    
};

class QQMediator : public Mediator
{
public:
	virtual void notify(Colleage *student)
	{
		student->talk();
		for(int i = 0 ; i < studentList.size() ; ++i)
		{            
			if(student != studentList[i])
			{
				studentList[i]->talk();
			}
		}
	};	
};


int main()
{
	QQMediator qq;
	Monitor *studentMonitor = new Monitor("Foxx");
	Secretary *studentSecretary = new Secretary("TC");
	StudentA *studentA = new StudentA("Jack");
	StudentB *studentB = new StudentB("Frank");        

	qq.add_student(studentSecretary);
	qq.add_student(studentA);
	qq.add_student(studentB);     

	studentMonitor->set_content("���쿪ʼ�ż٣�");
	qq.notify(studentMonitor);  

	system("pause");
	return 0;
}
