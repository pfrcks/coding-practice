/*
 * =====================================================================================
 *
 *       Filename:  tofromDecimal.cpp
 *
 *    Description: Convert a number to and from decimal base.
 *
 *        Version:  1.0
 *        Created:  09/13/2017 09:44:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int toDecimal(int n, int b)
{
    int result = 0;
    int multiplier = 1;

    while(n)
    {
        result+= n%10*multiplier;
        multiplier*=b;
        n=n/10;
    }
    return result;
}

int fromDecimal(int n, int b)
{
    int result = 0;
    int multiplier = 1;

    while(n)
    {
        result+= n%b*multiplier;
        multiplier*=10;
        n=n/b;
    }
    return result;
}

void toHexa(int n)
{
    int b = 16;
    char hexa[100];
    int i=0;
    while(n)
    {
        int temp = n % b;
        if (temp < 10)
            hexa[i++] = temp + 48;
        else
            hexa[i++] = temp + 55;
        n = n/b;
    }

    for(int j = i-1 ; j >=0; j--)
        cout << hexa[j];
}

int main()
{
    cout << toDecimal(1011, 2) << endl;
    cout << fromDecimal(45, 2) << endl;
    cout << fromDecimal(45, 8) << endl;
    toHexa(45);
}
