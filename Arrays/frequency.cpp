#include<iostream>
using namespace std;
void f1(long long int arr[],int N,int P)
{
	 for(int i=0;i<N;i++)
        {
            int count =0;
            for(int j=1;j<P;j++)
            {
                if(j==arr[i])
                {
                    count++;
                }
                    
            }
            cout<<count<<" ";
        }	
}
int main()
{
	long long int arr[]={2,3,2,3,5};
	int n=5;
	int P=5;
	f1(arr,n,P);
	return 0;
}

