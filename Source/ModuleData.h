#pragma once
#include <QMainWindow>
#include "ui_ModuleData.h"
///--------------------------------------------------------------------------------------


#include "MarkingContainer.h"
#include "MarkingEditorDialog.h"
#include "DataSourceContainer.h"
#include "ChartContainer.h"
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
	Chart::PChartContainer				mChart;			//��������

private slots:

	//CHART
	void on_actionMarking_triggered();	//�������������� ����������� �������� �������
	void on_actionChartNew_triggered(); //���������� ����� ��������
	void slot_refreshChart();			//���������� �������, ��������� ��������� ��������

	//DATA
	void on_actionRandomGenerator_triggered(); //���������� ���������� ��������� �����
	void slot_refreshDataSource(); //���������� ��������� ������
};


