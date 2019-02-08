#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std ;

#define endl '\n'
#define Max 100002

void Build_Permutation (char arr[] , int lo , int hi)
{
    if(lo == hi)
    {
        cout<<setw(26)<<arr<<endl;
        return ;
    }

    for(int i=lo;i<=hi;i++)
    {
        swap(arr[lo] , arr[i]) ;
        Build_Permutation(arr , lo+1 , hi) ;
        swap(arr[lo] , arr[i]) ;
    }

}

int main()
{

    while(true)
    {
        cout<<":::::::::::::::::::::::::::::"<<endl;
        cout<<"::: Find All Permutations :::"<<endl;
        cout<<":::::::::::::::::::::::::::::"<<endl<<endl;

        int num ;
        char word[Max] ;

        cout<<"Enter size of the word : ";
        cin>>num ;

        cout<<"Enter the word : ";
        for(int i=0;i<num;i++)
        {
            cin>>word[i] ;
        }

        cout<<"All Permutations are : "<<endl;
        Build_Permutation(word , 0 , num-1) ;
        cout<<endl;
    }

    return 0 ;
}
