#include <bits/stdc++.h>
using namespace std;
void Subsequences(int index, vector<int> &ds, vector<int> &arr, int n)
{
    if (index == arr.size())
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i];
        }
        cout << endl;
        return;
    }
    // take the particular index
    ds.push_back(arr[index]);
    Subsequences(index + 1, ds, arr, n);
    ds.pop_back();
    // not take
    Subsequences(index + 1, ds, arr, n);
}
int main()
{
    vector<int> arr = {3, 1, 2};
    int n = arr.size();
    vector<int> ds;
    Subsequences(0, ds, arr, n);
}