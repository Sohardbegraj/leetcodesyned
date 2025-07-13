class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
       int n=players.size();
       int m=trainers.size();
       
       int ans=0;
       
       sort(trainers.begin(),trainers.end());
       sort(players.begin(),players.end());
       int i=0;int j=0;
       while(i<n && j<m){
            if(players[i]<=trainers[j]){
                ans++;
                trainers[j]=-1;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
       return ans;
    };
};