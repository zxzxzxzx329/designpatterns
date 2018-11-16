#include <iostream>   
#include <list>   
#include <string>   

using namespace std;  

class CPerson;  
class CStudent;  
class CTeacher;  

class CVisitor;  
class CPrinter;  

//Ԫ�أ��������ߣ�  
class CPerson //������   
{  
protected:   
	string name; //���߸ĳ�����  
	int gender;   

	CPerson()  
	{  
	}  

public:  
	virtual void Accept( CVisitor& ) //= 0;//���麯��  
	{  
	}  
public:  
	void SetName(const string& Name)  
	{  
		name = Name;  
	}  

	string GetName() const  
	{         
		return name;  
	}  

	void SetGender(const int& Gender)  
	{  
		gender = Gender;  
	}  

	int GetGender() const  
	{  
		return gender;  
	}  

};  

//������  
class CVisitor   
{  
public:  
	virtual void Visit( CStudent& ) = 0;  
	virtual void Visit( CTeacher& ) = 0;  
};  

//����Ԫ��  
class CStudent: public CPerson   
{   
private:   
	int grade; //�꼶  
public:   
	CStudent(string Name,int Gender,int Grade)  
	{   
		name=Name;   
		gender=Gender;   
		grade=Grade;   
	}   
public:   
	virtual void Accept(CVisitor& printer) //�麯��  
	{  
		printer.Visit(*this);  
	}  

	void SetGrade(int Grade)  
	{  
		grade=Grade;  
	}  

	int GetGrade() const  
	{  
		return grade;  
	}  
};   

//����Ԫ��  
class CTeacher:public CPerson   
{   
private:  
	int service_time;//����  
public:   
	CTeacher(string Name,int Grade, int ServiceTime)   
	{   
		name = Name;   
		gender = Grade;   
		service_time = ServiceTime;  
	}   

public:   

	virtual void Accept(CVisitor& printer)  
	{  
		printer.Visit(*this);  
	}  

	void SetServiceTime(int ServiceTime)  
	{  
		service_time = ServiceTime;  
	}  

	int GetServiceTime() const  
	{  
		return service_time;  
	}  
};  

//���������  
//���������ӡ����Ԫ�ص���Ϣ��������ʾ����Ļ�ϣ����ɸ�����Ҫ��ӡ��ͬ�����ݡ�  
//�����������һ�ֲ��ԣ��ɸ��ݲ�ͬ��Ҫ�����µľ�������ߣ��������޸ľ���Ԫ�أ����������ߣ���  
class CPrinter: public CVisitor  
{   
public:           
	void Visit(CStudent& s)  
	{  
		cout <<"student:" <<endl;   
		cout <<"/t Name:" <<s.GetName() <<endl;   
		if(s.GetGender()==0)   
			cout <<"/t Gender:" <<"female" <<endl;   
		else   
			cout <<"/t Gender:" <<"male" <<endl;   
		cout <<"/t Grade:" <<s.GetGrade() <<endl;   
	}  

	void Visit(CTeacher& t)  
	{  
		cout <<"Teacher:" <<endl;   
		cout <<"/t Name:" <<t.GetName() <<endl;   
		if(t.GetGender()==0)   
			cout <<"/t Gender:" <<"female" <<endl;   
		else   
			cout <<"/t Gender:" <<"male" <<endl;   
		cout <<"/t Service Time:" <<t.GetServiceTime()<<endl;   
	}  
};  

//����ṹ  
//���Organization�Ǹ���֯����ֲ�������һ���Ŷӣ�ȥֲ��������������ʦ������ѧ����  
class Organization   
{  
private:  
	typedef list<CPerson*> CMemberList;  
	CMemberList member_list;   

public:   

	void Add(CPerson* person) //������Ա��ֻ��ʾ����û�п�����Ա�ظ��������  
	{  
		//ע�⣺personָ��Ŀռ��������new����������Ŀռ�  

		member_list.push_back(person);  
	}  

	//ֻ��ʾ��������ɾ����Ա�Ȳ�����ȥ  

	void PrintMembers(CPrinter& printer) //�����Ա����  
	{  
		CMemberList::iterator itr = member_list.begin();  
		for(; itr != member_list.end(); ++itr)   
		{    
			(*itr)->Accept(printer);  
		}  
	}  

	~Organization()  
	{  
		//ɾ������Ŀռ䣻c++�Ƚ��鷳  
		CMemberList::iterator itr = member_list.begin();  
		for(; itr != member_list.end(); ++itr)   
		{    
			delete *itr;  
		}  
	}  
};  

int main()   
{   
	Organization Planting;//ֲ����֯  
	Planting.Add( new CTeacher("Johnny",1,10) );  
	Planting.Add( new CStudent("Catherine",0,1) );  
	Planting.Add( new CStudent("peter",1,2) );  

	CPrinter printer;//�����ߣ�Ҳ�ɿ���һ�ֲ���  
	Planting.PrintMembers(printer);  

	system("pause");
	return 0;   
}  