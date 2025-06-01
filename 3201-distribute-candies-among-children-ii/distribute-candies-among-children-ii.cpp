class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways=0;

        int maxch1=min(n,limit);
        int minch1=max(0,n-2*limit);

        for(int i=minch1;i<=maxch1;i++){
            int N=n-i;

            int maxch2=min(N,limit);
            int minch2=max(0,N-limit);

            ways+=maxch2-minch2+1;
        }
        return ways;
    }
};