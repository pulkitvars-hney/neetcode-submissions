class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        int n=t.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
                st.push({t[i],i});
                continue;
            }
            while(!st.empty()&&t[i]>=st.top().first){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top().second-i;
                st.push({t[i],i});
            }else{
                ans[i]=0;
                st.push({t[i],i});
            }
        }
        return ans;
    }
};
