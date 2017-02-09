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


	//тестовые значения
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
/// создание виджета 
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: createUI(QWidget *parentWidget)
{

	//основной контент
	auto contentWidget = new QWidget();
	auto contentLayout = new QHBoxLayout(contentWidget);
	contentLayout->setContentsMargins(0, 0, 0, 0);

	//слева распологается дерево
	mTreeMarkings = new QTreeWidget();
	contentLayout->addWidget(mTreeMarkings);
	
	auto chartsWidget = createCharts();
	contentLayout->addWidget(chartsWidget);


	//разделитель
	auto splitterContent = new QSplitter(Qt::Horizontal, contentWidget);
	splitterContent->addWidget(mTreeMarkings);
	splitterContent->addWidget(chartsWidget);
	contentLayout->addWidget(splitterContent);

	

	//формирование общего контента
	//общий контент,
	auto firstLayout = new QVBoxLayout(parentWidget);
	firstLayout->setContentsMargins(6, 6, 6, 6);
	firstLayout->addWidget(createHeader()); //заголовок
	firstLayout->addWidget(contentWidget);

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// создание заголовка
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget*  AChartWidget :: createHeader() 
{
	auto headerWidget = new QWidget();
	headerWidget->setFixedHeight(120);
	auto headerLayout = new QHBoxLayout(headerWidget);
	headerLayout->setContentsMargins(0, 0, 0, 0);

	//создание информационного бокса
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


void AChartWidget ::  test()
{
	auto customPlot = mPlot;


	customPlot->setInteraction(QCP::iRangeZoom,true);   // Включаем взаимодействие удаления/приближения
    customPlot->setInteraction(QCP::iRangeDrag, true);  // Включаем взаимодействие перетаскивания графика
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal);   // Включаем перетаскивание только по горизонтальной оси
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
   // customPlot->xAxis->setDateTimeFormat("hh:mm");  // Устанавливаем формат даты и времени
 
    // Настраиваем шрифт по осям координат
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
 
    // Автоматическое масштабирование тиков по Оси X
    //customPlot->xAxis->setAutoTickStep(true);
 
    /* Делаем видимыми оси X и Y по верхней и правой границам графика,
     * но отключаем на них тики и подписи координат
     * */
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
    auto graphic = customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);

	graphic->setName("Доход, Р");       // Устанавливаем
    graphic->setPen(QPen(QColor(Qt::red))); // Устанавливаем цвет графика
    graphic->setAntialiased(false);         // Отключаем сглаживание, по умолчанию включено
    graphic->setLineStyle(QCPGraph::lsImpulse); // График в виде импульсных тиков
 
    /* Подключаем сигнал от Оси X об изменении видимого диапазона координат
     * к СЛОТу для переустановки формата времени оси.
     * */
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(slotRangeChanged(QCPRange)));
 
    // Будем строить график с сегодняшнего дни и текущей секунды в будущее
    double now = QDateTime::currentDateTime().toTime_t();
    // Объявляем вектора времени и доходов
    QVector <double> time(400);
	QVector <double> income(400);
 
    srand(15); // Инициализируем генератор псевдослучайных чисел
 
    // Заполняем график значениями
	income[0] = 0;
    for (int i= 1; i<400; ++i)
      {
        time[i] = now + 3600*i;
        income[i] = qFabs(income[i-1]) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
 
    graphic->setData(time, income); // Устанавливаем данные
    customPlot->rescaleAxes();      // Масштабируем график по данным
    customPlot->replot();           // Отрисовываем график

}







 ///=====================================================================================
///
/// очистка всех зависемостей
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
/// установка действующих закладок
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
/// обнолвение виджета
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartWidget :: refresh(const QVector<int> &data)
{


}