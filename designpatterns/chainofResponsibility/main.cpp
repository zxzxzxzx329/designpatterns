#include "chain.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	DM* pDM = new DM(NULL);//���ž���
	PS* pPS= new PS(pDM);//��������
	PM* pPM = new PM(pPS);//��Ŀ����
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
