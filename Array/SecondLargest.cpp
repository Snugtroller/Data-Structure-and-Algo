#include <bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int> &arr)
{
    int largest = INT_MIN;
    int secondLarge = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLarge = largest;
            largest = arr[i];
        }
        if (arr[i] > secondLarge && arr[i] < largest)
        {
            secondLarge = arr[i];
        }
    }
    return (secondLarge == INT_MIN) ? -1 : secondLarge;
}
int main()
{
    vector<int> res = {12, 35, 1, 10, 34, 1};
    int num = SecondLargest(res);
    cout << num;
}