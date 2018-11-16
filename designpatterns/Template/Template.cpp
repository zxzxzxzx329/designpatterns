#include <iostream>

template <typename T> 
class CaffeineBeverage  //咖啡因饮料
{
public:
	void PrepareRecipe() //咖啡因饮料冲泡法
	{
		BoilWater();  //把水煮沸
		Brew();    //冲泡
		PourInCup();  //把咖啡因饮料倒进杯子
		AddCondiments(); //加调料
	}
	void BoilWater()
	{std::cout << "把水煮沸" << std::endl;}
	void Brew()
	{static_cast<T *>(this)->Brew();}
	void PourInCup()
	{std::cout << "把咖啡倒进杯子" << std::endl;}
	void AddCondiments()
	{static_cast<T *>(this)->AddCondiments();}
};

class Coffee : public CaffeineBeverage<Coffee>
{
public:
	void Brew()
	{std::cout << "用沸水冲泡咖啡" << std::endl;}
	void AddCondiments()
	{std::cout << "加糖和牛奶" << std::endl;}
};

class Tea : public CaffeineBeverage<Tea>
{
public:
	void Brew()
	{std::cout << "用沸水浸泡茶叶" << std::endl;}
	void AddCondiments()
	{std::cout << "加柠檬" << std::endl;}
};

int main(void)
{
	std::cout << "冲杯咖啡:" << std::endl;
	Coffee c;
	c.PrepareRecipe();
	std::cout << std::endl;
	std::cout << "冲杯茶:" << std::endl;
	Tea t;
	t.PrepareRecipe();

	system("pause");
	return 0;
}
