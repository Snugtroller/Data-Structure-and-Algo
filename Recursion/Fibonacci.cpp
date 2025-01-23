#include <bits/stdc++.h>
using namespace std;
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    // Fibonacci(3)=Fibonacci(2)+Fibonacci(1)
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
    int n = Fibonacci(9);
    cout << n;
}