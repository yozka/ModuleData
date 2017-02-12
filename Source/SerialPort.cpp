#include "SerialPort.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Utils;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ASerialPort :: ASerialPort ()
	:
	mActive(false),
	mStopping(false),
	mThread(nullptr)
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ASerialPort :: ~ASerialPort ()
{


}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// проверка порт активный или нет
/// 
/// 
///--------------------------------------------------------------------------------------
bool ASerialPort :: isActive() const
{
	return mActive;
}
///--------------------------------------------------------------------------------------









 ///=====================================================================================
///
/// закрыть порт
/// 
/// 
///--------------------------------------------------------------------------------------
void ASerialPort :: close()
{
	mStopping = true;
	if (mActive && mThread != nullptr)
	{
		mThread->wait(1000);
	}
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// открыть порт
/// 
/// 
///--------------------------------------------------------------------------------------
void ASerialPort :: open(const QSerialPortInfo &portInfo)
{
	if (mActive)
	{
		return;
	}

	mMain = sharedFromThis(); 

	mActive = true;
	mStopping = false;
	mPortInfo = portInfo;
	
	mThread = new QThread();
	moveToThread(mThread);
	connect(mThread, &QThread::started, this, &ASerialPort::slot_run);
	mThread->start();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// выполнение потока
/// 
/// 
///--------------------------------------------------------------------------------------
void ASerialPort :: slot_run()
{
	auto *port = new QSerialPort(mPortInfo);
	const bool open = port->open(QIODevice::ReadOnly);
	if (!open)
	{
		auto error = port->errorString();
		emit signal_error(error);
	}


	connect(port, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(slot_error(QSerialPort::SerialPortError)));

	mStopping = !open;
	while (!mStopping)
	{
		if (!port->waitForReadyRead(1000))
		{
			continue;
		}
		QByteArray requestData = port->readLine();
		//----
		QString dataCmd = QString::fromLocal8Bit(requestData);
		emit signal_readLine(dataCmd);
	}
	port->close();
	delete port;
	mMain = PSerialPort();
	mThread->quit();
	mActive = false;

	//delete mThread;
	mThread = nullptr;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ошибка данных
/// 
/// 
///--------------------------------------------------------------------------------------
void ASerialPort :: slot_error(QSerialPort::SerialPortError serialPortError)
{
	QString er = "Error port";
	emit signal_error(er);
}

///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// поиск меток, по данным
/// 
/// 
///--------------------------------------------------------------------------------------
/*
PMarking ASerialPort :: find(const int data) const
{
	for (auto item = mMarkings.constBegin(); item != mMarkings.constEnd(); ++item)
	{
		const auto mark = *item;
		if (mark->isCheck(data))
		{
			return mark;
		}
	}
	return PMarking();
}
*/