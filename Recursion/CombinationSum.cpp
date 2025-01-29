#include <bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &res, vector<int> arr, int index, int target, vector<int> &ds)
{
    if (target == 0)
    {
        res.push_back(ds);
        return;
    }
    if (arr.size() < index || target < 0)
    {
        return;
    }
    ds.push_back(arr[index]);
    helper(res, arr, index, target - arr[index], ds);
    ds.pop_back();
    helper(res, arr, index + 1, target, ds);
}
vector<vector<int>> CombinationSum(vector<int> array, int target)
{
    vector<vector<int>> res;
    int index = 0;
    vector<int> ds;
    helper(res, array, index, target, ds);
    return res;
}
int main()
{
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> result = CombinationSum(arr, 7);
    for (const auto &combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}