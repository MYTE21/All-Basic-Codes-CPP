/*
---------------------
# Cumulative Sum Basic #
---------------------
Given an array arr[] , you have to generate another array sum_arr[] so that
sum_arr[i] = arr[0]+arr[1]+arr[2]+...+arr[i]

[Tips: sum_arr[i] = sum_arr[i-1]+arr[i]]

Complexity : O(n)

------
input:
------
Enter the array size : 5
Enter 5 elements of the array : 10 20 30 40 50
-------
output:
-------
The cumulative sum : 10 30 60 100 150
*/
#include<iostream>
#include<cstdio>
using namespace std ;

#define Max 10002

int arr_size ;
int arr[Max] ;
int sum_arr[Max] ;

void Cumulative_Sum ()
{
    sum_arr[0] = arr[0] ;

    for(int i=1;i<arr_size;i++)
    {
        sum_arr[i] = sum_arr[i-1] + arr[i] ;
    }
}

void Input()
{
    cout<<"Enter the array size : " ;
    cin>>arr_size ;

    cout<<"Enter "<<arr_size<<" elements of the array : " ;
    for(int i=0;i<arr_size;i++)
    {
        cin>>arr[i] ;
    }
}

void ansGenerator()
{
    cout<<"The cumulative sum : " ;
    for(int i=0;i<arr_size;i++)
    {
        cout<<sum_arr[i]<<" ";
    }
    cout<<endl ;
}

int main()
{
    Input() ;
    Cumulative_Sum() ;
    ansGenerator() ;

    return 0 ;
}

