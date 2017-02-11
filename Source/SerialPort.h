#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QEnableSharedFromThis>
///--------------------------------------------------------------------------------------

namespace Utils
{
	///--------------------------------------------------------------------------------------




	

	 ///=====================================================================================
	///
	/// реализация компортов
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ASerialPort
			: 
				public QObject,
				public QEnableSharedFromThis<ASerialPort>
	
	{
		Q_OBJECT

	public:
		ASerialPort();
		virtual ~ASerialPort();


		void close(); //закрыть порт
		void open(const QSerialPortInfo &portInfo); //откыть порт
		bool isActive() const; //проверка порт активный или нет


	signals:
	
		void signal_readLine(QString data); //пришли данные
		void signal_error(QString error); //ошибки

	private:


		
		QSerialPortInfo	mPortInfo;

		
		bool			mActive; //активный порт
		bool			mStopping; //нужно остановится выполнять поток
		QThread			*mThread; //поток в котором будет идти работа

		QSharedPointer<ASerialPort>	mMain;

	private slots:

		void slot_run();//выполнение потока
		void slot_error(QSerialPort::SerialPortError serialPortError);//ошибка
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ASerialPort> PSerialPort;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

