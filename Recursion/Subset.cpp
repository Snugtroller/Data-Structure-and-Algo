#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans, vector<int> output, int index, vector<int> &vec)
{
    if (index >= vec.size())
    {
        ans.push_back(output);
        return;
    }

    helper(ans, output, index + 1, vec);

    output.push_back(vec[index]);
    helper(ans, output, index + 1, vec);
}

vector<vector<int>> powerSet(vector<int> &nums)
{
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;
    helper(ans, output, index, nums);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = powerSet(nums);
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int val : subset)
        {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}
