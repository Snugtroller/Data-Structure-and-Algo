#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> arr, vector<int> &ds, vector<bool> &freq, vector<vector<int>> &res)
{
    if (ds.size() == arr.size())
    {
        res.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            ds.push_back(arr[i]);
            helper(arr, ds, freq, res);
            ds.pop_back();
            freq[i] = false;
        }
    }
}
// using swap method
void helper2(vector<int> &arr, vector<vector<int>> &ans, int index)
{

    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        helper2(arr, ans, index + 1);
        swap(arr[index], arr[i]);
    }
}
vector<vector<int>> permute(vector<int> arr)
{
    // vector<int> ds;
    // vector<bool> freq(arr.size(), false);
    vector<vector<int>> res;
    // helper(arr, ds, freq, res);
    helper2(arr, res, 0);
    return res;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res = permute(arr);
    for (const auto &permute : res)
    {
        for (int num : permute)
        {
            cout << num;
        }
        cout << endl;
    }
}