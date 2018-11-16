//应用
//①优点
//
//抽象和实现分离
//
//完全为了解决集成的缺点而提出的设计模式////抽象与实现的关系本来是纵向的，桥梁模式将他们改为横向关系
//
//优秀的扩充能力
//
//实现细节对客户透明
//
//使用场景
//不希望或者不适合通过继承的场景
//
//接口或者抽象类不稳定
//
//重要性要求较高的场景
//
//注意事项
//使用桥梁模式重点在于如何拆分抽象和实现，并不是以设计继承就考虑使他，桥梁的意图是对变化进行封装

#pragma once
#include<iostream>
using namespace std;

class Implementor
{
protected:
	Implementor(){}
public:
	virtual ~Implementor() = 0{}

	virtual void doSomething() = 0;
	virtual void doAnything() = 0;
};

class ConcreteImplementor1 :public Implementor
{
public:
	void doSomething()
	{
		cout << "1doSomething();" << endl;
	}
	void doAnything()
	{
		cout << "1doAnything();" << endl;
	}
};
class ConcreteImplementor2 :public Implementor
{
public:
	void doSomething()
	{
		cout << "2doSomething();" << endl;
	}
	void doAnything()
	{
		cout << "2doAnything();" << endl;
	}
};

class Abstraction
{
private:
	Implementor *_imp;
public:
	Abstraction(Implementor * imp)
		:_imp(imp)
	{}

	virtual void request()
	{
		_imp->doSomething();
	}
	Implementor* getImp()
	{
		return _imp;
	}
};

class RefinedAbstraction :public Abstraction
{
public:
	RefinedAbstraction(Implementor* imp)
		:Abstraction(imp)
	{}

	void request()
	{
		Abstraction::request();
		Abstraction::getImp()->doAnything();
	}
};

class Client
{
public:
	void operator()()
	{
		Implementor* imp = new ConcreteImplementor1();
		Abstraction* abs = new RefinedAbstraction(imp);
		abs->request();

		Implementor* imp2 = new ConcreteImplementor2();
		Abstraction* abs2 = new RefinedAbstraction(imp2);
		abs2->request();
	}
};

int main()
{
	Client c1;
	c1();
	system("pause");
	return 0;
};