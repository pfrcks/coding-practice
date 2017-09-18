/*
 * =====================================================================================
 *
 *       Filename:  fastexpo.cpp
 *
 *    Description: Fast exponentiation using recursion
 *
 *        Version:  1.0
 *        Created:  09/14/2017 08:10:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amol Agrawal
 *
 * =====================================================================================
 */

#include <iostream>
#include "math.h"
#include <ctime>

using namespace std;

int fastexpo(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    int t = pow(a, n/2);
    return t*t*pow(a, n%2);
}

int slowexpo(int a, int n)
{
    int ret = 1;
    while(n)
    {
        if(n%2==1)
            ret*=a;
        a*=a;
        n/=2;
    }
    return ret;
}

int main()
{
    int a, n;
    cin >> a >> n;
    clock_t start;
    start = clock();
    cout << fastexpo(a, n);
    cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    cout << slowexpo(a, n) << endl;
    start = clock();
    cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    return 0;
}
