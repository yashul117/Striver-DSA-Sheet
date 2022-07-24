//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        // Code here
        // vector<pair<int,int>> graph[];
        
        for(int i=0;i<V;i++) {
            
        }
        
        priority_queue<pair<int,int>> pq;
        
        vector<int> distTo(V,INT_MAX);
        
        distTo[source]=0;
        
        pq.push(make_pair(0,source));
        
        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            for(int i=0;i<adj[node].size();i++) {
                int res=adj[node][i][0];
                int wt=adj[node][i][1];
                
                if(wt+distTo[node]<distTo[res]) {
                    distTo[res]=distTo[node]+wt;
                    pq.push({-1*distTo[res],res});
                }
            }
        }
        
        return distTo;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends