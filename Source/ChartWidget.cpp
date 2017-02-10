#include "ChartWidget.h"
#include <QGroupBox>
#include <QApplication>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Chart;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChartWidget :: AChartWidget ()
	:
	mInfoTime(NULL),
	mInfoValue(NULL),
	mInfoDescription(NULL),
	mTreeMarkings(NULL),
	mPlot(NULL),
	mPlotTimer(NULL),
	mPlotGraph(NULL)
{
	createUI(this);


	//�������� ��������
	initPlot();
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChartWidget :: ~AChartWidget ()
{
	clear();

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ������� 
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: createUI(QWidget *parentWidget)
{
	auto contentLayout = new QVBoxLayout(parentWidget);
	contentLayout->setContentsMargins(6, 6, 6, 6);
	

	//��������
	auto *markingWidget = createMarking();
	contentLayout->addWidget(markingWidget);


	//��������
	auto *chartsWidget = createCharts();
	contentLayout->addWidget(chartsWidget);


	//�����������
	auto splitter = new QSplitter(Qt::Horizontal, parentWidget);
	splitter->addWidget(markingWidget);
	splitter->addWidget(chartsWidget);
	contentLayout->addWidget(splitter);

	auto sz = splitter->sizes();
	sz[0] = 100;
	sz[1] = 500;
	splitter->setSizes(sz);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ���������
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget*  AChartWidget :: createMarking() 
{
	auto *mainWidget = new QWidget();
	//mainWidget->setFixedHeight(120);
	auto mainLayout = new QVBoxLayout(mainWidget);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	//�������� ��������������� �����
	auto *infoBox = new QGroupBox(mainWidget);
	infoBox->setTitle(QApplication::translate("ChartWidget", "Marking", 0));
    infoBox->setFlat(true);
	//infoBox->setFixedSize(250, 100);
	infoBox->setFixedHeight(100);
	auto *label = new QLabel(infoBox);
 	label->setText(QApplication::translate("ChartWidget", "Time:", 0));
	label->setGeometry(QRect(0, 20, 70, 20));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

	label = new QLabel(infoBox);
    label->setText(QApplication::translate("ChartWidget", "Value:", 0));
	label->setGeometry(QRect(0, 40, 70, 20));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        
	label = new QLabel(infoBox);
    label->setText(QApplication::translate("ChartWidget", "Description:", 0));
    label->setGeometry(QRect(0, 60, 70, 20));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        
	mInfoTime = new QLabel(infoBox);
    mInfoTime->setGeometry(QRect(80, 20, 160, 20));
    mInfoTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
     
	mInfoValue = new QLabel(infoBox);
    mInfoValue->setGeometry(QRect(80, 40, 160, 20));
    mInfoValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

	mInfoDescription = new QLabel(infoBox);
    mInfoDescription->setGeometry(QRect(80, 60, 160, 20));
    mInfoDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
	//

	mainLayout->addWidget(infoBox);
	//---------------------------------------------------------


	mTreeMarkings = new QTreeWidget(mainWidget);
	mainLayout->addWidget(mTreeMarkings);


	return mainWidget;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget*  AChartWidget :: createCharts()
{
	mPlot = new QCustomPlot();

	return mPlot;
	/*
	//������� ���������
	auto charts = new QWidget();

	mPlot = new QCustomPlot(charts);
	mPlotTimer = new QCustomPlot(charts);

	auto splitter = new QSplitter(Qt::Vertical, charts);
	splitter->addWidget(mPlot);
	splitter->addWidget(mPlotTimer);
	

	auto layout = new QVBoxLayout(charts);
	layout->addWidget(mPlot);
	//layout->addWidget(splitter);
	layout->addWidget(mPlotTimer);

	return charts;*/
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget ::  initPlot()
{
	auto customPlot = mPlot;


	customPlot->setInteraction(QCP::iRangeZoom,true);   // �������� �������������� ��������/�����������
    customPlot->setInteraction(QCP::iRangeDrag, true);  // �������� �������������� �������������� �������
   // customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // �������� �������������� ������ �� �������������� ���
   // customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // �������� ��������/����������� ������ �� �������������� ���
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // ������� ��������� �� ��� X � �������� ���� � �������
   // customPlot->xAxis->setDateTimeFormat("hh:mm");  // ������������� ������ ���� � �������
 
    // ����������� ����� �� ���� ���������
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 
    // �������������� ��������������� ����� �� ��� X
    //customPlot->xAxis->setAutoTickStep(true);
 

    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
 
    customPlot->yAxis->setTickLabelColor(QColor(Qt::red)); // ������� ���� �������� ����� �� ��� Y
    customPlot->legend->setVisible(true);   //�������� ������� �������
    // ������������� ������� � ����� ������� ���� �������
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
 
    // �������������� ������ � ����������� ��� � ����
    mPlotGraph = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraph->setName("Data");
    mPlotGraph->setPen(QPen(QColor(Qt::red)));
    mPlotGraph->setAntialiased(true);
    mPlotGraph->setLineStyle(QCPGraph::lsImpulse); 
 


    /* ���������� ������ �� ��� X �� ��������� �������� ��������� ���������
     * � ����� ��� ������������� ������� ������� ���.
     * */
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));
 
    customPlot->rescaleAxes();      // ������������ ������ �� ������
    customPlot->replot();           // ������������ ������
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// ��������� ����������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: setMarking(const Marking::PMarkingContainer &marking)
{
	mMarking = marking;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ���� ������������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: clear()
{
	mMarking = Marking::PMarkingContainer();
	reset();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// ������� ��� ������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: reset()
{
	mPlotGraph->setData(QVector<qreal>(), QVector<qreal>());
	mPlot->rescaleAxes();
	mPlot->replot();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// �������� ������ � �������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: append(const double time, const double data)
{
	mPlotGraph->addData(time, data);
	mPlot->rescaleAxes();
	mPlot->replot();

	//������� �������
}
///--------------------------------------------------------------------------------------




