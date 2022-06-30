/*
Given an array arr[] of N positive integers. Find maximum value of |arr[i] – arr[j]| + |i – j|, (0 <= i, j <= N – 1)

Example 1:

Input:
N = 4 
arr[] = {1, 2, 3, 1}
Output:
4
Explanation:
Choosing i=0 and j=2, will result in
|1-3|+|0-2| = 4, which is the maximum
possible value.
*/
#include<bits/stdc++.h>
using namespace std;
int findMax(int arr[],int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans=max(ans, abs( arr[i] - arr[j] ) + abs(i - j) );			//abs function return same value with +ve sign
																		//max funct return max value b/w two values 
	
	return ans;		
}


int main()
{
	int arr[]={1,2,3,8,6};
	int n=5;
	
	int mera=findMax(arr,n);
	cout<<"Max is : "<<mera;
	return 0;
}

/*
Above is the naive approach 
time complexity O(n^2)
space complexity O(1)
*/

/*
Below is the efficient approach 
time complexity O(n)
space complexity O(n)

First of all lets make four equations by removing the absolute value signs ("|"). 
The following 4 equations will be formed, and we need to find the maximum value of these equations and that will be our answer. 


1. arr[i] - arr[j] + i - j = (arr[i] + i) - (arr[j] + j)
2. arr[i] - arr[j] - i + j = (arr[i] - i) - (arr[j] - j)
3. -arr[i] + arr[j] + i - j = -(arr[i] - i) + (arr[j] - j)
4. -arr[i] + arr[j] - i + j = -(arr[i] + i) + (arr[j] + j)

Observe the equations (1) and (4) are identical. Similarly, equations (2) and (3) are identical.
Now the task is to find the maximum value of these equations.
So the approach is to form two arrays, first_array[], it will store arr[i] + i, 0 <= i < n, second_array[], it will store arr[i] - i, 0 <= i < n. 
Now our task is easy, we just need to find the maximum difference between the two values of these two arrays.
For that, we find the maximum value and minimum value in the first_array and store their difference: 
ans1 = (maximum value in first_array - minimum value in first_array) 
Similarly, we need to find the maximum value and minimum value in the second_array and store their difference: 
ans2 = (maximum value in second_array - minimum value in second_array) 
Our answer will be a maximum of ans1 and ans2.
*/
int maxValue(int arr[], int N) 
{
    int a[N],b[N];
    //to fill a and b array
    for(int i=0;i<N;i++)
    {
        a[i]=arr[i]+i;
        b[i]=arr[i]-i;
    }
    //now find min and max in a array
    int x=a[0],y=a[0];
    for(int i=0;i<N;i++)
    {
        if(a[i]<x)
            x=a[i];
        
        if(a[i]>y)
            y=a[i];
    }
    int ans=y-x;
    
    //now find min and max in b array
    int x1=b[0],y1=b[0];
    for(int i=0;i<N;i++)
    {
        if(b[i]<x1)
            x1=b[i];
        
        if(b[i]>y1)
            y1=b[i];
    }
    int ans2=y1-x1;
    
return max(ans,ans2);
                    
}
