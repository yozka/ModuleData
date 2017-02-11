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
	mTreeMarkings(nullptr),
	mPlot(nullptr),
	mPlotGraph(nullptr),
	mPlotGraphMark(nullptr),
	mAutoTracker(nullptr),
	mScrollTime(nullptr),
	mScrollTimeLabel(nullptr),
	mAutoTrackerEnabled(false),
	mZoomFactor(0),
	mTimeValueChanged(false),
	mRangeSetSkip(false),
	mTimeValueSkip(false)
{
	createUI(this);
	
	mMarkLabel = PMarkPlot::create();

	//тестовые значения
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
/// создание виджета 
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: createUI(QWidget *parentWidget)
{
	auto contentLayout = new QVBoxLayout(parentWidget);
	contentLayout->setContentsMargins(6, 6, 6, 6);
	

	//закладки
	auto *markingWidget = createMarking();
	contentLayout->addWidget(markingWidget);


	//диаграма
	auto *chartsWidget = createCharts();
	contentLayout->addWidget(chartsWidget);


	//разделитель
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
/// создание заголовка
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

	connect(mTreeMarkings, &QTreeWidget::currentItemChanged, this, &AChartWidget::slot_treeChanged);


	return mainWidget;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// создание диаграмм
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget*  AChartWidget :: createCharts()
{
	//контент диаграммы
	auto *content = new QWidget();
	auto *layout = new QVBoxLayout(content);

	auto *label = new QLabel(content);
	label->setText("test");
	label->setFixedHeight(20);
	layout->addWidget(label);

	mAutoTracker = new QCheckBox(content);
	mAutoTracker->setText("Auto tracker");
	layout->addWidget(mAutoTracker);

	///
	mPlot = new QCustomPlot(content);
	layout->addWidget(mPlot);
	///

	auto *line = new QFrame(content);
    line->setObjectName(QStringLiteral("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
	layout->addWidget(line);

	mScrollTimeLabel = new QLabel(content);
	mScrollTimeLabel->setText("Time:");
	mScrollTimeLabel->setFixedHeight(20);
	layout->addWidget(mScrollTimeLabel);


	mScrollTime = new QSlider(content);
	mScrollTime->setOrientation(Qt::Horizontal);
	mScrollTime->setFixedHeight(20);



	layout->addWidget(mScrollTime);


	connect(mPlot->xAxis, SIGNAL(rangeChanged(const QCPRange &)), this, SLOT(slot_rangeChanged(const QCPRange &)));


	connect(mScrollTime, &QSlider::valueChanged, this, &AChartWidget::slot_timeChanged);

//	bool bo = connect(mPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(slot_graphClicked(QCPAbstractPlottable*,int)));

	return content;
}
///--------------------------------------------------------------------------------------


void AChartWidget :: slot_graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
	int i = 0;
}


 ///=====================================================================================
///
/// изменение размеров
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: slot_rangeChanged(const QCPRange &newRange)
{
	if (!mAutoTrackerEnabled)
	{
		//размеры изменяет не автотрекер, поменяли фактор зумирования
		mZoomFactor = newRange.size();
		mAutoTracker->setChecked(false); //отключили автотрекер. иоо рамеры поменяли не автоматом
	}

	if (!mTimeValueSkip)
	{
		mRangeSetSkip = true;
		mScrollTime->setValue(newRange.center());
		mRangeSetSkip = false;
	}
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// изменение времени
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: slot_timeChanged(const int value)
{
	if (!mAutoTrackerEnabled)
	{
		mAutoTracker->setChecked(false); //отключили автотрекер. иоо рамеры поменяли не автоматом
	}
	mTimeValueChanged = true;

	if (!mRangeSetSkip)
	{
		mTimeValueSkip = true;
		mPlot->xAxis->setRange(value - (int)(mZoomFactor * 0.5f), mZoomFactor, Qt::AlignLeft);
		mTimeValueSkip = false;
		mPlot->replot();
	}

	refreshTimeLabel();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// обновление метки
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: refreshTimeLabel()
{
	int value = mScrollTime->value();
	if (value == mMaxTime)
	{
		mScrollTimeLabel->setText("Current time: " + ATimeTicker::timeToString(value));
	}
	else
	{
		mScrollTimeLabel->setText("Current time: " + ATimeTicker::timeToString(value) + " / " + ATimeTicker::timeToString(mMaxTime));
	}
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// установка действующих закладок
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
/// очистка всех зависемостей
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
/// удалить все данные
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: reset()
{
	mMarkLabel->destroy();

	mRangeSetSkip = true;
	mMaxTime = 0;
	mScrollTime->setMaximum(0);
    mScrollTime->setValue(0);
	mScrollTime->setSliderPosition(0);
	mScrollTime->setPageStep(0);
	
	
	mTreeMarkings->clear();
	mPlotGraph->setData(QVector<qreal>(), QVector<qreal>());
	mPlotGraphMark->setData(QVector<qreal>(), QVector<qreal>());

	mZoomFactor = 6000;
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
/// создание диаграмм
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget ::  initPlot()
{
	auto customPlot = mPlot;


	//интерактив
	customPlot->setInteraction(QCP::iRangeZoom, true);
    customPlot->setInteraction(QCP::iRangeDrag, true);
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal);
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal);

	customPlot->setInteraction(QCP::iSelectPlottables, true);

	QSharedPointer<ATimeTicker> timeTicker(new ATimeTicker);
	customPlot->xAxis->setTicker(timeTicker);


    //шрифт по осям
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 

    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
 


	customPlot->yAxis->setTickLabelColor(QColor(Qt::darkGreen)); 
    customPlot->legend->setVisible(true);   //Включаем Легенду графика
    // Устанавливаем Легенду в левый верхний угол графика
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
 


    //график с данными
	QColor color(66, 134, 244, 200);
    QPen penData;
	penData.setColor(color);
	penData.setWidthF(10);
	
	mPlotGraph = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraph->setName("Data");
    mPlotGraph->setPen(penData);
    mPlotGraph->setAntialiased(true);
    mPlotGraph->setLineStyle(QCPGraph::lsImpulse); 
	mPlotGraph->setSelectable(QCP::stNone);
	//


	QPen penMark;
	penMark.setColor(QColor(255, 181, 50, 250));


	mPlotGraphMark = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
	mPlotGraphMark->setName("Marking");
	mPlotGraphMark->setPen(penMark);
    mPlotGraphMark->setLineStyle(QCPGraph::lsNone); 
	mPlotGraphMark->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 15));

	mPlotGraphMark->setSelectable(QCP::stDataRange);

	//bool bo = connect(mPlotGraphMark,	SIGNAL(selectionChanged(const QCPDataSelection &)), this, SLOT(slot_selectionChanged(const QCPDataSelection)));

	bool bo = connect(customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(slot_graphClicked(QCPAbstractPlottable*,int)));
	
   // connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));



	customPlot->rescaleAxes();      // Масштабируем график по данным
    customPlot->replot();           // Отрисовываем график
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// добавить данные в виджеты
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: append(const double time, const double data)
{

	mPlotGraph->addData(time, data);


	//добавим маркеты
	if (mMarking.isNull())
	{
		return;
	}
	Marking::PWMarking marking = mMarking.data()->find(data);
	if (!marking.isNull())
	{
		auto mark = PMark(new AMark(time, data, marking)); 
		appendMark(mark);

		//добавим к шкале
		mPlotGraphMark->addData(time, data);

		//добавим лабел автоматом
		if (mAutoTracker->isChecked())
		{
			mMarkLabel->createLabel(mark, mPlot);
		}
	}
	//--------------------------------------------------

	//время
	int max = time;
	if (max > mMaxTime)
	{
		mMaxTime = max;
		mScrollTime->setMaximum(mMaxTime);
	}
	mTimeValueChanged = false;
	//
	
	//график
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
		if (!mTimeValueChanged)
		{
			mRangeSetSkip = true;
			int timeVal = time - mZoomFactor * 0.5f;
			if (timeVal < 0)
			{
				timeVal = time;
			}
			mScrollTime->setValue(timeVal);
			mRangeSetSkip = false;
		}
		mAutoTrackerEnabled = false;
	}
	else
	{
		refreshTimeLabel();
	}
	mPlot->replot();

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// //добавить закладки
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: appendMark(const PMark &mark)
{

	//добавляем закладкку в дерево
	auto *top = findItemMark(mark->marking());
	

	if (top == nullptr)
	{
		//создадим закладку, ибо ее нет
		top = new QTreeWidgetItem(mTreeMarkings);
		top->setData(0, Qt::UserRole, qVariantFromValue<PMark>(PMark(new AMark(mark->marking()))));
		top->setText(0, mark->description());

		mTreeMarkings->insertTopLevelItem(0, top);
	}


	//добавим  к закладке данные
	QStringList captions;
	captions << QString();
	captions << mark->timeToString();
	captions << mark->valueToString();
	auto *item = new QTreeWidgetItem(captions);
	item->setData(0, Qt::UserRole, qVariantFromValue<PMark>(mark));

	top->addChild(item);

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// поиск закладок
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
/// изменили текущую выбор элемента в дереве меток
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: slot_treeChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous)
{
	if (current == nullptr)
	{
		showMark(PMark());
		return;
	}
	const auto markVariant = current->data(0, Qt::UserRole);
	const auto mark = qSharedPointerFromVariant<AMark>(markVariant);
	if (mark.isNull() || mark->isRoot())
	{
		showMark(PMark());
		return;
	}
	showMark(mark);
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// показать закладку на графике и других контролах
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: showMark(const PMark &mark)
{
	mMarkLabel->destroy();
	if (mark.isNull())
	{
		//убрать надписи
		return;
	}
	mAutoTracker->setChecked(false);
	mScrollTime->setValue(mark->time());
	mMarkLabel->createLabel(mark, mPlot);
	
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// установим текущее название источника
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: setNameDataSource(const QString &caption)
{
	mPlotGraph->setName(caption);
	mPlot->replot();
}