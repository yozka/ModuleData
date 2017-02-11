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
	///setWindowFlags(Qt::Window);
	
	//setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_Resized, false);
	createUI(this);

	setMinimumSize(QSize(293, 132));
    setMaximumSize(QSize(293, 132));
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
	
	
	auto ports = QSerialPortInfo::availablePorts();

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
    form->resize(293, 132);
	auto butHide = new QPushButton(form);
    butHide->setText(QApplication::translate("random", "Hide", 0));
	butHide->setGeometry(QRect(210, 100, 75, 23));

  

    auto label = new QLabel(form);
	label->setText(QApplication::translate("random", "Status:", 0));
    label->setGeometry(QRect(20, 20, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    label = new QLabel(form);
	label->setText(QApplication::translate("random", "Interval:", 0));
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

	mInterval = new QLineEdit(form);
    mInterval->setGeometry(QRect(120, 50, 161, 20));

	//
	connect(mInterval,	&QLineEdit::textEdited, this, &AComPortDialog::slot_editInterval);
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
		mInterval->setText("-");
		mInterval->setEnabled(false);
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
	mInterval->setEnabled(!run);

	setWindowTitle(data->title());
	mStatus->setText(status);
	mCount->setText(QString::number(data->streamData->count()));
	//mInterval->setText(data->);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// завершили редактировать интервал данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AComPortDialog :: slot_editInterval(const QString &text)
{
	if (!mDataSource.isNull())
	{
		//mDataSource.data()->setInterval(text.toInt());
	}
}