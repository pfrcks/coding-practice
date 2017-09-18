/*
 * =====================================================================================
 *
 *       Filename:  primes.cpp
 *
 *    Description: Check whether number is prime. The program takes into account the fact
 *    that we only need to check factors uptil the square root of the number and that we don't
 *    need to check even numbers as factors.
 *
 *        Version:  1.0
 *        Created:  09/13/2017 08:25:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amol Agrawal
 *
 * =====================================================================================
 */

#include <iostream>
#include "math.h"

using namespace std;

int isPrime(int n)
{
    if (n<=1) return 0;
    if (n==2) return 1;
    if (n%2==0) return 1;
    int m = sqrt(n);
    for(int i = 3; i <= m; i+=2)
    {
        if (n%i == 0)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n);
}
