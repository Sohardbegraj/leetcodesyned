class Solution {
public:
    vector<pair<int, int>>t={{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    unordered_map<int, unordered_map<int, double>> memo;
    double prob(double A, double B){
       if(A<=0 && B<=0){
        return 0.5;
       }
        if(A<=0){
        return 1.0;
       }
       if(B<=0){
        return 0.0;
       }
        if (memo.count(A) && memo[A].count(B)) {
            return memo[A][B];
        }
       double probabilty=0.0;
       for(auto &p:t){
        int A_used=p.first;
        int B_used=p.second;
        probabilty+=prob(A-A_used,B-B_used);
       }
       return memo[A][B] =0.25*probabilty;
    };
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
       return prob(n,n);       
    }
};