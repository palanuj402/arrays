/*Merge Without Extra Space
Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)
*/

//efficient algo
/*
1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 

2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively

    if arr1[i] is less than arr2[j]

        increment i

    else

        swap the arr2[j] and arr1[k]

        increment j and decrement k



3) Sort both arr1 and arr2 

*/


 void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int i,j,k;
    i=0,j=0,k=n-1;
    while(i<=k && j<m)
    {
        if(arr1[i] < arr2[j])
            i++;
        else 
        {
            swap(arr1[k--],arr2[j++]);
        }
    }
    //sort array1
    sort(arr1,arr1+n);
    
    //sort array2
    sort(arr2,arr2+m);
}
        
//2nd is not so efficient 
//it uses both merge and insertion sort
//but it is time taking algo        
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int i,j;
    i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i] <= arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i++;
            
            if((arr2[j+1]<arr2[j]) && (j<m-1) )
            {
                int temp=arr2[j];
                int tj=j+1;
                while(arr2[tj]<temp && tj<m)
                {
                    arr2[tj-1]=arr2[tj];
                    tj++;
                }
                arr2[tj-1]=temp;
            }
        }
    }
}



















#include <bits/stdc++.h>
using namespace std;

void mergeArray(int arr1[], int arr2[],
				int n, int m)
{
	
	// Now traverse the array1 and if
	// arr2 first element
	// is less than arr1 then swap
	for(int i = 0; i < n; i++)
	{
		if (arr1[i] > arr2[0])
		{
			
			// Swap
			int temp = arr1[i];
			arr1[i] = arr2[0];
			arr2[0] = temp;

			// After swapping we have to sort the array2
			// again so that it can be again swap with
			// arr1

			// We will store the firstElement of array2
			// and left shift all the element and store
			// the firstElement in arr2[k-1]
			int firstElement = arr2[0];

			int k;
			
			for(k = 1;
				k < m && arr2[k] < firstElement;
				k++)
			{
				arr2[k - 1] = arr2[k];
			}
			arr2[k - 1] = firstElement;
		}
	}
	
	// Read the arr1
	for(int i = 0; i < n; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	// Read the arr2
	for(int i = 0; i < m; i++)
	{
		cout << arr2[i] << " ";
	}
}

// Driver Code
int main()
{
	int arr1[] = { 1, 3, 5, 7 };
	int arr2[] = { 0, 2, 6, 8, 9 };
	int n = sizeof(arr1)/sizeof(arr1[0]), m = sizeof(arr2)/sizeof(arr2[0]);
	
	mergeArray(arr1, arr2, n, m);
}

// This code is contributed by yashbeersingh42

