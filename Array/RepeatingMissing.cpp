#include <bits/stdc++.h>
using namespace std;
vector<int> idkarray(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (const int &num : nums)
    {
        freq[num]++;
    }
    int missing = -1;
    int repeating = -1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (freq[i] >= 2)
            repeating = i;
        if (freq[i] == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
            break;
    }
    vector<int> ans = {repeating, missing};
    return ans;
}
int main()
{
    vector<int> nums = {4, 3, 6, 2, 1, 1}; // Example input
    vector<int> result = idkarray(nums);

    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}