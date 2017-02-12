#include "../../../Source/ModuleData.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append(".");
    paths.append("imageformats");
    paths.append("platforms");
    paths.append("sqldrivers");
    QCoreApplication::setLibraryPaths(paths);


	QApplication a(argc, argv);
	AModuleData w;
	w.show();
	return a.exec();
}


//QString newName = QInputDialog::getText(this, "QCustomPlot example", "New graph name:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
   