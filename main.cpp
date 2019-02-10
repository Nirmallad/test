#include <iostream>
#include "i2c_module.h"

using namespace std;

int main(void)
{
    i2c_module test;

    cout<<"hey"<<endl;

    if(test.open_i2c(1, 0x40))
        cout<<"bye"<<endl;
    else
        cout<<"hey"<<endl;

    if(test.close_i2c(&test))
        cout<<"bye"<<endl;
    else
        cout<<"hey"<<endl;
}
