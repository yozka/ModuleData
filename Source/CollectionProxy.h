#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
#include <QList>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ADataProxy;
	typedef QList<QSharedPointer<ADataProxy>> AListProxy;
	///--------------------------------------------------------------------------------------





	

	 ///=====================================================================================
	///
	/// ���������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class IInterface_receiv
	{
	public:
		virtual bool command_dataOpen		() = 0; //������� ������ ����� ������
		virtual	bool command_dataClose		() = 0;   //������� ����� ����� ������
		virtual bool command_dataReceive	(const QVariant &value) = 0;  //����� ������
		virtual void command_dataError		(const QString &error) = 0;	//��������� ������

		virtual void command_connect		(IInterface_receiv *obj) = 0; //����������� � ��������� ������
		virtual void command_disconnect		() = 0; //���������� �� ��������� ������
	};
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// ���������� ������������ ������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ACollectionProxy
		: 
			public QEnableSharedFromThis<ACollectionProxy>
	{


	public:
		ACollectionProxy(IInterface_receiv *parent);
		virtual ~ACollectionProxy();

		IInterface_receiv*	parent() const {return mParent;};


		bool connect	(const QSharedPointer<ADataProxy> &dataProxy);
		bool disconnect	(const QSharedPointer<ADataProxy> &dataProxy); //��������� �������� ������
		void disconnectAll(); //�������� ��� ����������
		int count() const; //���������� �����������


		//�������
		bool command_dataOpen();	//������� ������ ����� ������
		bool command_dataClose();   //������� ����� ����� ������
		bool command_dataSend(const QVariant &value);  //�������� ������
		void command_dataError(const QString &error); //������ � ������ ������

		QList<IInterface_receiv*> childs() const;//������� ���� �������� � �����������

	private:

		AListProxy			mDataProxy;
		IInterface_receiv*	mParent;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ACollectionProxy> PCollectionProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

