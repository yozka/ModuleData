#pragma once
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "qcustomplot-source\qcustomplot.h"
#include "MarkingContainer.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// �������� ������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChartWidget
			: 
				public QWidget
	{
		Q_OBJECT

	public:
		AChartWidget();
		virtual ~AChartWidget();

		void clear(); //������� ���� ������������
		void setMarking(const Marking::PWMarkingContainer &marking); //��������� ����������� ��������



		//void refresh(const QVector<int> &data); //���������� �������
		void append(const double time, const double data); //�������� ������ � �������
		void reset(); //������� ��� ������
	private:

		Marking::PWMarkingContainer	mMarking; //��������


		//�������������� ��������
		QLabel *mInfoTime;
		QLabel *mInfoValue;
		QLabel *mInfoDescription;

		QTreeWidget *mTreeMarkings; //������������ �����

		QCustomPlot *mPlot; //���������
		QCustomPlot *mPlotTimer; //��������� �����

		QCPGraph *mPlotGraph; //�������� ������


		void createUI(QWidget *parentWidget); //�������� ������� 


		QWidget* createMarking(); //�������� �������� �������
		QWidget* createCharts(); //�������� ��������

		void initPlot();

		void appendMark(const double time, const double data, const Marking::PWMarking &mark); //�������� ��������

		QTreeWidgetItem* findItemMark(const Marking::PWMarking &mark) const; //����� ��������  

	public slots:


	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

