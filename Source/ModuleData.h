#pragma once
#include <QMainWindow>
#include "ui_ModuleData.h"
///--------------------------------------------------------------------------------------


#include "MarkingContainer.h"
#include "MarkingEditorDialog.h"
#include "DataSourceContainer.h"
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// �������� ����
/// 
/// 
///--------------------------------------------------------------------------------------
class AModuleData 
		: 
			public QMainWindow
{
	Q_OBJECT

public:
	AModuleData(QWidget *parent = 0);
	virtual ~AModuleData();



private:
	Ui::AModuleDataClass				ui;

	Marking::PMarkingContainer			mMarkings;		//�����
	Marking::PMarkingEditorDialog		mMarkingEditor; //�������� �����

	DataSource::PDataSourceContainer	mData;			//����� ������� �������� �����

private slots:

	//EDIT
	void on_actionMarking_triggered(); //�������������� ����������� �������� �������

	//DATA
	void on_actionRandomGenerator_triggered(); //���������� ���������� ��������� �����
	void slot_refreshDataSource(); //���������� ��������� ������
};


