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
	/// ���������� ���������
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


		void close(); //������� ����
		void open(const QSerialPortInfo &portInfo); //������ ����
		bool isActive() const; //�������� ���� �������� ��� ���


	signals:
	
		void signal_readLine(QString data); //������ ������
		void signal_error(QString error); //������

	private:


		
		QSerialPortInfo	mPortInfo;

		
		bool			mActive; //�������� ����
		bool			mStopping; //����� ����������� ��������� �����
		QThread			*mThread; //����� � ������� ����� ���� ������

		QSharedPointer<ASerialPort>	mMain;

	private slots:

		void slot_run();//���������� ������
		void slot_error(QSerialPort::SerialPortError serialPortError);//������
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ASerialPort> PSerialPort;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

