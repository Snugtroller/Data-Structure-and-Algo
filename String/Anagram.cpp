// Input: s = "anagram", t = "nagaram"

// Output: true

#include <bits/stdc++.h>
using namespace std;

bool Anagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
        freq[t[i]]--;
    }
    for (auto it : freq)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (Anagram(s1, s2))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are NOT anagrams." << endl;
    }

    return 0;
}
