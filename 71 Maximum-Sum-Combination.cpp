vector<int> Solution::solve(vector<int> &A, vector<int> &B, int k) {
    int n=A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    
    pq.push({A[n-1]+B[n-1], {n-1, n-1}});
    st.insert({n-1, n-1});
    
    vector<int> ans;
    for(int count=0;count<k;count++) {
        auto temp=pq.top();
        pq.pop();
        
        ans.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        
        if(st.find({i-1, j})==st.end()) {
            pq.push({A[i-1]+B[j], {i-1, j}});
            st.insert({i-1, j});
        }
        
        if(st.find({i, j-1})==st.end()) {
            pq.push({A[i]+B[j-1], {i, j-1}});
            st.insert({i, j-1});
        }
    }
    
    return ans;    
}
