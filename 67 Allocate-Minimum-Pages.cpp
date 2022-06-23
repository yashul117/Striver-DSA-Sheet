// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int max_no(int arr[], int n) {
        return arr[n-1];
    }
    
    int sum(int arr[], int n) {
        int sm=0;
        for(int i=0;i<n;i++) {
            sm += arr[i];
        }
        return sm;
    }
    
    bool isValid(int arr[], int n, int k, int mx) {
        int count=1;
        int sum=0;
        
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            
            if(sum>mx) {
                count++;
                sum=arr[i];
            }
        
            if(count>k) {
                return false;
            }
        }
        
        return true;
    }
    
    int findPages(int arr[], int n, int k) 
    {
        //code here
        if(n<k) {
            return -1;
        }
        
        int low=max_no(arr,n);
        int high=sum(arr,n);
        int res=-1;
        
        while(low<=high) {
            int mid=(low+high)/2;
            
            if(isValid(arr,n,k,mid)) {
                res=mid;   
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends