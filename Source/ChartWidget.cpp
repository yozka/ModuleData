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


	//тестовые значения
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
	mPlot = new QCustomPlot();

	return mPlot;
	/*
	//контент диаграммы
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
/// создание диаграмм
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget ::  initPlot()
{
	auto customPlot = mPlot;


	customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
    customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
   // customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
   // customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
   // customPlot->xAxis->setDateTimeFormat("hh:mm");  // Устанавливаем формат даты и времени
 
    // Настраиваем шрифт по осям координат
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 
    // Автоматическое масштабирование тиков по Оси X
    //customPlot->xAxis->setAutoTickStep(true);
 

    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
 
    customPlot->yAxis->setTickLabelColor(QColor(Qt::red)); // Красный цвет подписей тиков по Оси Y
    customPlot->legend->setVisible(true);   //Включаем Легенду графика
    // Устанавливаем Легенду в левый верхний угол графика
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
 


    // Инициализируем график и привязываем его к Осям
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


    /* Подключаем сигнал от Оси X об изменении видимого диапазона координат
     * к СЛОТу для переустановки формата времени оси.
     * */
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));
 
    customPlot->rescaleAxes();      // Масштабируем график по данным
    customPlot->replot();           // Отрисовываем график
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
	mTreeMarkings->clear();
	mPlotGraph->setData(QVector<qreal>(), QVector<qreal>());
	mPlotGraphMark->setData(QVector<qreal>(), QVector<qreal>());
	mPlot->rescaleAxes();
	mPlot->replot();
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

	mPlot->rescaleAxes();
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