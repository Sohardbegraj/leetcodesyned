class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }
        long long l=1;
        long long new_k=-1;
        int op=-1;
        for(int i=0;i<operations.size();i++){
            l=l*2;
            if(l>=k){
                op=operations[i];
                new_k = k-l/2;
                break;
            }
        }
        char ch=kthCharacter(new_k,operations);
        if(op==0){
            return ch;
        }else{
            if(ch=='z'){
                return 'a';
            }
            return ch+1;
        }
    }
};