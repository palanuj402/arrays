/*
Given an array Arr of N numbers and another number target, find three integers in the array such that the sum is closest to target. Return the sum of the three integers.

Example 1:

Input:
N = 6, target = 2
A[] = {-7,9,8,3,1,1}
Output: 2
Explanation: There is one triplet with sum
2 in the array. Triplet elements are -7,8,
1 whose sum is 2.
*/
//--->Naive approach 
#include<bits/stdc++.h>
using namespace std;

int triple(int arr[],int target,int n)
{
	//simple approach is 
	//take run trhee loops and find sum is less target or not
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if( abs( target - ans ) > abs( target - ( arr[i] + arr[j] + arr[k] ) ) )
					ans=arr[i] + arr[j] + arr[k];
			}
		}
	}
	return ans;
	
}
int main()
{
	int arr[]={-7,9,8,3,1,1};
	int target=2;
	int n=6;
	int x=triple(arr,target,n);
	cout<<x;
	
	return 0;
}
//this is not an efficient approach 
//time complexity O(n^3)
//space complexity O(1)
/*

*/
