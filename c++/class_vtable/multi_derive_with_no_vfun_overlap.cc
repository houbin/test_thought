#include <iostream>
#include <stdint.h>
#include "base.h"

using namespace std;

class Derive : public Base, public Base2, public Base3
{
public:
    virtual void f1() { cout << "Derive::f1" << endl; }
    virtual void g1() { cout << "Derive::g1" << endl; }
};

int main()
{
    Derive d;

    for (int i = 0; i < 3; i++)
    {
        int64_t *vtable = (int64_t *)*(((int64_t*)&d) + i);

        for (int j = 0; j < 20; j++)
        {
            int64_t temp = *(vtable + j);
            if (temp <= 0)
            {
                break;
            }

            Fun fun = (Fun)temp;
            cout << "虚函数表 [" << i << ", " << j << "] 地址为: "  << temp << endl;
            fun();
        }
    }

    return 0;
}

