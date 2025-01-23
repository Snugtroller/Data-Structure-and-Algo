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
bool AnotherPalindrome(int l, int r, string s)
{
    if (l >= r)
    {
        return true;
    }
    if (s[l] != s[r])
        return false;
    AnotherPalindrome(l + 1, r - 1, s);
}
int main()
{
    string str = {"naman"};
    if (palindromeCheck(str, 0))
        cout << "yes";
    if (AnotherPalindrome(0, str.size() - 1, str))
        cout << "yes";
}