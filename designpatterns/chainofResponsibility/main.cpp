#include "chain.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	DM* pDM = new DM(NULL);//部门经理
	PS* pPS= new PS(pDM);//部门主管
	PM* pPM = new PM(pPS);//项目经理
	HolidayRequest* Prequest = new HolidayRequest(10);
	pPM->HandleRequest(Prequest);
	delete Prequest;

	Prequest = new HolidayRequest(2);
	pPM->HandleRequest(Prequest);
	delete pDM;
	delete pPS;
	delete pPM;
	delete Prequest;

	system("pause");
	return 0;

}
