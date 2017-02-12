#include "DSComPortDialog.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QHeaderView>
#include <QWindow>
#include <QTime>
#include <QSerialPortInfo>

#include "DSComPort.h"
#include "ModuleData.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace DataSource;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AComPortDialog :: AComPortDialog ()
{
	setParent(AModuleData::main());
	setWindowFlags(Qt::Dialog);
	setAttribute(Qt::WA_Resized, false);
	createUI(this);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AComPortDialog :: ~AComPortDialog ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// показать диалог редактирования
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPortDialog :: show(const QWeakPointer<AComPort> &dataSource)
{
	mDataSource = dataSource;
	
	mPorts = QSerialPortInfo::availablePorts();

	
	raise();
	activateWindow();
	refresh();

	QDialog::show();
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// создание диалога
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPortDialog :: createUI(QWidget *form)
{
	int width = 350;
	int height = 200;
	form->setMinimumSize(QSize(width, height));
    form->setMaximumSize(QSize(width, height));
    form->resize(width, height);


	auto butHide = new QPushButton(form);
    butHide->setText(QApplication::translate("random", "Hide", 0));
	butHide->setGeometry(QRect(width - 82, height - 30, 75, 23));

  

    auto label = new QLabel(form);
	label->setText(QApplication::translate("random", "Status:", 0));
    label->setGeometry(QRect(20, 20, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    label = new QLabel(form);
	label->setText(QApplication::translate("random", "Ports:", 0));
    label->setGeometry(QRect(20, 50, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    
	label = new QLabel(form);
	label->setText(QApplication::translate("random", "Count using:", 0));
    label->setGeometry(QRect(20, 80, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    mStatus = new QLabel(form);
    mStatus->setGeometry(QRect(120, 20, 171, 16));

    mCount = new QLabel(form);
    mCount->setGeometry(QRect(120, 80, 171, 16));

	mBoxPort = new QComboBox(form);
    mBoxPort->setGeometry(QRect(120, 50, 161, 20));

	//
	connect(mBoxPort, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_portChanged(int)));
	connect(butHide,	&QPushButton::clicked, this, &QDialog::close);
	//

    QMetaObject::connectSlotsByName(form);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// обновить данные
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPortDialog :: refresh()
{
	if (mDataSource.isNull())
	{
		setWindowTitle("Broken");
		mStatus->setText("-");
		mCount->setText("-");
		
		mBoxPort->blockSignals(true);
		mBoxPort->clear();
		mBoxPort->setEnabled(false);
		mBoxPort->blockSignals(false);
		return;
	}

	AComPort *data = mDataSource.data();

	QString status = "stop";
	const bool run = data->isActive();
	if (run)
	{
		QTime time(0,0,0);
		time = time.addMSecs(data->lastTimeMS());
		status = QString("RUN - ") + time.toString("HH:mm:ss:zzz");
	}


	setWindowTitle(data->title());
	mStatus->setText(status);
	mCount->setText(QString::number(data->streamData->count()));
	

	//комбобокс портов
	mBoxPort->blockSignals(true);
	mBoxPort->clear();
	mBoxPort->setEnabled(!run);

	
	QStringList list;
	for(auto item = mPorts.cbegin(); item != mPorts.cend(); ++item)
	{
		auto port = *item;
		list.append(port.portName());
	}

	mBoxPort->insertItems(0, list);

	mBoxPort->blockSignals(false);

}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// завершили редактировать интервал данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPortDialog :: slot_portChanged(int index)
{
	if (!mDataSource.isNull())
	{
		//mDataSource.data()->setInterval(text.toInt());
	}
}