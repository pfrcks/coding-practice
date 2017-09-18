/*
 * =====================================================================================
 *
 *       Filename:  seive.cpp
 *
 *    Description: Test for prime numbers using the Seive of Eratosthenes. It improves over the primes.cpp
 *    as it stores all the primes upto number N in one go and querying for any number below N is a simple lookup.
 *
 *        Version:  1.0
 *        Created:  09/13/2017 08:33:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amol Agrawal
 *
 * =====================================================================================
 */

#include <iostream>
#include "math.h"
#include <cstring>

using namespace std;
bool array[10000001];

void sieve()
{
    array[0] = true;
    array[1] = true;
    int m = sqrt(10000001);

    for(int i = 2; i <= m; i++)
    {
        if (array[i] == false)
        {
            for(int j=i*i; j <10000001 ; j+=i)
                array[j]=true;
        }
    }
}

int main()
{
    int num, query;
    sieve();
    cin >> num;
    while(num--)
    {
        cin >> query;
        if (array[query] == false)
            cout << 0;
        else
            cout << 1;
    }
    return 0;
}
