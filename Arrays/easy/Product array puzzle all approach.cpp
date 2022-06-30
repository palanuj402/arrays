/*
Algo-1
1. make 3 arrays prefix suffix and product 
2.initialize first and last element of prefix and sufix to 1
3.traverse from 1 to size 
	update prefix as prefix[i]=arr[i-1]*prefix[i-1]
4.again traverse from last second to first 
	update suffix as suffix[i]=arr[i+1]*suffix[i+1]
3.again traverse from 0 to size-1 
	and store product of  prefix and suffix
	
Time=O(n)
Space=O(n)			
*/
#include<iostream>
using namespace std;
void f1(long long int arr[],int n)
{
	int prefix[n],suffix[n],product[n];				//created two array prefix and suffix and product array to store product of prefix and suffix
	prefix[0]=1;		//first ele of prefix is 1
	suffix[n-1]=1;		//last ele of suffix is 1
	for(int i=1;i<n;i++)		//traverse from 1st ele nd store product of arr to prefix
	{
		prefix[i]=arr[i-1] * prefix[i-1];
	}
	for(int i=n-2;i>=0;i--)		//traverse from last to store product of arr to suffix
	{
		suffix[i]=arr[i+1] * suffix[i+1];
	}
	for(int i=0;i<n;i++)		//traverse from start to end and store prod of prefix nd suffix in product array
	{
		product[i]=prefix[i] * suffix[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<product[i]<<" ";
	}
}
int main()
{
	long long int arr[]={10,3,5,6,2};
	int n=5;
	f1(arr,n);
	return 0;
}

/*
Algo - 2
1.initialize product array 1st ele to 1 and temp var to 1
2.traverse array from start to N-1
	2.1 update product[i] as temp
	2.2 temp =temp * array[i]
3.Again temp=1
4.traverse array from end to 0
	4.1 update product[i] as temp
	4.2	temp =temp * array[i]
	
Time=O(n)
Space=O(n)			
	
*/


void f1(long long int arr[],int n)
{
	long long int pro[n];
	int temp=1;
	//storing initial values to product array
	for(int i=0;i<n;i++)
	{
		pro[i] = temp;
		temp = temp * arr[i];
	}
	temp=1;
	//storing last values to product array
	for(int i=n-1;i>=0;i--)
	{
		pro[i] *= temp;
		temp = temp * arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<pro[i]<<" ";
	}
			
}

//using vectors 
//time O(n)
//space O(n)
vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
{
    long long int temp=1;
    vector<long long int> pro;

    if(n<1)
        return pro;
    //pehle start se saare push krdo vector mein
    for(int i=0;i<n;i++)
    {
        temp=temp*nums[i];
        pro.push_back(temp);
    }
    
    //fir last se push krddo vector mein
    temp=1;
    for(int i=n-1;i>0;i--)
    {
        pro[i]=pro[i-1]*temp;
        temp=temp*nums[i];
    }
    pro[0]=temp;
    
    return pro;
}

/*
Algo - 3
using pow function
1.Make variable total=1
2.iterate from 0 to n-1 and stroe product of each element to total
3.now again iterate from 0 to n-1 and print total as total*pow(arr[i],-1)

time=O(n)
space=O(1)

*/
void f1(int arr[],int n)
{
	int total=1;
	for(int i=0;i<n;i++)
	{
		total*=arr[i];		//store all product of  elements to total 
	}
	for(int i=0;i<n;i++)
	{
		cout<<total*(int)pow(arr[i],-1)<<" ";
	}
	
}
