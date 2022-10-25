#include <cstdio>
#include <string>

#include "../include/Database.h"

int main(int argc, char* argv[]) {
    Database db("../booking.db");

    db.CheckTable("users");

    db.Close();
}