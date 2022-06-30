/*
NAIVE APPROACH
first sort the elemnts in array in ascending order
then simply find consecutive subarray in array

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
	int ans=0;
	int count=0;
	//first sort array
    sort(arr,arr+N);
    
    
    //now push only first elemnts in vector
    vector<int> v1;
    
    v1.push_back(arr[0]);
    //in order to remove duplicacy in array
    for(int i=1;i<=N;i++)
    {
    	if(arr[i]!=(arr[i-1]))
    		v1.push_back(arr[i]);
	}
	//now check elements are consecutive or not
	for(int i=0;i<v1.size();i++)
	{
		if(i>0 && v1[i]==(v1[i-1]+1))
			count++;
		else 
			count=1;
		
		ans=max(ans,count);	
	}
	return ans;
}

int main()
{
	int arr[]={1,2,2,3};
	int n=4;
	
	int x=findLongestConseqSubseq(arr, n);
	
	cout<<"boihhhhhhhhhhh: "<<x;
	
	return 0;
}
//Time complexity O(nlogn)
//space complexity O(1)
//It can be solved using hash and priority queue as well in O(n) time
// C++ program to find longest
// contiguous subsequence
#include <bits/stdc++.h>
using namespace std;

// Returns length of the longest
// contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

// Driver code
int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}
