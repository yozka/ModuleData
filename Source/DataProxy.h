#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ACollectionProxy;
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// ������������� ������ ����� �����������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataProxy
		: 
			public QEnableSharedFromThis<ADataProxy>
	{


	public:
		ADataProxy();
		

		virtual ~ADataProxy();


		bool connect(const QSharedPointer<ACollectionProxy> &source);
		void disconnect(); //��������� �������� ������


		//�������
		bool command_dataOpen();	//������� ������ ����� ������
		bool command_dataClose();   //������� ����� ����� ������
		bool command_dataSend(const QVariant &value);  //�������� ������
		void command_dataError(const QString &error);  //�������� ������

		QWeakPointer<ACollectionProxy> first() const; //������ �������� ������
		QWeakPointer<ACollectionProxy> second() const; //������ �������� ������

	private:

		QWeakPointer<ACollectionProxy> mSourceFirst;
		QWeakPointer<ACollectionProxy> mSourceSecond;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataProxy> PDataProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

