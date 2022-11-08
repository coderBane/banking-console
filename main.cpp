#include <iostream>
#include <sqlite3.h>
#include <filesystem>
#include "utilities.hpp"
#include "db-tables.hpp"

using namespace std;

constexpr const char *dbPath = "test.db";

int sql_do(sqlite3 *db, const char *query, char* error)
{
    int rc = sqlite3_exec(db, query, nullptr, nullptr, &error);
    if (rc != SQLITE_OK){
        cerr << "Error Executing DbCommand: " << error << endl;
        exit(1);
    }

    cout << "Executed DbCommand ->\n" << query << endl;
    return sqlite3_changes(db);
}

int main(int, char**) 
{
    // auto cwd = filesystem::current_path();
    // cout << cwd.string() << endl;

    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *errmsg = 0;

    //open database connection
    int rc = sqlite3_open(dbPath, &db);

    if (rc != SQLITE_OK){
        cerr << "Error opening database\n" << sqlite3_errmsg(db) << endl;
        return 1;
    }

    cout << "Database opened" << endl;

    //create the table
    cout << "creating customer table" << endl;
    sql_do(db, customer_table_create, errmsg);

    //insert rows into customer table
    sql_do(db, "DELETE FROM Customers;",errmsg);
    sqlite3_prepare_v2(db, customer_init, -1, &stmt, nullptr);
    int params = sqlite3_bind_parameter_count(stmt);
    int rows = sizeof(customer_data) / sizeof(char *) / params;

    random_device rd;

    int istr_index = 0, row_insert = 0;
    for (int row = 0; row < rows + 1; ++row)
    {
        for (int col = 0; col < params; ++col){
            if (!col){
                sqlite3_bind_int(stmt, col + 1, rd());
                continue;
            }
            sqlite3_bind_text(stmt, col + 1, customer_data[istr_index], -1, SQLITE_STATIC);
            ++istr_index;
        }
        sqlite3_step(stmt);
        row_insert += sqlite3_changes(db);
        sqlite3_reset(stmt); // reset for next run
    }

    sqlite3_finalize(stmt);
    cout << "Inserted rows: " << row_insert << endl;
    
    // sqlite3_prepare_v2(db, "SELECT * FROM Items", -1, &stmt, nullptr);

    // //column names
    // int cols = sqlite3_column_count(stmt);
    // for (int i = 0; i < cols; ++i){
    //     cout << sqlite3_column_name(stmt, i) << (i < cols - 1 ? "\t" : "");
    // }

    // //print row values
    // cout << "\n";
    // while (sqlite3_step(stmt) == SQLITE_ROW){
    //     for (int i = 0; i < cols - 1; ++i){
    //         auto value = sqlite3_column_text(stmt, i);
    //         if (value == nullptr)
    //             cout << "NULL";
    //         else cout << value;
    //         cout << "\t";
    //     }
    //     cout << "\n";
    // }

    //sqlite3_finalize(stmt);
    sqlite3_close(db);
    cout << "Database closed" << endl;

    return 0;
}

