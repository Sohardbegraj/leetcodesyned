class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freetime;
        freetime.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime[n-1]);
        
        int i=0;
        int j=0;
        int m=freetime.size();
        int maxsum=0;
        int currsum=0;
        while(j<m){
            currsum+=freetime[j];
            if(i<m && j-i+1>k+1){
                currsum-=freetime[i];
                i++;
            }
            maxsum=max(maxsum,currsum);
            j++;
        }
        return maxsum; 
    }
};