#ifndef DB_TABLES_HPP
#define DB_TABLES_HPP

constexpr const char *customer_table_create = 
    "CREATE TABLE IF NOT EXISTS Customers(\n"
    "\tId NUMERIC NOT NULL CONSTRAINT PK_Customers PRIMARY KEY,\n"
    "\tFirstname VARCHAR(50) NOT NULL,\n"
    "\tLastname VARCHAR(50) NOT NULL,\n"
    "\tDoB TEXT NOT NULL,\n"
    "\tJoined datetime DEFAULT current_timestamp)"
;

constexpr const char *customer_init = 
    "INSERT INTO Customers (Id,Firstname,Lastname,DoB)\n" 
    "VALUES (?, ?, ?, ?)"
;

constexpr const char * customer_data[] = {
    "John", "Buldh", "1970-09-10",
    "Mary", "Poppins", "1970-06-21",
    "Amando", "Goegres", "1970-06-13",
    "Neil", "Lumba", "1970-10-21",
};

void dbInit();

const char * customerInit();

#endif