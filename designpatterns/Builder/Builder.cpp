// CplusplusBuild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//product
class Food
{
private:
	vector<string> mFoodName;
	vector<int> mFoodPrice;

public:
	void add(string foodName,int price)
	{
		mFoodName.push_back(foodName);		
		mFoodPrice.push_back(price);
	}

	void show()
	{
		cout<<"Food List" <<endl;
		cout<<"-------------------"<<endl;
		for(int i=0;i<mFoodName.size();i++)
		{
			cout<<mFoodName[i]<<" "<<mFoodPrice[i]<<endl;
		}
	}
};

//builder
class Builder
{
public:
	virtual void BuildRiceNoodles() {};
	virtual void BuildCoolDish(){};
	virtual void BuildDrink(){};
	virtual Food * getFood(){return NULL;}
};


//builderA
class BuilderA:public Builder
{
private:
	Food *food;

public:
	BuilderA(){food = new Food();}
	void BuildRiceNoodles()
	{
		food->add("RiceNoodlesA",20);
	}
	void BuildCoolDish()
	{
		food->add("CoolDishA",20);
	}
	void BuildDrink()
	{
		food->add("DrinkA",20);
	}
	Food * getFood()
	{
		return food;
	}
};

//builderB
class BuilderB:public Builder
{
private:
	Food *food;
public:
	BuilderB(){food = new Food();}
	void BuildRiceNoodles()
	{
		food->add("RiceNoodlesB",10);
	}
	void BuildCoolDish()
	{
		food->add("CoolDishB",10);
	}
	void BuildDrink()
	{
		food->add("DrinkB",10);
	}
	Food * getFood()
	{
		return food;
	}
};

//director
class FoodManager
{
public:
	void Construct(Builder * builder)
	{
		builder->BuildRiceNoodles();
		builder->BuildDrink();
		builder->BuildCoolDish();
	}
};

//clent
int main(int argc, char* argv[])
{
	FoodManager *foodManager= new FoodManager();

	Builder * builder = new Builder();

	// the following code can use simple factory;
	char ch;
	cout<<"input your food Type (A or B):";
	cin>>ch;
	if(ch=='A')
	{
		builder = new BuilderA();
	}else if(ch=='B')
	{
		builder = new BuilderB();
	}

	foodManager->Construct(builder);
	Food * food = builder->getFood();
	food->show();

	system("pause");
	return 0;
}
