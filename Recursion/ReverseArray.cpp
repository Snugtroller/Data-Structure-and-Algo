#include <bits/stdc++.h>
using namespace std;
void ReverseArray(int l, int r, vector<int> &arr)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    l++;
    r--;
    ReverseArray(l, r, arr);
}
int main()
{
    vector<int> arr = {5, 2, 3, 4, 1};
    ReverseArray(0, 4, arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}