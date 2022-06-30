#include<iostream>
using namespace std;
void rearrange(int arr[],int n)
{
	int result[n];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			result[i]=arr[i];
		}
		else
			result[i+1]=arr[i];
//		if(arr[i]<0)
//		{
//			result[i+1]=arr[i];
//		}
	}
	
	cout<<"\nElements after arrange are : ";	
	for(int i=0;i<n;i++)
		cout<<result[i]<<" ";
}
int main()
{
	int n,arr[n];
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Enter elemnts: ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cout<<"Elements are : ";	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
	
	rearrange(arr,n);
	
	return 0;
}

