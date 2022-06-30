/*
Given two sorted arrays arr1 and arr2 of size M and N respectively and an element K. 
The task is to find the element that would be at the k’th position of the final sorted array. 
*/

//-->Naive approach
// 1. merge both sorted array elements in single array
// 2. simply return k-1th index of new merged sorted array as index start from 0

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int arr3[n+m];
    int i,j,l;
    i=j=l=0;
    //simply merge two arrays
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[l]=arr1[i];
            i++;
            l++;
        }
        else
        {
            arr3[l]=arr1[j];
            j++;
            l++;
        }
    }
    while(i<n)
    {
        arr3[l]=arr1[i];
        i++;
        l++;
    }
    while(j<m)
    {
        arr3[l]=arr1[j];
        j++;
        l++;
    }
    
    return arr3[k-1];
}
//Time Complexity: O(n) 
//Auxiliary Space : O(m + n) 
//it is not efficient for some cases 
//we can solve above problem simply by removing extra space i.e Arr[n+m]

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    
    int i,j,l;
    i=j=l=0;
    //simply merge two arrays
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            l++;
            if(l==k)
                return arr1[i];
            i++;    
        }
        else
        {
            l++;
            if(l==k)
                return arr2[j];
            j++;
        }
    }
    //if arr2 is completed
    while(i<n)
    {
        l++;
        if(l==k)
            return arr1[i];
        i++;
    }
    //if arr1 is completed
    while(j<m)
    {
        l++;
        if(l==k)
            return arr2[j];
        j++;
    }
}

//there can be many more approaches to make it efficient 
//there are 3 more approaces (Divide nd conquer) refer gfg
