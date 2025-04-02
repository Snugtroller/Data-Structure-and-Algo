#include <bits/stdc++.h>
using namespace std;
bool divideArray(vector<int> nums)
{
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }
    for (auto &p : freq)
    {
        if (p.second % 2 != 0)
            return false;
    }
    return true;
}
int main()
{
    vector<int> nums = {3, 3, 2, 2, 2, 2};
    if (divideArray(nums))
    {
        cout << "Yes, the array can be divided into pairs." << endl;
    }
    else
    {
        cout << "No, the array cannot be divided into pairs." << endl;
    }
    return 0;
}