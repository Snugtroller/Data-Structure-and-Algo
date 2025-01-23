#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(string s, int i)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    palindromeCheck(s, i + 1);
}
int main()
{
    string str = {"naman"};
    if (palindromeCheck(str, 0))
        cout << "yes";
}