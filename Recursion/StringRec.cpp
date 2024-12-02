#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

// string ReverseString(string word,int n,string rev){
//     if(n==0)return rev;
//     rev+=word[n-1];
//     return ReverseString(word,n-1,rev);
    
// }
string ReverseString(int i,int j,string word){
    if(i>j)return word;
    swap(word[i],word[j]);
    i++;
    j--;
    return ReverseString(i,j,word);
}
bool isPalindrome(string word,int i,int j){
    if(i>j){
        if(word[i]==word[j])return true;
        else return false;
    }
    swap(word[i],word[j]);
    i++;
    j--;
    return isPalindrome(word,i,j);
}
int power(int num,int p){
    if(p==0)return 1;
    return num*power(num,p-1);
}
int main(){
    string word="A man, a plan, a canal: Panama";
    string rev="";
    int n=word.size();
    int i=0;
    int j=word.length()-1;
    int num=3;
    // string result=ReverseString(word,n,rev);
    // string result=ReverseString(i,j,word);
    // bool result=isPalindrome(word,i,j);
    int result=power(num,3);
    cout<<result<<endl;
}