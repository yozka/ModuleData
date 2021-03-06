﻿#pragma once
#include <QSharedPointer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "DataSource.h"
#include "SerialPort.h"
///--------------------------------------------------------------------------------------

namespace DataSource
{
	///--------------------------------------------------------------------------------------








	///--------------------------------------------------------------------------------------
	class AComPortDialog;
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// Источник данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AComPort
			: 
				public ADataSource
	{
		Q_OBJECT

	public:
		AComPort();
		

		virtual ~AComPort();


		QString	title() const override; //возвратим имя источника данных
		void	show() override; //покажем диалог информации по источнику данных

		QSerialPortInfo portInfo() const; //возвратим текущий порт
		void setPortInfo(const QSerialPortInfo &info); //установим информацию по порту

		int lastTimeMS() const; //возвратим последнее время

		QStringList lastError() const; //последняя ошибка
	protected:
		
		bool onOpen() override;		//открытие данных
		bool onClose() override;	//закрытие данных
		void onConnect() override;	//ктоо подсоеденился
		void onDisconnect() override;//ктото отсоединлся
		
	private:

		int		mNumber; //номер генератора

		QSerialPortInfo		mPortInfo;
		//Utils::PSerialPort	mPort;
		QSerialPort*		mSerial;

		QStringList			mLastError;

		qint64	mBeginMs; //время, начальный отчет
		int		mLastTime; //последие значения времени в милисикундах

		void	slot_error(QString error); //ошибка

		QSharedPointer<AComPortDialog> mWidget;


		void refreshWidget();//обновим виджет


	
	private slots:
		void	slot_readData(QString text); //обновление таймера
		void	slot_readDataNativ(); //чтение данных
		void	slot_errorNativ(QSerialPort::SerialPortError serialPortError);//ошибка

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AComPort> PComPort;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

