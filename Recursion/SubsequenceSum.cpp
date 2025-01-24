#include <bits/stdc++.h>
using namespace std;
void VectorSum(int index, vector<int> &ds, vector<int> &arr, int s, int sum)
{
    if (index == arr.size())
    {
        if (s == sum)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i];
            }
            cout << endl;
        }
        return;
    }
    // include
    ds.push_back(arr[index]);
    VectorSum(index + 1, ds, arr, s + arr[index], sum);
    ds.pop_back();
    // exclude
    VectorSum(index + 1, ds, arr, s, sum);
}
int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int sum = 2;
    VectorSum(0, ds, arr, 0, sum);
}