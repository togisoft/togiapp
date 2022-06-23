#ifndef _CONNECTION_

#include <iostream>
#include <string>
#include <wx/wx.h>
#include <odbc/Connection.h>
#include <odbc/Environment.h>
#include <odbc/Exception.h>
#include <odbc/PreparedStatement.h>
#include <odbc/ResultSet.h>
class Connections
{

public:
    Connections();
    std::string connect{"connect"};
    odbc::EnvironmentRef env;
    odbc::ConnectionRef conn;
    odbc::PreparedStatementRef psInsert;
    odbc::PreparedStatementRef psSelect;
    odbc::ResultSetRef rs;
    ~Connections()
    {
        conn->disconnect();
    }
};
#define _CONNECTION_
#endif