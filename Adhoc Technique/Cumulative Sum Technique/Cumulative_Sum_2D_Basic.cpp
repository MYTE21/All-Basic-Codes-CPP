/*
-------------------------
#Cumulative Sum 2D Basic#
-------------------------
Given a matrix (or 2D array) a[][] of integers, find prefix sum matrix sum_arr[][] for it.
[
The general formula:
sum_arr[i][j] = sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1] + arr[i][j]
]
------
input:
------
Column number of the matrix : 5
Row number of the matrix : 5
Enter the cells values of the matrix (5x5) :
1 2 2 4 1
3 4 1 5 2
2 3 3 2 4
4 1 5 4 6
6 3 2 1 3

-------
output:
-------
Cumulative sum 2D array is :
1 3 5 9 10
4 10 13 22 25
6 15 21 32 39
10 20 31 46 59
16 29 42 58 74
*/
#include<iostream>
#include<cstdio>
using namespace std ;

#define Max 1002

int arr[Max][Max] ;
int sum_arr[Max][Max] ;
int arr_sizeX ;
int arr_sizeY ;

void Cumulative_Sum_2D ()
{
    sum_arr[0][0] = arr[0][0] ;

    //Filling first row
    for(int i=1;i<arr_sizeX;i++)
    {
        sum_arr[0][i] = sum_arr[0][i-1]+arr[0][i] ;
    }
    //Filling first column
    for(int i=1;i<arr_sizeY;i++)
    {
        sum_arr[i][0] = sum_arr[i-1][0]+arr[i][0] ;
    }

    //Update all the cells using general formula
    for(int i=1;i<arr_sizeX;i++)
    {
        for(int j=1;j<arr_sizeY;j++)
        {
            sum_arr[i][j] = sum_arr[i-1][j]+sum_arr[i][j-1]-sum_arr[i-1][j-1]+arr[i][j] ;
        }
    }
}

void Input()
{
    cout<<"Column number of the matrix : " ;
    cin>>arr_sizeX ;
    cout<<"Row number of the matrix : " ;
    cin>>arr_sizeY ;

    cout<<"Enter the cells values of the matrix ("<<arr_sizeX<<"x"<<arr_sizeY<<") : "<<endl ;
    for(int i=0;i<arr_sizeX;i++)
    {
        for(int j=0;j<arr_sizeY;j++)
        {
            cin>>arr[i][j] ;
        }
    }
}

void ansGenerator()
{
    cout<<"Cumulative sum 2D array is : "<<endl ;
    for(int i=0;i<arr_sizeX;i++)
    {
        for(int j=0;j<arr_sizeY;j++)
        {
            cout<<sum_arr[i][j]<<" ";
        }
        cout<<endl ;
    }
}

int main()
{
    Input() ;
    Cumulative_Sum_2D() ;
    ansGenerator() ;

    return 0 ;
}
