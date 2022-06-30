/*
Given an array arr[] of N integers arranged in a circular fashion. 
Your task is to find the maximum contiguous subarray sum.

Example 1:
Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22

first Method:
1. find sum of whole array
2. invert all the array with -ve sign
3. now find max sum using kadane's algo
4. now find sum as array sum + max sum 
*/
int kadane(int arr[],int n)
    {
    	int current_sum=0;
    	int max_sum=INT_MIN;
    	for(int i=0;i<n;i++)
    	{
    		current_sum+=arr[i];
    		if(current_sum>max_sum)
    			max_sum=current_sum;
    		if(current_sum<0)
    			current_sum=0;	
    	}
    	return max_sum;
    } 
    int circularSubarraySum(int arr[], int num)
    {
        int sum=0;
        for(int i=0;i<num;i++)
            sum+=arr[i];
            
        for(int i=0;i<num;i++)
            arr[i]=-arr[i];
        
        int max_sum=kadane(arr,num);
        
        return max_sum+sum;
    }

/*
second method:
1. create 5 variable
2. one array_sum , 1 current_min and current_max and 1 max_sum and 1 min_sum
3. now iterate 

*/	

int circularSubarraySum(int arr[], int num)
{
    int arr_sum=0;
    for(int i=0;i<num;i++)
        arr_sum+=arr[i];
    
    int c_max=arr[0],c_min=arr[0];
    int max_sum=arr[0],min_sum=arr[0];
    
    for(int i=1;i<num;i++)
    {
        c_max=max(c_max+arr[i],arr[i]);
        max_sum=max(max_sum,c_max);
        
        c_min=min(c_min+arr[i],arr[i]);
        min_sum=min(min_sum,c_min);
    }
    if(arr_sum==min_sum)
        return max_sum;
        
    return max(max_sum,(arr_sum-min_sum));    
}
