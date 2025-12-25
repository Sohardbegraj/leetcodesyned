class Solution {
public:
    void dfs(int node,unordered_map<int,list<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,list<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};