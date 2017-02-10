#include "ChartWidget.h"
#include <QGroupBox>
#include <QApplication>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QVariant>
#include <QSharedPointer>
#include <QWeakPointer>
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
	sz[0] = 250;
	sz[1] = 600;
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
	auto mainLayout = new QVBoxLayout(mainWidget);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	auto *label = new QLabel(mainWidget);
	label->setText(QApplication::translate("ChartWidget", "Marking", 0));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	mainLayout->addWidget(label);

	mTreeMarkings = new QTreeWidget(mainWidget);
	
	auto *header = new QTreeWidgetItem();
    header->setText(0, QStringLiteral("Name"));
    header->setText(1, QStringLiteral("Time"));
	header->setText(2, QStringLiteral("Value"));
    mTreeMarkings->setHeaderItem(header);
	
	
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
 


	mPlotGraphMark = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraphMark->setName("Marking");
	mPlotGraphMark->setPen(QPen(QColor(Qt::blue)));
    mPlotGraphMark->setLineStyle(QCPGraph::lsNone); 
	mPlotGraphMark->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 6));


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
void AChartWidget :: setMarking(const Marking::PWMarkingContainer &marking)
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
	mMarking = Marking::PWMarkingContainer();
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
	mTreeMarkings->clear();
	mPlotGraph->setData(QVector<qreal>(), QVector<qreal>());
	mPlotGraphMark->setData(QVector<qreal>(), QVector<qreal>());
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


	//������� �������
	if (mMarking.isNull())
	{
		return;
	}
	Marking::PWMarking marking = mMarking.data()->find(data);
	if (!marking.isNull())
	{
		auto mark = PMark(new AMark(time, data, marking)); 
		appendMark(mark);

		//������� � �����
		mPlotGraphMark->addData(time, data);
	}

	mPlot->rescaleAxes();
	mPlot->replot();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// //�������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: appendMark(const PMark &mark)
{

	//��������� ��������� � ������
	auto *top = findItemMark(mark->marking());
	

	if (top == nullptr)
	{
		//�������� ��������, ��� �� ���
		top = new QTreeWidgetItem(mTreeMarkings);
		top->setData(0, Qt::UserRole, qVariantFromValue<PMark>(mark));
		top->setText(0, mark->description());

		mTreeMarkings->insertTopLevelItem(0, top);
	}


	//�������  � �������� ������
	QStringList captions;
	captions << QString();
	captions << mark->time();
	captions << mark->value();
	auto *item = new QTreeWidgetItem(captions);
	item->setData(0, Qt::UserRole, qVariantFromValue<PMark>(mark));

	top->addChild(item);

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ����� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
QTreeWidgetItem* AChartWidget :: findItemMark(const Marking::PWMarking &marking) const
{
	const int count = mTreeMarkings->topLevelItemCount();
	for (int i = 0; i < count; i++)
	{
		auto *item = mTreeMarkings->topLevelItem(i);
		const auto markVariant = item->data(0, Qt::UserRole);
		const auto mark = qSharedPointerFromVariant<AMark>(markVariant);
		if (mark.isNull())
		{
			continue;
		}

		if (mark->marking() == marking)
		{
			return item;
		}
	}
	return nullptr;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ��������� ������� �������� ���������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: setNameDataSource(const QString &caption)
{
	mPlotGraph->setName(caption);
	mPlot->replot();
}