#pragma once
#include <QObject>
#include <QWeakPointer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>




///--------------------------------------------------------------------------------------
#include "DSComPort.h"
///--------------------------------------------------------------------------------------


namespace DataSource
{
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// диалог настройки компаорта
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



		void show(const QWeakPointer<AComPort> &dataSource); //показать диалог
		void refresh(); //обновить данные



	private:

		QWeakPointer<AComPort>	mDataSource;	//данные
		QLabel*				mStatus;		//статуст генератора
		QLabel*				mCount;			//количество подцепленных приемников
		QLineEdit*			mInterval;		//интервал

		void createUI(QWidget *form);//создание диалога

	private slots:

		void slot_editInterval(const QString &text); //завершили редактировать интервал данных
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AComPortDialog> PComPortDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

