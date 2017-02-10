#pragma once
#include <QObject>
#include <QWeakPointer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>




///--------------------------------------------------------------------------------------
#include "DSManualControl.h"
///--------------------------------------------------------------------------------------


namespace DataSource
{
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// ��������� �����
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AManualControlDialog
			: 
			public QDialog
	{
		Q_OBJECT

	public:
		AManualControlDialog();
		virtual ~AManualControlDialog();



		void show(const QWeakPointer<AManualControl> &dataSource); //�������� ������
		void refresh(); //�������� ������



	private:

		QWeakPointer<AManualControl>	mDataSource;	//������
		QLabel*				mStatus;		//������� ����������
		QLabel*				mCount;			//���������� ������������ ����������
		QLineEdit*			mInterval;		//��������
		
		QLabel*				mDataCurrent;	//������� ������
		QSlider*			mData;			//������

		void createUI(QWidget *form);//�������� �������

	private slots:

		void slot_editData(int value); //��������� ������������� �������� ������
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AManualControlDialog> PManualControlDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

