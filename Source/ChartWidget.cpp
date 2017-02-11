#include "ChartWidget.h"
#include "TimeTicker.h"

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
	mPlotGraph(NULL),
	mAutoTrackerEnabled(false),
	mZoomFactor(0)
{
	createUI(this);


	//�������� ��������
	initPlot();
	reset();
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
	//������� ���������
	auto *content = new QWidget();
	auto *layout = new QVBoxLayout(content);

	auto *label = new QLabel(content);
	label->setText("test");
	label->setFixedHeight(20);
	layout->addWidget(label);

	mAutoTracker = new QCheckBox(content);
	mAutoTracker->setText("Auto tracker");
	layout->addWidget(mAutoTracker);


	mPlot = new QCustomPlot(content);
	layout->addWidget(mPlot);


	mScrollTime = new QSlider(content);
	mScrollTime->setOrientation(Qt::Horizontal);
	mScrollTime->setFixedHeight(20);



	layout->addWidget(mScrollTime);


	connect(mPlot->xAxis, SIGNAL(rangeChanged(const QCPRange &)), this, SLOT(slot_rangeChanged(const QCPRange &)));

	



	return content;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// ��������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: slot_rangeChanged(const QCPRange &newRange)
{
	if (!mAutoTrackerEnabled)
	{
		//������� �������� �� ����������, �������� ������ �����������
		mZoomFactor = newRange.size();
		mAutoTracker->setChecked(false); //��������� ����������. ��� ������ �������� �� ���������
	}
	mScrollTime->setValue(newRange.center());
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
	mMaxTime = 0;
	mScrollTime->setMaximum(0);
    mScrollTime->setValue(0);
	mScrollTime->setSliderPosition(0);
	mScrollTime->setPageStep(0);
	
	
	mTreeMarkings->clear();
	mPlotGraph->setData(QVector<qreal>(), QVector<qreal>());
	mPlotGraphMark->setData(QVector<qreal>(), QVector<qreal>());

	mZoomFactor = 17000;
	mAutoTrackerEnabled = true;
	mPlot->xAxis->setRange(0, mZoomFactor, Qt::AlignLeft);
	mAutoTrackerEnabled = false;
	mAutoTracker->setChecked(true);

	mPlot->rescaleAxes();
	mPlot->replot();
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


	//����������
	customPlot->setInteraction(QCP::iRangeZoom, true);
    customPlot->setInteraction(QCP::iRangeDrag, true);
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal);
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal);
   

	QSharedPointer<ATimeTicker> timeTicker(new ATimeTicker);
	customPlot->xAxis->setTicker(timeTicker);


    //����� �� ����
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 

    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
 


	customPlot->yAxis->setTickLabelColor(QColor(Qt::darkGreen)); 
    customPlot->legend->setVisible(true);   //�������� ������� �������
    // ������������� ������� � ����� ������� ���� �������
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
 


    //������ � �������
    QPen penData;
	penData.setColor(QColor(30, 40, 255, 150));
	penData.setWidthF(10);
	
	mPlotGraph = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraph->setName("Data");
    mPlotGraph->setPen(penData);
    mPlotGraph->setAntialiased(true);
    mPlotGraph->setLineStyle(QCPGraph::lsImpulse); 
	//


	QPen penMark;
	penMark.setColor(QColor(200, 0, 0, 255));
	penMark.setWidthF(5);

	mPlotGraphMark = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraphMark->setName("Marking");
	mPlotGraphMark->setPen(penMark);
    mPlotGraphMark->setLineStyle(QCPGraph::lsNone); 
	mPlotGraphMark->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));


    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));



	customPlot->rescaleAxes();      // ������������ ������ �� ������
    customPlot->replot();           // ������������ ������
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

	int max = time;
	if (max > mMaxTime)
	{
		mMaxTime = max;
		mScrollTime->setMaximum(mMaxTime);
	}
	mTimeValueChanged = false;

	
	mPlot->yAxis->rescale();

	if (mAutoTracker->isChecked())
	{
		const double size = mZoomFactor;
		double start = time - size;
		if (start < 0)
		{
			start = 0;
		}
		mAutoTrackerEnabled = true;
		mPlot->xAxis->setRange(start, size * 1.1f, Qt::AlignLeft);
		mAutoTrackerEnabled = false;
	}

	mPlot->replot();

	if (!mTimeValueChanged)
	{
		mScrollTime->setValue();
	}
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