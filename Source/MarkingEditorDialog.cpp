#include "MarkingEditorDialog.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QHeaderView>
#include <QWindow>
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Marking;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AMarkingEditorDialog :: AMarkingEditorDialog ()
{
	setWindowFlags(Qt::Dialog | Qt::Popup);
	//setWindowFlags(Qt::Window);
	createUI(this);

	setModal(true);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AMarkingEditorDialog :: ~AMarkingEditorDialog ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// показать диалог редактирования
/// 
/// 
///--------------------------------------------------------------------------------------
void AMarkingEditorDialog :: show(const PMarkingContainer &markings)
{
	mMarkings = markings;
	
	auto mm = qApp->topLevelWindows();

	//setMi
	//setWindowFlags(Qt::Dialog | Qt::Main);
	//mm[0]->

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
void AMarkingEditorDialog :: createUI(QWidget *form)
{
        form->resize(800, 600);
        auto verticalLayout = new QVBoxLayout(form);
        verticalLayout->setSpacing(9);
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        mViews = new QTableWidget(form);
		mViews->horizontalHeader()->setStretchLastSection(true);
		verticalLayout->addWidget(mViews);

        auto widget = new QWidget(form);
        auto horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(9);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        auto horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        auto butAdd = new QPushButton(widget);
		horizontalLayout->addWidget(butAdd);

        auto butDelete = new QPushButton(widget);
        horizontalLayout->addWidget(butDelete);

        auto butClose = new QPushButton(widget);
        horizontalLayout->addWidget(butClose);

        verticalLayout->addWidget(widget);



		//перевод строк
		form		->setWindowTitle(QApplication::translate("markingEditor", "Marking editor", 0));
        butAdd		->setText(QApplication::translate("markingEditor", "ADD", 0));
		butDelete	->setText(QApplication::translate("markingEditor", "DELETE", 0));
		butClose	->setText(QApplication::translate("markingEditor", "CLOSE", 0));

		//
		connect(butAdd,		&QPushButton::clicked, this, &AMarkingEditorDialog::slot_add);
		connect(butClose,	&QPushButton::clicked, this, &QDialog::close);
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
void AMarkingEditorDialog :: refresh()
{
	mViews->clear();
	mViews->setColumnCount(2);
	mViews->setHorizontalHeaderLabels(QString("Value;Description").split(";"));	
	mViews->horizontalHeader()->setVisible(true);

	//устанваливем данные
	if (mMarkings.isNull())
	{
		return;
	}

	const int count = mMarkings->count();
	mViews->setRowCount(count);
	for (int i = 0; i < count; i++)
	{
		auto item = mMarkings->item(i);
		mViews->setItem(i, 0, new QTableWidgetItem (QString::number(item->value())));
		mViews->setItem(i, 1, new QTableWidgetItem (item->description()));
	}
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// нажали кнопку добавить
/// 
/// 
///--------------------------------------------------------------------------------------
void AMarkingEditorDialog :: slot_add()
{
	/*
	int row = mViews->rowCount();
	mViews->insertRow(row);
	mViews->setItem(row, 0, new QTableWidgetItem ("0"));
	*/
}