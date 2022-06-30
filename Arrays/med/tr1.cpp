#include<iostream>
using namespace std;
void buy_Sell(int arr[],int n)
{
	int min_price=arr[0];
	int max_cost=0;
	int cost=0;
	
	for(int i=0;i<n;i++)
	{
		min_price=min(min_price,arr[i]);	
			
		cost=arr[i]-min_price;
		if(cost!=0)
		{
			cout<<min_price<<" "<<i<<endl;
			
		}
		//min_price++;
		
		max_cost=max(cost,max_cost);
		
		
	}
	
	//return max_cost;
}

int main()
{
	int arr[]={7,1,5,3,6,4};
	int n=6;
	
	
	buy_Sell(arr,n);
	//cout<<"boihhhhhhhhhhh: "<<fuck;
	
	return 0;
}
