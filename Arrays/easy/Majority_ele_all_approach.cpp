//Given an array A of N elements. Find the majority element in the array. 
//A majority element in an array A of size N is an element that appears more than N/2 times in the array

#include<iostream>
using namespace std;

int majorityElement(int a[], int size)
{
    int a1[size],i,j;						//a1 is array of size n
        for(i=0;i<size;i++)
        {
            int count=0;
            for(j=i+1;j<size;j++)
            {
                if(a[i]==a[j])
                    count++;					//if element found increment count
            }
            
            if(count>=size/2)					//if count has size more than size /2
            return a[i] ;						//return element
        }
        return -1;								//else return -1
}
int main()
{
	//driver code 
	return 0;
}
//time complexity of above code is O(n^2)
//Below is the optimal code which takes O(N) time

#include<iostream>
using namespace std;
int f1(int a[],int n)
{
	int m_index=0,count=1,m_count=0;
	for(int i=1;i<n;i++)
	{
		if( a[m_index] == a[i] )
			count++;
		else
			count--;
		if(count==0){
			m_index=i;
			count=1;
		}		
	}								//this loop for counting and finding majority element
		
	for(int i=0;i<n;i++)
	{
		
		if( a[m_index] == a[i] )
			m_count++;	
	}								//m_count for checking is element >size/2
	if(m_count>n/2)					
		return a[m_index];			//return that element 
		

	return -1;						//else -1
}
int main()
{
    int arr[] = {1,2,1,2,1,1,2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int x=f1(arr,n);
    cout<<x;

    return 0;
}
