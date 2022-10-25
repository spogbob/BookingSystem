//
// Created by simon on 2022-10-25.
//

#ifndef BOOKINGSYSTEM_DATABASE_H
#define BOOKINGSYSTEM_DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
private:
    int rc;

    char *zErrMsg = nullptr;
    char sql[256];
    const char* data = "Callback function called";

    sqlite3 *db;

    static int callback(void *data, int argc, char **argv, char **azColName){
        int i;
        fprintf(stderr, "%s: \n", (const char*)data);

        for(i = 0; i<argc; i++){
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }

        printf("\n");
        return 0;
    }
public:

    explicit Database(const char *bdName);

    void Close();

    void CheckTable(const char *tableName);

};


#endif //BOOKINGSYSTEM_DATABASE_H
