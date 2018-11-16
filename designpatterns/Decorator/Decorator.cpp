#include <string>
#include <iostream>
#include <memory>
using namespace std;

//������Tank
class Tank
{
public:
	virtual void shot()=0;
	virtual void run()=0;

public:
	virtual ~Tank()
	{
		cout<<"in the destructor of Tank"<<endl;
	}	
};
//������ T50
class T50:public Tank
{
public:
	void shot()
	{
		cout<<"Tank T50 shot()"<<endl;
	}
	void run()
	{
		cout<<"Tank T50 run()"<<endl;
	}
public:
	virtual ~T50()
	{
		cout<<"In the destructor of T50"<<endl;
	}
};
//������T75
class T75:public Tank
{
public:
	void shot()
	{
		cout<<"Tank T75 shot()"<<endl;
	}
	void run()
	{
		cout<<"Tank T75 run()"<<endl;
	}
public:
	virtual ~T75()
	{
		cout<<"In the destructor of T75"<<endl;
	}
};

//�����࣬Decorator
class Decorator:public Tank
{
protected:
	Tank* tank;
public:
	Decorator(Tank* tank):tank(tank) {}  //�����̹�˵�װ����
	virtual ~Decorator()
	{
		cout<<"In the destructor of Decorator"<<endl;
	}
public:
	void shot()
	{
		tank->shot();
	}
	void run()
	{
		tank->run();
	}
};

class InfraredDecorator: public Decorator
{
private:
	string infrared;//�������ν��addAtrribute
public:
	InfraredDecorator(Tank* tank):Decorator(tank) {}
	virtual ~InfraredDecorator()
	{
		cout<<"in the destructor of InfraredDecorator"<<endl;
	}
public:
	void set_Infrared(const string &infrared)
	{
		this->infrared=infrared;
	}
	string get_infrared() const
	{
		return infrared;
	}
	void run()
	{
		tank->run();
		set_Infrared("+Infrared");
		cout<<get_infrared()<<endl;
	}
	void shot()
	{
		tank->shot();
	}
};

class AmphibianDecorator:public Decorator
{
private:
	string amphibian;
public:
	AmphibianDecorator(Tank* tank):Decorator(tank) {}
	~AmphibianDecorator()
	{
		cout<<"in the destructor of AmphibianDecorator"<<endl;
	}
public:
	void set_amphibian(const string &hibian)
	{
		this->amphibian=hibian;
	}
	string get_amphibian() const
	{
		return amphibian;
	}
public:
	void run()
	{
		tank->run();
		set_amphibian("+amphibian");
		cout<<get_amphibian()<<endl;
	}
	void shot()
	{
		tank->shot();
	}
};

int main(int argc, char **argv)
{
	//��T50���Ӻ��⹦��
	Tank* tank1(new T50);
	Tank* pid1(new InfraredDecorator(tank1));
	pid1->shot();
	cout<<endl;
	pid1->run();
	cout<<endl;
	cout<<endl<<"---------------"<<endl;
	//��t75���Ӻ��⡢���ܹ���
	Tank* tank2(new T75);
	tank2->run();
	Tank* pid2(new InfraredDecorator(tank2));
	Tank* pad2(new AmphibianDecorator(pid2));
	pad2->shot();
	cout<<endl;
	pad2->run();
	cout<<endl;
	cout<<endl<<"--------------"<<endl;

	//��̬��������װ�� ?
	tank2->run();

	Tank * tank3(tank2);
	tank3->run();

	system("pause");
	return 0;
}
