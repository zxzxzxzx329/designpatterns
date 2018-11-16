#include <iostream>

template <typename T> 
class CaffeineBeverage  //����������
{
public:
	void PrepareRecipe() //���������ϳ��ݷ�
	{
		BoilWater();  //��ˮ���
		Brew();    //����
		PourInCup();  //�ѿ��������ϵ�������
		AddCondiments(); //�ӵ���
	}
	void BoilWater()
	{std::cout << "��ˮ���" << std::endl;}
	void Brew()
	{static_cast<T *>(this)->Brew();}
	void PourInCup()
	{std::cout << "�ѿ��ȵ�������" << std::endl;}
	void AddCondiments()
	{static_cast<T *>(this)->AddCondiments();}
};

class Coffee : public CaffeineBeverage<Coffee>
{
public:
	void Brew()
	{std::cout << "�÷�ˮ���ݿ���" << std::endl;}
	void AddCondiments()
	{std::cout << "���Ǻ�ţ��" << std::endl;}
};

class Tea : public CaffeineBeverage<Tea>
{
public:
	void Brew()
	{std::cout << "�÷�ˮ���ݲ�Ҷ" << std::endl;}
	void AddCondiments()
	{std::cout << "������" << std::endl;}
};

int main(void)
{
	std::cout << "�屭����:" << std::endl;
	Coffee c;
	c.PrepareRecipe();
	std::cout << std::endl;
	std::cout << "�屭��:" << std::endl;
	Tea t;
	t.PrepareRecipe();

	system("pause");
	return 0;
}
