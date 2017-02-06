#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QDialog>
#include <QTableWidget>




///--------------------------------------------------------------------------------------
#include "MarkingContainer.h"
///--------------------------------------------------------------------------------------


namespace Marking
{
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// Контейнер меток
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AMarkingEditorDialog
			: 
			public QDialog
	{
		Q_OBJECT

	public:
		AMarkingEditorDialog();
		virtual ~AMarkingEditorDialog();



		void show(PMarkingContainer markings); //показать диалог редактирования
		void refresh(); //обновить данные

	private:

		PMarkingContainer	mMarkings; //данные, с метками
		QTableWidget*		mViews;



		void createUI(QWidget *form);//создание диалога

	private slots:

		void slot_add(); //нажали кнопку добавить
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarkingEditorDialog> PMarkingEditorDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

