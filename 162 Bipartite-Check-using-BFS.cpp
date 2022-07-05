class Solution {
public:
    bool bipartiteBFS(int src, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> q;
        q.push(src);
        
        color[src]=1;
        
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node]) {
                if(color[it]==-1) {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        
        vector<int> color(V,-1);
        
        for(int i=0;i<V;i++) {
            if(color[i]==-1) {
                if(!bipartiteBFS(i,graph,color))
                    return false;
            }
        }
        
        return true;
    }
};