/*
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

*/
//  --->Naive approach
// 1.first iterate all the elements in array
//2. for each element check in left is there any maximum height and in right also
//3. update ans with left right max values 
//time complexity O(n^2)
//space complexity O(1)
//the below code also not give right ans  for some cases
#include<bits/stdc++.h>
using namespace std;

int trappingWater(int arr[],int n)
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		//store first ele in left
		int left=arr[i];
		//check for largest ele in left
		for(int j=0;j<n-1;j++)
			left = max(left , arr[ j ] ) ;
		
		//store first ele in right
		int right=arr[i];
		//check for largest ele in right
		for(int k=i+1;k<n;k++)
			right=max( right , arr [ k ] ) ;
		
		ans = ans + ( min ( left , right ) - arr [ i ] ) ;		
	}
	return ans;
}

int main()
{
	int arr[]={8 ,8 ,2 ,4 ,5 ,5 ,1};
	int n=7;
	int x=trappingWater(arr,n);
	cout<<x;
	return 0;
}
//------>2nd approach 
//1. create two array left and right 
//2. fill left array from left with max values and right array with max values 
//3. iterate a loop fro  strt to end and update your ans with ans+=( min(left[i],right[i])-arr[i])

int trappingWater(int arr[], int n)
{
    int ans=0;
    int left[n],right[n];
    
    //fill left array from left to right with max value
    left[0]=arr[0];
    for(int i=1;i<n;i++)
        left[i]=max(left[i-1],arr[i]);
        
    //fill right array from right to left with max values
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        right[i]=max(right[i+1],arr[i]);
   
    //now put value in ans by comparing left and right aux array
    for(int i=0;i<n;i++)
        ans=ans+(min(left[i],right[i])-arr[i]);
	
	return ans;
}
//time complexity O(n)
//space complexity O(n)

//---->3 approach
/*
Space Optimization for the above Solution: 
Instead of maintaining two arrays of size n for storing the left and a right max of each element, maintain two variables to store the maximum till that point. 
Since water trapped at any element = min(max_left, max_right) - arr[i]. 
Calculate water trapped on smaller elements out of A[lo] and A[hi] first and move the pointers till lo doesn't cross hi.
*/
int findWater(int arr[], int n)
{
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}

