class Solution {
public:
bool isSubfolder(const string& folder, const string& parent) {
    string prefix = parent + "/";
    return folder.size() > prefix.size() &&
           folder.compare(0, prefix.size(), prefix) == 0;
}
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        sort(folder.begin(), folder.end());
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || !isSubfolder(folder[i],ans.back())){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};