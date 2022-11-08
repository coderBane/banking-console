#include "sqlcpp.h"
#include "db-tables.hpp"
#include "utilities.hpp"



// const char * customerInit()
// {
//     std::random_device rd;

//     char sql[] = 
//         "DELETE FROM Customers\n"
//         "INSERT INTO Customers (Id, Firstname,Lastname,DoB)\n"
//         "VALUES"
//     ;

//     const char * data[4][3] ={
//         {"John", "Buldh", "1970-09-10"},
//         {"Mary", "Poppins", "1970-06-21"},
//         {"Amando", "Goegres", "1970-06-13"},
//         {"Neil", "Lumba", "1970-10-21"}
//     } ;

//     char buffer[100];

//     for (const auto &i : data){
//         sprintf(buffer, "(%u,%s,%s,%s)", rd(), i[0], i[1], i[2]);
//         strcat(sql, buffer);

//         if (strcmp(i[0], "Neil") == 0) 
//             continue;

//         strcat(sql, (const char*)",");
//     }

//     return sql;
// }