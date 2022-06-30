//rotate array by all approoch
#include<iostream>
using namespace std;

int left_rotate_by_one(int arr[],int n){
	int temp=arr[0],i;
	for(i=0;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	arr[n-1]=temp;
}


int leftrotation(int arr[],int d,int n){
	for(int i=0;i<d;i++)
		left_rotate_by_one(arr,n);
}
int main()
{
	int arr[100],x,n,d;
	
	cout<<"Enter size of array: ";							//Input Size of array
	cin>>n;
	
	cout<<"\nEnter elements of array : ";		//input elements to array
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	
	cout<<"\nArray before rotation: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
	
	cout<<"\n By how many elements u want to rotate: ";
	cin>>d;
	
	leftrotation(arr,d,n);
	
	cout<<"\nArray after rotation: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	
	return 0;
}
/*
Above method takes O(n*d) time complexity
we can reduce time to O(n) in next approach
*/

// C++ program to rotate an array by
// d elements

/*Fuction to get gcd of a and b*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
//time O(n)
