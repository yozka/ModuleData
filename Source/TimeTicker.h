#pragma once;
#include <QTime>
#include "qcustomplot-source\qcustomplot.h"

class ATimeTicker : public QCPAxisTicker
{
public:
  ATimeTicker();
  
	static QString timeToString(const int tick);
  
protected:
  

  
  // reimplemented virtual methods:
  //virtual double getTickStep(const QCPRange &range) Q_DECL_OVERRIDE;
  //virtual int getSubTickCount(double tickStep) Q_DECL_OVERRIDE;
	QString getTickLabel(double tick, const QLocale &locale, QChar formatChar, int precision) override;
  //virtual QVector<double> createTickVector(double tickStep, const QCPRange &range) Q_DECL_OVERRIDE;

private:
	static QTime mZeroTime;

};

