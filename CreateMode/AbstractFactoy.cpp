#include<vector>
class EmployDAO {
private:
	IDBFactory* m_factory;
public:
	vector<EmployDAO> CetEmplyeses() {
		IDBConnection* connection = m_factory->CreateConnection();
		IDBCommand* command = m_factory->CreateCommand();
		IDataReader* dataReader = m_factory->CreateDataReader();
	}

 };
class IDBConnection {

};
class IDBCommand {

};
class IDataReader {

};
class IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDataReader* CreateDataReader() = 0;
};


class SqlConnection : public IDBConnection {

};
class SqlCommand :public IDBCommand {

};
class SqlDataReader : public IDataReader {

};
class SqlDBFactory : public IDBFactory {
	virtual IDBConnection* CreateDBConnection() {

	}
	virtual IDBCommand* CreateDBCommand() {

	}
	virtual IDataReader* CreateDataReader() {

	}
};


class MysqlConnection : public IDBConnection {

};
class MysqlCommand :public IDBCommand {

};
class MysqlDataReader : public IDataReader {

};
class MysqlFactory : public IDBFactory {
	virtual IDBConnection* CreateDBConnection() {

	}
	virtual IDBCommand* CreateDBCommand() {

	}
	virtual IDataReader* CreateDataReader() {

	}
};