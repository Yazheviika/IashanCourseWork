#include <iostream>
#include "Buyer.h"
#include "Seller.h"
#include <stdio.h>
#include <sqlite3.h>

int main()
{
    sqlite3* db;

    int rc = sqlite3_open("D:\SQLite\#My Data Bases\CourseWork.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    //Seller seller("fd", "erfew", "dfa", "dsfa", 32, "ewrwe", "erfq", "efsd");
    //seller.registrateUser(db);

    sqlite3_close(db);

}

