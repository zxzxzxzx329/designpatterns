#include "observer.h"
int main()
{
	//Ŀ��(���۲���)
	CBloger* pBloger = new CBloger();
	CPortal* pPortal = new CPortal();
	//�۲���. һ���۲��߿��Թ۲���Ŀ��
	CRSSReader* pRssReader = new CRSSReader("rss reader");
	CMailReader* pMailReader = new CMailReader("mail reader");
	pBloger->Attach(pRssReader);  //blogerע��۲���
	pBloger->Attach(pMailReader); //blogerע��۲���
	pPortal->Attach(pRssReader);  //portalע��۲���
	pPortal->Attach(pMailReader); //portalע��۲���
	//���ͷ�����Ϣ
	pBloger->Publish("���ͷ������ģʽ");
	cout << endl;
	//�Ż�������Ϣ
	pPortal->Publish("�Ż��������ģʽ");
	cout << "\nportal detached mail reader" << endl;

	pPortal->Detach(pMailReader);

	cout << "portal observers count: " << pPortal->GetObserversCount() << endl << endl;
	pPortal->Publish("�Ż��������ģʽ");

	system("pause");
	return 0;
}