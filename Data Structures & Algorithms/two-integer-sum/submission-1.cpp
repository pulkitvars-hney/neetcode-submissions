class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> store;
        int r;
        for(int i=0;i<nums.size();i++){
            r=target-nums[i];
            if(store.find(r)!=store.end()){
            ans.push_back(store[r]);
            ans.push_back(i);
            break;
            }
            store[nums[i]]=i;
        }
        return ans;
    }
};
