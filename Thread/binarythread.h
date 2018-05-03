
/*
*ͼ���ֵ���������߳���
*��AutoNeuronGPS��û��
*Ŀ�����ڶ�ֵ����ͬʱ������ʹ�ô��ڼ���
*
*���ߣ��ܺ�
*ʱ�䣺2013-8-26
*�人���ҹ��ʵ����
*/

#ifndef BINARYTHREAD_H
#define BINARYTHREAD_H
#include <QThread>
#include <memory>
#include "../Function/ineuronprocessobject.h"

class BinaryThread : public QThread
{
	Q_OBJECT
public:
	BinaryThread(QObject *parent);
	~BinaryThread();
    void setParam(INeuronProcessPointer);
	void stop();
    ProcStatPointer RetVal()const{ return retVal; }

protected:
	void run();

signals:

private:
	volatile bool stopped;//no use
	///--------------data------------------------------
	bool			isInit;//
    INeuronProcessPointer filter;
	//run status----//
    ProcStatPointer retVal;
};

#endif