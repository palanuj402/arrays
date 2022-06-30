//Given an array arr[], find the maximum j - i such that arr[j] > arr[i].
//Naive approach 
//Run two loops. In the outer loop, pick elements one by one from the left. 
//In the inner loop, compare the picked element with the elements starting from the right side. 
int maxIndexDiff(int arr[], int n) 
{    
	int ans=0;    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=n-1;j>i;--j)
	        {
	            if(arr[i]<=arr[j])
	            {
	                ans=max(ans,abs(j-i));
	            }
	        }
	    }
	return ans;    
}
//this not efficient time ->O(N^2)
//Given below is efficient approach
#include<bits/stdc++.h>
using namespace std;
int maxIndexDiff(int arr[],int n)
{
	//create two auxillary array
//	int* lMin = new int[(sizeof(int) * n)];
  //  int* rMax = new int[(sizeof(int) * n)];
	//int* lMin [ ]= new int [ n];	
	//int* rMax [ ]= new int [ n];
	int lMin[n],rMax[n];
	
	//fill lMin array from left with min value
	lMin[0]=arr[0];
	for(int i=1;i<=n;i++)
	{
		lMin[i]=min(arr[i],lMin[i-1]);
	}
	
	//again fill rMax from right with max value 
	rMax[n-1]=arr[n-1];
	for(int j=n-2;j>=0;j--)
	{
		rMax[j]=max(arr[j],rMax[j+1]);
	}
	
	//compare lmin and rMax array
	int i=0,j=0;
	int maxDiff=-1;
	while(i<n &&j<n)
	{
		if(lMin[i]<rMax[j])
		{
			maxDiff=max(maxDiff,j-i);
			j++;
		}
		else
		{
			i++;
		}
	}
	return maxDiff;
}
int main()
{
	int arr[]={82, 63, 44 ,74 ,82 ,99 ,82};
	int n=7;
	int diff=maxIndexDiff(arr,n);
	cout<<"Max diff is: "<<diff;
	return 0;
}
//This is the efficient approach 
//time complexity O(n)
//space complexity O(n)
