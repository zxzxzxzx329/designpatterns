#include <iostream>
#include <string>
using namespace std;

class Memento 
{
private:
	string state;

public:
	Memento()
	{
		state = "";
	}
	Memento(string state)
	{
		this->state = state;
	}
	string getState() 
	{
		return state;
	}
	void setState(string state) 
	{
		this->state = state;
	}
};

class Originator 
{
private :
	string state;

public:
	Originator()
	{
		state = "";
	}

	string getState() 
	{
		return state;
	}
	void setState(string state) 
	{
		this->state = state;
	}
	Memento createMemento()
	{
		return Memento(this->state);
	}
	void restoreMemento(Memento memento)
	{
		this->setState(memento.getState());
	}
};

class Caretaker 
{
private :
	Memento memento;
public :
	Memento getMemento()
	{
		return memento;
	}
	void setMemento(Memento memento)
	{
		this->memento = memento;
	}
};

int main (int argc, char *argv[])   
{
	Originator originator;
	originator.setState("״̬1");
	cout<<"��ʼ״̬:"<<originator.getState()<<endl;

	Caretaker caretaker;
	caretaker.setMemento(originator.createMemento());
	originator.setState("״̬2");

	cout<<"�ı��״̬:"<<originator.getState()<<endl;
	originator.restoreMemento(caretaker.getMemento());
	cout<<"�ָ���״̬:"<<originator.getState()<<endl;

	system("pause");
}
