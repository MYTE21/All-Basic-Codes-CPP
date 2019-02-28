/**
	In a array , one element is single in number and all the other element are double in number .
	You have to find the unique number with one loop, no sorting and no extra array. 
*/
#include<iostream>
#include<cstdio>
using namespace std ;

int main()
{
	int array[] = {5, 4, 8, 11, 8, 5, 11} ; // Only 4 is one in number , others are double in number 
	int ans = array[0] ;

	for(int i=1;i<7;i++)
	{
		ans = ans^array[i] ;	// XOR ^ - same number will return 0 ; a^a == 0
	}
	cout<<"The single element : "<<ans <<endl ;

	return 0 ;
}