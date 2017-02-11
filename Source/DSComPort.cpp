﻿#include "DSComPort.h"
#include <QVariant>
#include <QTime>
#include <QDateTime>

#include "DSComPortDialog.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace DataSource;
///--------------------------------------------------------------------------------------





///--------------------------------------------------------------------------------------
int gNumberComPort = 0;
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AComPort :: AComPort ()
	:
	mBeginMs(0),
	mLastTime(0)
{
	gNumberComPort++;
	mNumber = gNumberComPort;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AComPort :: ~AComPort ()
{
	clear();

	if (!mPort.isNull())
	{
		mPort->close();
	}

	if (!mWidget.isNull())
	{
		mWidget->close();
	}
}
///--------------------------------------------------------------------------------------










 ///=====================================================================================
///
/// возвратим имя источника данных
/// 
/// 
///--------------------------------------------------------------------------------------
QString AComPort :: title() const
{
	QString name = "NONE";
	if (mPortInfo.isValid())
	{
		name = mPortInfo.portName();
	}
	return "Com port - " + QString::number(mNumber) + " [" + name + "]";
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// покажем диалог информации по источнику данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: show()
{
	if (mWidget.isNull())
	{
		mWidget = PComPortDialog::create();
	}

	auto _this = qSharedPointerCast<AComPort>(sharedFromThis());
	mWidget->show(_this);
	//mWidget->show(PRandomGenerator());

}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ктоо подсоеденился
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: onConnect()
{
	refreshWidget();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ктото отсоединлся
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: onDisconnect()
{
	refreshWidget();
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// открытие данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool AComPort :: onOpen()
{
	mLastError = QString();
	if (mPort.isNull() || mPort->isActive())
	{
		if (!mPort.isNull())
		{
			mPort->close();
		}

		mPort = Utils::PSerialPort::create();
		connect(mPort.data(), &Utils::ASerialPort::signal_readLine, this, &AComPort::slot_readData);
		connect(mPort.data(), &Utils::ASerialPort::signal_error, this, &AComPort::slot_error);
	}

	mBeginMs = QDateTime::currentMSecsSinceEpoch();
	mLastTime = 0;

	mPort->open(mPortInfo);
	refreshWidget();
	return true;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// закрытие данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool AComPort :: onClose()
{
	if (!mPort.isNull())
	{
		mPort->close();
	}

	mLastTime = 0;
	refreshWidget();
	return true;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// обновление таймера
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: slot_readData(QString text)
{
	bool ok = false;
	const int val = text.toInt(&ok);
	if (!ok)
	{
		return;
	}

	const int timeMs = QDateTime::currentMSecsSinceEpoch() - mBeginMs;
	mLastTime = timeMs;

	QList<int> data;
	data.append(timeMs);
	data.append(val);
	streamData->command_dataSend(QVariant::fromValue<QList<int>>(data));
	
	refreshWidget();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ошибка
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: slot_error(QString error)
{
	mLastError += "\r" + error;
	show();
	close();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// возвратим интервал таймера
/// 
/// 
///--------------------------------------------------------------------------------------
QSerialPortInfo AComPort :: portInfo() const
{
	return mPortInfo;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// установим информацию по порту
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: setPortInfo(const QSerialPortInfo &info)
{
	mPortInfo = info;
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// возвратим последнее время
/// 
/// 
///--------------------------------------------------------------------------------------
int AComPort :: lastTimeMS() const
{
	return mLastTime;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// обновим виджет
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPort :: refreshWidget()
{
	if (!mWidget.isNull())
	{
		mWidget->refresh();
	}
}