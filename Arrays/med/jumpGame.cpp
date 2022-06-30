/*
Given an positive integer N and a list of N integers A[]. 
Each element in the array denotes the maximum length of jump you can cover. 
Find out if you can make it to the last index if you start at the first index of the list.

Example 1:

Input:
N = 6
A[] = {1, 2, 0, 3, 0, 0} 
Output:
1
Explanation:
Jump 1 step from first index to
second index. Then jump 2 steps to reach 
4th index, and now jump 2 steps to reach
the end.
*/
#include<bits/stdc++.h>
using namespace std;
int canReach(int arr[],int n)
{
	//it is the point upto which we can jump
	int reachable=0;
	//iterate from start to end
	for(int i=0;i<n;i++)
	{
		if(reachable<i)	//that means you cant move fwd but your loop can then return 0
			return 0;
		reachable=max(reachable,i+arr[i]);	
	}
	return 1;
}
int main()
{
	int arr[]={1, 2, 0, 3, 0, 0};
	int n=6;
	int x=canReach(arr,n);
	if(x==0)
		cout<<"U can't reach to end";
	else 
		cout<<"U Can reach to end";	
	return 0;
}
