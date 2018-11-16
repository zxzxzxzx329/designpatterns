//Menu.h
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Menu  
{
public:
	virtual ~Menu(){};

	virtual void Add(Menu*){};
	virtual void Remove(Menu*){};
	virtual Menu* GetChild(int);
	virtual void Display() = 0;
protected:
	Menu(){};
	Menu(std::string);
	string m_strName;
};


Menu::Menu(std::string strName) : m_strName(strName)
{

}

Menu *Menu::GetChild(int)
{
    return NULL;
}


class SubMenu : public Menu  
{
public:
	SubMenu(){};
	SubMenu(string);
	virtual ~SubMenu(){};

	void Display();
};


SubMenu::SubMenu(string strName) : Menu(strName)
{

}

void SubMenu::Display()
{
	cout << m_strName << endl;
}

class CompositMenu : public Menu
{
public:
	CompositMenu(){};
	CompositMenu(string);
	virtual ~CompositMenu(){};

	void Add(Menu*);
	void Remove(Menu*);
	Menu* GetChild(int);
	void Display();
private:
	vector<Menu*> m_vMenu;
};

CompositMenu::CompositMenu(string strName) : Menu(strName)
{

}

void CompositMenu::Add(Menu* pMenu)
{
	m_vMenu.push_back(pMenu);
}

void CompositMenu::Remove(Menu* pMenu)
{
	for(vector<Menu*>::iterator iter = m_vMenu.begin(); iter != m_vMenu.end();)
	{
		if(pMenu == *iter)
		{
			iter = m_vMenu.erase(iter);
		}
		else
			++iter;
	}
}

Menu* CompositMenu::GetChild(int index)
{
	return m_vMenu[index];
}

void CompositMenu::Display()
{
	cout << "+" << m_strName << endl;
	vector<Menu*>::iterator it = m_vMenu.begin();
	for (; it != m_vMenu.end(); ++it)
	{
		cout << "|-";
		(*it)->Display();
	}
}

int main(int argc, char* argv[])
{
	Menu* pMenu = new CompositMenu("国内新闻");
	pMenu->Add(new SubMenu("时事新闻"));
	pMenu->Add(new SubMenu("社会新闻"));
	pMenu->Display();
	pMenu = new CompositMenu("国际新闻");
	pMenu->Add(new SubMenu("国际要闻"));
	pMenu->Add(new SubMenu("环球视野"));
	pMenu->Display();

	system("pause");
	return 0;
}
