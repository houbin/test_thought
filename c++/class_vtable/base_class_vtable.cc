#include <iostream>
#include <stdint.h>
#include "base.h"

using namespace std;

int main()
{
    Base b;
    Fun p_fun = NULL;

    // 虚函数表地址在栈空间上
    cout << "虚函数表地址: 0x" << (int64_t*)&b << endl;

    // v_table首地址, Base的虚函数地址在代码段上
    int64_t* v_table = (int64_t *)(*(int64_t *)&b);
    cout << "虚函数表的第一个函数地址: 0x" << v_table << endl;

    // 第一个函数
    p_fun = (Fun)*v_table;
    p_fun();

    // 第二个函数
    p_fun = (Fun)*(v_table + 1);
    p_fun();

    // 第三个函数
    p_fun = (Fun)*(v_table + 2);
    p_fun();

    return 0;
}
