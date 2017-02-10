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
	/// Контейнер меток
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



		void show(const QWeakPointer<AManualControl> &dataSource); //показать диалог
		void refresh(); //обновить данные



	private:

		QWeakPointer<AManualControl>	mDataSource;	//данные
		QLabel*				mStatus;		//статуст генератора
		QLabel*				mCount;			//количество подцепленных приемников
		QLineEdit*			mInterval;		//интервал
		
		QLabel*				mDataCurrent;	//текущие данные
		QSlider*			mData;			//данные

		void createUI(QWidget *form);//создание диалога

	private slots:

		void slot_editData(int value); //завершили редактировать интервал данных
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AManualControlDialog> PManualControlDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

