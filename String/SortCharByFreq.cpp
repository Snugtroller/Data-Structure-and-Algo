// Input: s = "tree"
// Output: "eert"

#include <bits/stdc++.h>
using namespace std;

string FreqSort(string s)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }
    vector<pair<int, char>> freqVec;
    for (auto it : freq)
    {
        freqVec.push_back({it.second, it.first});
    }
    sort(freqVec.rbegin(), freqVec.rend());
    string ans;
    for (auto it : freqVec)
    {
        ans.append(it.first, it.second);
    }
    return ans;
}
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string sortedStr = FreqSort(s);
    cout << "Frequency Sorted String: " << sortedStr << endl;

    return 0;
}
