#include <iostream>
using namespace std;

int Partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (arr[start] <= pivot && start < ub)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

void QuickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = Partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
}

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {2, 1, 4, 3, 6};
    int size = 5;
    int lb = 0;
    int ub = size - 1;

    QuickSort(arr, lb, ub);
    Print(arr, size);

    return 0;
}
