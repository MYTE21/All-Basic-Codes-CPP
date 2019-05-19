/*
---------------------
# Cumulative Sum 1D #
---------------------
Given an array arr[] , you have to generate another array sum_arr[] so that
sum_arr[i] = arr[0]+arr[1]+arr[2]+...+arr[i]
and find the sum among index_1 to index_2.
ans will be : ans = arr[index_1]+arr[index_1+1]+...+arr[index_2-1]+arr[index_2] ;

[Tips: ans = sum_arr[index_2]-sum_arr[index_1-1]]

Complexity : O(n)

------
input:
------
Enter the array size : 5
Enter 5 elements of the array : 10 20 30 40 50
Get the summation among index "a" and "b" : (a) 1
                                            (b) 3
-------
output:
-------
The sum between 1 and 3 is : 90
*/
#include<iostream>
#include<cstdio>
using namespace std ;

#define Max 10002

int arr_size ;
int arr[Max] ;
int sum_arr[Max] ;
int index_1, index_2 ;

void Cumulative_Sum_1D ()
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

    cout<<"Get the summation among index \"a\" and \"b\" : (a) " ;
    cin>>index_1 ;
    cout<<"\t\t\t\t\t    (b) " ;
    cin>>index_2 ;
}

void ansGenerator()
{
    int ans = sum_arr[index_2]-sum_arr[index_1-1] ;

    cout<<"The sum between "<<index_1<<" and "<<index_2<<" is : "<<ans<<endl ;
}

int main()
{
    Input() ;
    Cumulative_Sum_1D() ;
    ansGenerator() ;

    return 0 ;
}
