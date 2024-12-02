//Sorting using recursion
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n){
    if((n==0)||(n==1))return true;
    if(arr[n-1]<arr[n-2])return false;
    return isSorted(arr,n-1); 
}

int sumArr(int arr[],int n,int sum){
    if(n==0)return sum;
    sum+=arr[0];
    return sumArr(arr+1,n-1,sum);
}

bool LinearSearch(int arr[],int element,int n){
    if(n==0)return false;
    if(arr[n-1]==element)return true;
    return LinearSearch(arr,element,n-1);
    
}


int main() {
    int arr[5]={1,2,3,4,5};
    int size=5;
    cout<<isSorted(arr,5)<<endl;
    cout<<sumArr(arr,5,0)<<endl;
    cout<<LinearSearch(arr,3,5);

}