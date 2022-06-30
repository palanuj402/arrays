/*
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). 
The digits are stored such that the most significant digit is first element of array.
 
Example 1:

Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output
Example 2:

Input: 
N = 3
arr[] = {9,9,9}
Output: 
1 0 0 0
Explanation:
999+1 = 1000, and so the output
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int arr[n];
	cout<<"Enter size of array: ";
	cin>>n;
	cout<<"Enter elements of array: ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	arr[n-1]=arr[n-1]+1;				//incrementing last ele by 1
	int carry=arr[n-1]/10;				//adding carry if last index is 9
	arr[n-1]=arr[n-1] % 10;				//making last index 0
	//iterate from 2nd last index
	for(int i=n-2;i>=1;i--)
	{
		if(carry==1)	//if carry still equals to 1 then repeats the above process	
		{
			arr[i]+=1;
			carry=arr[i]/10;
			arr[i]=arr[i] %10;
		}
	}
	//if still carry has value 1
	if(carry==1)
	{
		arr[0]=1;			//make 1st elemnet 1 
		n++;				//increase size of array
	}
	
	//print array
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}

//Same problem can be done with vectors as well

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        
        arr[N-1]+=1;
        int carry=arr[N-1] / 10;
        arr[N-1]=arr[N-1] % 10;
        
        for(auto i=N-2;i>=0;i--)
        {
            if(carry==1)
            {
                arr[i]+=1;
                carry=arr[i]/10;
                arr[i]=arr[i]%10;
                
            }
        }
        if(carry==1)
        {
            arr.insert(arr.begin(),1);
        }
        
        return arr;
        
    }
};

//both the cases time complexity is O(n)
