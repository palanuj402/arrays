/*
Stock buy and sell
time complexity O(n)
space complexity O(1)
*/
#include<iostream>
using namespace std;
int buy_Sell(int arr[],int n)
{
	int min_price=arr[0];
	int max_cost=0;
	int cost=0;
	
	for(int i=0;i<n;i++)
	{
		min_price=min(min_price,arr[i]);	
			
		cost=arr[i]-min_price;
		
		max_cost=max(cost,max_cost);
		
	}
	
	return max_cost;
}

int main()
{
	int arr[]={7,1,5,3,6,4};
	int n=6;
	
	
	int fuck=buy_Sell(arr,n);
	cout<<"boihhhhhhhhhhh: "<<fuck;
	
	return 0;
}
