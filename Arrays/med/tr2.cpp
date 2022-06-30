//in this we have to find max profit but after buying we have to sell 
#include<iostream>
using namespace std;
void stockBuySell(int price[], int n)
{
	int profit=0;
	for(int i=1;i<n;i++)
	{
		if(price[i]>price[i-1])
		{
			cout<<i-1<<" "<<i<<endl;
			profit+=(price[i]-price[i-1]);
		}
	}
	cout<<"\nMax profit: "<<profit;
}
// Driver code
int main()
{
    // Stock prices on consecutive days
    int price[] = { 5,2,6,1,4,7,3,6 };
    int n = sizeof(price) / sizeof(price[0]);

    // Function call
    stockBuySell(price, n);

    return 0;
}

// below approach is using local maxima nd minima it can be solved using both approaches

// C++ Program to find best buying and selling days
#include <bits/stdc++.h>
using namespace std;

// This function finds the buy sell
// schedule for maximum profit
void stockBuySell(int price[], int n)
{
    // Prices must be given for at least two days
    if (n == 1)
        return;

    // Traverse through given price array
    int i = 0;
    while (i < n - 1) {

        // Find Local Minima
        // Note that the limit is (n-2) as we are
        // comparing present element to the next element
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;

        // If we reached the end, break
        // as no further solution possible
        if (i == n - 1)
            break;

        // Store the index of minima
        int buy = i++;

        // Find Local Maxima
        // Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i - 1]))
            i++;

        // Store the index of maxima
        int sell = i - 1;

        cout << "Buy on day: " << buy
             << "\t Sell on day: " << sell << endl;
    }
}

// Driver code
int main()
{
    // Stock prices on consecutive days
    int price[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);

    // Function call
    stockBuySell(price, n);

    return 0;
}

// This is code is contributed by rathbhupendra


