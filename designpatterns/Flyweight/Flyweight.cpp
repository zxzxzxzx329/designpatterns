// CplusplusFlyweight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;
class Character  
{
public:
	virtual ~Character(){};

	virtual void SetSize(int, int) = 0;
	virtual void Display() = 0;
protected:
	Character(){};
	char m_chSymbol;
	int m_nWeight;
	int m_nHeight;
};

class CharacterA : public Character
{
public:
	CharacterA();
	virtual ~CharacterA();

	void SetSize(int, int);
	void Display();
};

CharacterA::CharacterA()
{
	this->m_chSymbol = 'A';
	this->m_nWeight = 100;
	this->m_nHeight = 200;
}

CharacterA::~CharacterA()
{

}
void CharacterA::SetSize(int nWeight, int nHeight)
{
	this->m_nWeight = nWeight;
	this->m_nHeight = nHeight;
}
void CharacterA::Display()
{
	cout << "CharacterA：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
}

class CharacterB : public Character
{
public:
	CharacterB();
	virtual ~CharacterB();

	void SetSize(int, int);
	void Display();
};

CharacterB::CharacterB()
{
	this->m_chSymbol = 'B';
	this->m_nWeight = 100;
	this->m_nHeight = 200;
}

CharacterB::~CharacterB()
{

}

void CharacterB::SetSize(int nWeight, int nHeight)
{
	this->m_nWeight = nWeight;
	this->m_nHeight = nHeight;
}

void CharacterB::Display()
{
	cout << "CharacterB：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
}

class CharacterFactory  
{
public:
	CharacterFactory();
	virtual ~CharacterFactory();

	Character* GetCharacter(char);
private:
	std::map<char, Character*> m_mChar;
};

CharacterFactory::CharacterFactory()
{
	m_mChar.insert(make_pair<char, Character*>('A', new CharacterA));
	m_mChar.insert(make_pair<char, Character*>('B', new CharacterB));
}

CharacterFactory::~CharacterFactory()
{

}

Character* CharacterFactory::GetCharacter(char chIn)
{
	map<char, Character*>::iterator it = m_mChar.find(chIn);
	if(it != m_mChar.end())
	{
		return (Character*)it->second;
	}

	return NULL;
}

int main(int argc, char* argv[])
{
	CharacterFactory* pFactory = new CharacterFactory;

	//内蕴状态 存储在享元对象内部并且不会随环境改变而改变
	Character* ch1 = pFactory->GetCharacter('A');
	ch1->Display();

	//外蕴状态 客户端保存
	Character* ch2 = pFactory->GetCharacter('B');
	ch2->SetSize(500, 800);
	ch2->Display();

	system("pause");
	return 0;
}
