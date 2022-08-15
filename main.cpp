#include <iostream>
#include <bank.hpp>


using namespace bank;

int main(int, char**) {

    Customer *c = new Customer;

    enroll(c);

    c->customerInfo();

    //std::cout << sizeof(c);
    delete(c);
}