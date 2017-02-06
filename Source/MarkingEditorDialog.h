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
	/// ��������� �����
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



		void show(PMarkingContainer markings); //�������� ������ ��������������
		void refresh(); //�������� ������

	private:

		PMarkingContainer	mMarkings; //������, � �������
		QTableWidget*		mViews;



		void createUI(QWidget *form);//�������� �������

	private slots:

		void slot_add(); //������ ������ ��������
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarkingEditorDialog> PMarkingEditorDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

