#include <iostream>
#include <mysql.h>
#include <windows.h>

using namespace std;

const char* hostname = "localhost";
const char* username = "root";
const char* password = "Iamalegend";
const char* database = "db";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned int clientflag = 0;


MYSQL* connectdatabase(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, username, password, database, port, unixsocket, clientflag);
    if(conn){
        return conn;
    }else{
        cout << "error, not connected"<< endl;
    }
}

int main()
{
    MYSQL* conn = connectdatabase();
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_query(conn, "SELECT * FROM STUDENT");
    res=mysql_use_result(conn);
    int num_fields = mysql_num_fields(res);
    while((row=mysql_fetch_row(res))!=NULL){
        for(int i=0;i<num_fields;i++){
            cout << row[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
