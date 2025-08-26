class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        double diag=0.0;
        int area=0;
        for(int i=0;i<n;i++){
            int len=dimensions[i][0];
            int width=dimensions[i][1];
            int temp=(len*len)+(width*width);
            
            if(diag<sqrt(temp)){
                diag=sqrt(temp);
                area=len*width;
            }else if (diag == sqrt(temp)) {
                area = max(area, len * width);
            }
        }
        return area;
    }
};