#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> arr, vector<int> &res, int sum, int index)
{
    if (index >= arr.size())
    {
        res.push_back(sum);
        return;
    }
    helper(arr, res, sum + arr[index], index + 1);
    helper(arr, res, sum, index + 1);
}
vector<int> subsetSum(vector<int> &arr)
{
    vector<int> res;
    int sum = 0;
    int index = 0;
    helper(arr, res, sum, index);
    return res;
}
int main()
{
    vector<int> arr = {2, 3};
    vector<int> res = subsetSum(arr);
    for (int sum : res)
    {
        cout << sum << " ";
    }
    cout << endl;
}