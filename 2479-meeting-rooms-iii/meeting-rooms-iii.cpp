class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        vector<int>roomcount(n,0);
        vector<long long>roomAvailAt(n,0);

        for(vector<int>&meet:meetings){
            int start=meet[0];
            int end=meet[1];
            bool found=false;

            long long earlyEndroomTime= LLONG_MAX;
            int earlyroom=0;

            for(int room=0;room<n;room++){
                if(roomAvailAt[room]<=start){
                    found=true;
                    roomAvailAt[room]=end;
                    roomcount[room]++;
                    break;
                }
                if(roomAvailAt[room]<earlyEndroomTime){
                    earlyEndroomTime=roomAvailAt[room];
                    earlyroom=room;
                }
            }
            if(!found){
                roomAvailAt[earlyroom]+=(end-start);
                roomcount[earlyroom]++;
            }
        }
        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomcount[room] > maxUse) {
                maxUse = roomcount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};