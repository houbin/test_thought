#include <iostream>
#include <stdint.h>
#include "base.h"

using namespace std;

class Derive : public Base
{
public:
    virtual void f1() { cout << "Derive::f1" << endl; }
    virtual void g1() { cout << "Derive::g1" << endl; }
    virtual void h1() { cout << "Derive::h1" << endl; }
};

int main()
{
    Derive d;

    Fun p_fun = NULL;

    int64_t *v_table = (int64_t *)*(int64_t *)&d;

    for (int i = 0; i < 10; i++)
    {
        int64_t func_addr = *(v_table + i);
        if (func_addr == 0)
        {
            cout << "encounter addr 0, end" << endl;
            break;
        }
        cout << "第" << i << "个函数地址: 0x" << func_addr << endl;
        p_fun = (Fun)func_addr;
        
        p_fun();
    }

    return 0;
}

