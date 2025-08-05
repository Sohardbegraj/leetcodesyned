class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int count=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    cout<<fruits[i]<<" "<<baskets[j];
                    count--;
                    baskets[j]=0;
                    break;
                }
            }
        }
        return count;
    }
};