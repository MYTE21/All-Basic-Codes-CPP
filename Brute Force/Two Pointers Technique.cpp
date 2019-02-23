/*input
70
6
10 20 35 50 75 80
*/

/**
Two pointer is really an easy and effective technique
which is typically used for searching pairs in a sorted arrays.

Given a sorted array A (sorted in ascending order), having N integers,
find if there exists any pair of elements (A[i], A[j])
such that their sum is equal to X.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std ;

#define Max 100002
int elementOne, elementTwo ;

bool isPairSum(int arr[], int arraySize, int pairSum)
{
    int i = 0 ;
    int j = arraySize-1 ;

    while(i<j)
    {
        if(arr[i]+arr[j] == pairSum)
        {
            elementOne = arr[i] ;
            elementTwo = arr[j] ;
            return true ;
        }
        else if(arr[i]+arr[j] < pairSum) i++ ;
        else j-- ;
    }
    return false ;
}

int main()
{
    int pairSum ;
    int arraySize ;
    int arr[Max] ;

    cin>> pairSum ;
    cin>> arraySize ;

    for(int i=0;i<arraySize;i++)
    {
        cin>>arr[i] ;
    }
    sort(arr, arr+arraySize) ;

    bool ans = isPairSum(arr, arraySize, pairSum) ;

    ans == true ? cout<<"Pair Found : "<<elementOne<<" + "<<elementTwo<<" = "<<pairSum<<endl
                : cout<<"No Pair Exist"<<endl ;

    return 0 ;
}
