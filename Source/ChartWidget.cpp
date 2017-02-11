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
	mScrollTime->setValue(newRange.center());
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
		top->setData(0, Qt::UserRole, qVariantFromValue<PMark>(mark));
		top->setText(0, mark->description());

		mTreeMarkings->insertTopLevelItem(0, top);
	}


	//добавим  к закладке данные
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
/// установим текущее название источника
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: setNameDataSource(const QString &caption)
{
	mPlotGraph->setName(caption);
	mPlot->replot();
}