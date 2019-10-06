#include <iostream>
#include "linear_recurrence.h"

int main()
{
    int n = 10;
    std::cout << fibonacci(n) << std::endl;
    std::cout << lucas(n) << std::endl;
    std::cout << pell(n) << std::endl;
    std::cout << pell_lucas(n) << std::endl;
    std::cout << padovan(n) << std::endl;
    std::cout << perrin(n) << std::endl;
    std::cout << tribonacci(n) << std::endl;
    std::cout << tribonacci_lucas(n) << std::endl;
    std::cout << cordonnier(n) << std::endl;

    trinomial<int> p(1, 2, 3);
    trinomial<int> q(3, 3, 4);
    auto r = modular_cubic_multiplies<int>(1, 1, 1)(p, q);
    std::cout << r.m0 << ", " << r.m1 << ", " << r.m2 << std::endl;
}
