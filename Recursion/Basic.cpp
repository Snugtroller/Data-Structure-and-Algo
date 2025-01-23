#include <bits/stdc++.h>
using namespace std;
// PRINT FROM 1 TO N BUT U START FROM N
void helper(int n)
{
    if (n < 1)
    {
        return;
    }
    helper(n - 1);
    cout << n << " ";
}
// PRINT FROM N TO 1 BUT U START FROM N
void helper1(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    helper1(n - 1);
}
// SUM OF FIRST N NUMBERS
int helper3(int n, int sum)
{
    if (n < 1)
    {
        return sum;
    }
    return helper3(n - 1, sum + n);
}
// FACTORIAL OF N
int helper4(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if(n==1){
        return 1;
    }
    return n*helper4(n-1);
}
int main()
{
    helper(4);
    cout << endl;
    helper1(4);
    cout << endl;
    int sumTotal = helper3(4, 0);
    cout << sumTotal << endl;
    int fact=helper4(4);
    cout <<fact<< endl;
    // return 0;
}