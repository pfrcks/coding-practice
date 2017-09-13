/*
 * =====================================================================================
 *
 *       Filename:  euclidGCD.cpp
 *
 *    Description: Finds the GCD of two numbers by using Euclids Algorithm
 *
 *        Version:  1.0
 *        Created:  09/13/2017 09:15:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amol Agrawal
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (b==0)
        return a;
    return GCD(b, a%b);
}

int LCM(int a, int b)
{
    return (a*b)/(GCD(a, b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << " " << LCM(a, b);
    return 0;
}
