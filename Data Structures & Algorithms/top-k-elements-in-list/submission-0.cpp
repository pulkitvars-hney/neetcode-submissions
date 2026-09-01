class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
       priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                while(pq.size()>k){
                    pq.pop();
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            ans.push_back(b);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};