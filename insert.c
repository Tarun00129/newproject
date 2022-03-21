#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char  server[16] = "localhost";
    char username[16] = "root";
    char password[16] = "tarun";
    char database[16] = "mydb";

    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("mysql initialization failed");
        return 1;
    }

    if (mysql_real_connect(conn, server, username, password, database, 0, 0, 0) == NULL) {
        printf("unable to connect with mysql server\n");
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "insert into teb (name,age,pno) values('ram',21,10000)")) {
        printf("unable to insert data into your table\n");
        mysql_close(conn);
        return 1;
    }
    mysql_close(conn);

    printf("Data inserted successfully\n");

    return 0;
}
