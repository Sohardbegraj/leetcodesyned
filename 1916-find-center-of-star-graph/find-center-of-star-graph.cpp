class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u]++;
            mp[v]++;
        }
        for(auto m:mp){
            if(m.second==n)return m.first;
        }
        return 0;
    }
};