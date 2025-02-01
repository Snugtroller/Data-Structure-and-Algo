// FORM SUBSEQUENCE

// #include <bits/stdc++.h>
// using namespace std;
// void helper(vector<int> arr, vector<int> &ds, vector<vector<int>> &res, int index)
// {
//     if (arr.size() <= index)
//     {
//         res.push_back(ds);
//         return;
//     }
//     ds.push_back(arr[index]);
//     helper(arr, ds, res, index + 1);
//     ds.pop_back();
//     helper(arr, ds, res, index + 1);
// }
// vector<vector<int>> Subsequence(vector<int> arr)
// {
//     vector<int> ds;
//     vector<vector<int>> res;
//     int index = 0;
//     helper(arr, ds, res, index);
//     return res;
// }
// int main()
// {
//     vector<int> arr = {3, 1, 2};
//     vector<vector<int>> res = Subsequence(arr);
//     for (const auto &Subsequence : res)
//     {
//         for (int nums : Subsequence)
//         {
//             cout << nums;
//         }
//         cout << endl;
//     }
// }

// FORM SUBSEQUENCE SUM

// #include <bits/stdc++.h>
// using namespace std;
// void helper(vector<int> arr, vector<int> &ds, int target, int index, vector<vector<int>> &res)
// {
//     if (target == 0)
//     {
//         res.push_back(ds);
//         return;
//     }
//     if (index >= arr.size() || target < 0)
//     {
//         return;
//     }
//     ds.push_back(arr[index]);
//     helper(arr, ds, target - arr[index], index + 1, res);
//     ds.pop_back();
//     helper(arr, ds, target, index + 1, res);
// }
// vector<vector<int>> SubsequenceSum(vector<int> arr, int target)
// {
//     vector<int> ds;
//     int index = 0;
//     vector<vector<int>> res;
//     helper(arr, ds, target, index, res);
//     return res;
// }
// int main()
// {
//     vector<int> arr = {1, 2, 1};
//     vector<vector<int>> res = SubsequenceSum(arr,2);
//     for (const auto &SubsequenceSum : res)
//     {
//         for (int nums : SubsequenceSum)
//         {
//             cout << nums;
//         }
//         cout << endl;
//     }
// }