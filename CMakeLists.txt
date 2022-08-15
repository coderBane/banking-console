cmake_minimum_required(VERSION 3.0.0)
project(Banking-Console VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)

set(SOURCES src/utilities.cpp bank/account.cpp bank/transaction.cpp bank/customer.cpp)

add_executable(Banking-Console main.cpp ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include
                                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/bank)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
