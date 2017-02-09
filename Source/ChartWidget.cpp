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
	mPlotTimer(NULL)
{
	createUI(this);


	//�������� ��������
	test();
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

	//�������� �������
	auto contentWidget = new QWidget();
	auto contentLayout = new QHBoxLayout(contentWidget);
	contentLayout->setContentsMargins(0, 0, 0, 0);

	//����� ������������� ������
	mTreeMarkings = new QTreeWidget();
	contentLayout->addWidget(mTreeMarkings);
	
	auto chartsWidget = createCharts();
	contentLayout->addWidget(chartsWidget);


	//�����������
	auto splitterContent = new QSplitter(Qt::Horizontal, contentWidget);
	splitterContent->addWidget(mTreeMarkings);
	splitterContent->addWidget(chartsWidget);
	contentLayout->addWidget(splitterContent);

	

	//������������ ������ ��������
	//����� �������,
	auto firstLayout = new QVBoxLayout(parentWidget);
	firstLayout->setContentsMargins(6, 6, 6, 6);
	firstLayout->addWidget(createHeader()); //���������
	firstLayout->addWidget(contentWidget);

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// �������� ���������
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget*  AChartWidget :: createHeader() 
{
	auto headerWidget = new QWidget();
	headerWidget->setFixedHeight(120);
	auto headerLayout = new QHBoxLayout(headerWidget);
	headerLayout->setContentsMargins(0, 0, 0, 0);

	//�������� ��������������� �����
	auto infoBox = new QGroupBox(headerWidget);
	infoBox->setTitle(QApplication::translate("ChartWidget", "Information", 0));
    infoBox->setFlat(false);
	infoBox->setFixedSize(250, 100);
    auto label = new QLabel(infoBox);
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

	headerLayout->addWidget(infoBox);
	headerLayout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	//---------------------------------------------------------


	return headerWidget;
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


void AChartWidget ::  test()
{
	auto customPlot = mPlot;


	customPlot->setInteraction(QCP::iRangeZoom,true);   // �������� �������������� ��������/�����������
    customPlot->setInteraction(QCP::iRangeDrag, true);  // �������� �������������� �������������� �������
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // �������� �������������� ������ �� �������������� ���
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // �������� ��������/����������� ������ �� �������������� ���
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // ������� ��������� �� ��� X � �������� ���� � �������
   // customPlot->xAxis->setDateTimeFormat("hh:mm");  // ������������� ������ ���� � �������
 
    // ����������� ����� �� ���� ���������
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 
    // �������������� ��������������� ����� �� ��� X
    //customPlot->xAxis->setAutoTickStep(true);
 
    /* ������ �������� ��� X � Y �� ������� � ������ �������� �������,
     * �� ��������� �� ��� ���� � ������� ���������
     * */
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
    auto graphic = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);

	graphic->setName("�����, �");       // �������������
    graphic->setPen(QPen(QColor(Qt::red))); // ������������� ���� �������
    graphic->setAntialiased(false);         // ��������� �����������, �� ��������� ��������
    graphic->setLineStyle(QCPGraph::lsImpulse); // ������ � ���� ���������� �����
 
    /* ���������� ������ �� ��� X �� ��������� �������� ��������� ���������
     * � ����� ��� ������������� ������� ������� ���.
     * */
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));
 
    // ����� ������� ������ � ������������ ��� � ������� ������� � �������
    double now = QDateTime::currentDateTime().toTime_t();
    // ��������� ������� ������� � �������
    QVector <double> time(400);
	QVector <double> income(400);
 
    srand(15); // �������������� ��������� ��������������� �����
 
    // ��������� ������ ����������
	income[0] = 0;
    for (int i= 1; i<400; ++i)
      {
        time[i] = now + 3600*i;
        income[i] = qFabs(income[i-1]) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
 
    graphic->setData(time, income); // ������������� ������
    customPlot->rescaleAxes();      // ������������ ������ �� ������
    customPlot->replot();           // ������������ ������

}







 ///=====================================================================================
///
/// ������� ���� ������������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: clear()
{
	mMarking = Marking::PMarkingContainer();
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
/// ���������� �������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: refresh(const QVector<int> &data)
{


}