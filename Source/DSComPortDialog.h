#pragma once
#include <QObject>
#include <QWeakPointer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>




///--------------------------------------------------------------------------------------
#include "DSComPort.h"
///--------------------------------------------------------------------------------------


namespace DataSource
{
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// ������ ��������� ���������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AComPortDialog
			: 
			public QDialog
	{
		Q_OBJECT

	public:
		AComPortDialog();
		virtual ~AComPortDialog();



		void show(const QWeakPointer<AComPort> &dataSource); //�������� ������
		void refresh(); //�������� ������



	private:

		QWeakPointer<AComPort>	mDataSource;	//������
		QLabel*					mStatus;		//������� ����������
		QLabel*					mCount;			//���������� ������������ ����������
		QComboBox*				mBoxPort;		//�����


		QList<QSerialPortInfo> mPorts;		//�������� �����

		void createUI(QWidget *form);//�������� �������

	private slots:

		void slot_portChanged(int index); //��������� ������������� �������� ������
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AComPortDialog> PComPortDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

