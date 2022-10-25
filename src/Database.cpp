//
// Created by simon on 2022-10-25.
//

#include <cstring>
#include "../include/Database.h"

Database::Database(const char *bdName) {
    rc = sqlite3_open(bdName, &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

void Database::Close() {
    sqlite3_close(db);
    fprintf(stderr, "Closed database\n");
}

void Database::CheckTable(const char *tableName) {
    /* Create SQL statement */
    strncpy(sql, "SELECT * FROM ", sizeof(sql));
    strncat(sql, tableName, sizeof(sql));

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

