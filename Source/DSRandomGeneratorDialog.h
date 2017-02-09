#pragma once
#include <QObject>
#include <QWeakPointer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>




///--------------------------------------------------------------------------------------
#include "DSRandomGenerator.h"
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
	class ARandomGeneratorDialog
			: 
			public QDialog
	{
		Q_OBJECT

	public:
		ARandomGeneratorDialog();
		virtual ~ARandomGeneratorDialog();



		void show(const QWeakPointer<ARandomGenerator> &dataSource); //�������� ������
		void refresh(); //�������� ������



	private:

		QWeakPointer<ARandomGenerator>	mDataSource;	//������
		QLabel*				mStatus;		//������� ����������
		QLabel*				mCount;			//���������� ������������ ����������
		QLineEdit*			mInterval;		//��������

		void createUI(QWidget *form);//�������� �������

	private slots:

		void slot_editInterval(const QString &text); //��������� ������������� �������� ������
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ARandomGeneratorDialog> PRandomGeneratorDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

