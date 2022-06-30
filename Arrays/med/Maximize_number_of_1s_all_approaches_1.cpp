#include<iostream>
using namespace std;
int findZeroes(int arr[],int n,int m)
{
	int bestWr,bestWl;
	int wl=0;
	int wr=0;
	int zcount=0;
	int i=0;
	int bestWindow=-1;
	while(i<n)
	{
		if(zcount<=m)
		{
			wr++;
			if(arr[i]==0)
				zcount++;
		}
		if(zcount>m)
		{
			wl++;
			if(arr[i]==0)
				zcount--;
		}
		if(bestWindow<(wr-wl))
		{
			bestWindow=wr-wl;
			bestWr=wr;
			bestWl=wl;
		}
	}
	return bestWindow;
}
int main()
{
	int arr[3]={1,0,1};
	int n=3;
	int m=1;
	int fuck=findZeroes(arr,n,m);
	cout<<"Best window size is: "<<fuck;
	return 0;
}
