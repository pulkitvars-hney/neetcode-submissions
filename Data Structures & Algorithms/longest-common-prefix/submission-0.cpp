class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0; 
        int n=strs.size()-1;
        while(i<strs[0].size()&&i<strs[n].size()){
            if(strs[0][i]!=strs[n][i]){
                break;
            }
           i++;
        }
        return strs[0].substr(0,i);
    }
};