class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ss(nums.begin(),nums.end());
        int ans=0;
        for(int x:ss){
            if(!ss.count(x-1)){
                int cur=x;
                int len=1;
                while(ss.count(cur+1)){
                    len++;
                    cur++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
