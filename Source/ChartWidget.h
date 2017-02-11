#pragma once
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QScrollBar>
#include <QCheckBox>

#include "qcustomplot-source\qcustomplot.h"
#include "MarkingContainer.h"
#include "Mark.h"
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


		void append(const double time, const double data); //�������� ������ � �������
		void reset(); //������� ��� ������

		void setNameDataSource(const QString &caption); //��������� ������� �������� ���������

	private:

		Marking::PWMarkingContainer	mMarking; //��������

		double	mZoomFactor;
		bool	mAutoTrackerEnabled; //����, ��� ������� ������ ����������
		int		mMaxTime; //����� ������������
		bool	mTimeValueChanged; //��������� ��������� ���� ��������

		QSlider		*mScrollTime; //����� �����
		QTreeWidget *mTreeMarkings; //������������ �����
		QCheckBox	*mAutoTracker;	//������������� ����������� ������

		QCustomPlot *mPlot;			//���������
		QCustomPlot *mPlotTimer;	//��������� �����

		QCPGraph *mPlotGraph;	//�������� ������
		QCPGraph *mPlotGraphMark;	//��������

		void createUI(QWidget *parentWidget); //�������� ������� 


		QWidget* createMarking(); //�������� �������� �������
		QWidget* createCharts(); //�������� ��������

		void initPlot();


		void appendMark(const PMark &mark); //�������� ��������
		QTreeWidgetItem* findItemMark(const Marking::PWMarking &marking) const; //����� ��������  

	public slots:

		void slot_rangeChanged(const QCPRange &newRange);//��������� ��������

	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

