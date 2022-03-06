// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b) {
        // return a.value/a.weight > b.value/b.weight;
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;

        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // double val[n];

        // for(int i=0;i<n;i++) {
        //     val[i]=arr[i].value/arr[i].weight;
        // }

        sort(arr, arr + n, cmp);

        double ans = 0;
        for (int i = 0; i < n && W; i++) {
            if (arr[i].weight > W) {
                ans += ((double)arr[i].value / (double)arr[i].weight) * (double)W;
                W = 0;
            }
            else {
                ans += (double)arr[i].value;
                W -= arr[i].weight;
            }
        }
        return ans;
    }

};


// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--) {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends