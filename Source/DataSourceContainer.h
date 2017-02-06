#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QList>
#include "DataSource.h"
///--------------------------------------------------------------------------------------

namespace DataSource
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// ��������� ���������� ������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataSourceContainer
			: 
				public QObject
	{
		Q_OBJECT

	public:
		ADataSourceContainer();
		virtual ~ADataSourceContainer();


		int count() const; //���������� ��������� � ����������
		PDataSource item(const int index); //��������� ������ � ����������
		void append(const PDataSource &data); //��������� ������


	signals:
	
		void signal_change(); //������ ����������, ������


	private:


		QList<PDataSource> mDatas; //������


	private slots:

		void slot_change(const ADataSource* data); //��������� ������
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataSourceContainer> PDataSourceContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

