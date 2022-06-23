#include "Connection.hpp"

Connections::Connections()
{
    try
    {
        env = odbc::Environment::create();
        conn = env->createConnection();
        conn->connect("MSSQLTogi", "sa", "531782aA");
        conn->setAutoCommit(false);
        connect = "Database Connected";
    }
    catch (const odbc::Exception &e)
    {
        std::cerr << e.what() << '\n';
        connect = "Connection error!";
    }
}