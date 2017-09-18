/*
 * =====================================================================================
 *
 *       Filename:  hammingDistance.cpp
 *
 *    Description: Hamming distance between two integers 
 *
 *        Version:  1.0
 *        Created:  09/17/2017 06:05:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amol Agrawal
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int sum =0;
    int p;
    cin >> x >> y;
    p = x ^ y;
    while(p)
    {
        p = p & (p-1);
        sum++;
    }
    cout << sum;
    return 0;
}
