#include "../../../Source/ModuleData.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AModuleData w;
	w.show();
	return a.exec();
}


//QString newName = QInputDialog::getText(this, "QCustomPlot example", "New graph name:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
   