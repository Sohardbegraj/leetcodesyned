class Solution {
public:
    string sorted(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
       if(n==1){
        return true;
       }
       string s= sorted(n);

       for(int i=0;i<=29;i++){
        if(s==sorted(1<<i)){
            return true;
            break;
        }
       }
       return false;
       
    }
};