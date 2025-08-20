class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int end=0;
        int ans=0;
        for(int i=0;i<piles.size();i++){
           end=max(end,piles[i]);
        }
        while(st<=end){
            int mid=st+(end-st)/2;
            long long time=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                    time+=piles[i]/mid;
                }
                else time+=piles[i]/mid +1;

                if(time>h) break;
            }
            if(time>h){
                st=mid+1;
            }
            else if(time<=h){
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};