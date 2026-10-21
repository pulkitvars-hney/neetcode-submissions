class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mpp;
        int n=position.size();
        for(int i=0;i<n;i++){
            mpp[position[i]]=speed[i];
        }
        stack<int>st;
        sort(position.begin(),position.end());
        for(int x:position){
            if(st.empty()){
                st.push(x);
            }else{
                double time_to_reach=(double)(target-x)/mpp[x];
                bool flag=true;
                while(!st.empty()&&flag){
                    double time_to_reachprev=(double)(target-st.top())/mpp[st.top()];
                    if(time_to_reachprev<=time_to_reach){
                        st.pop();
                    }else{
                        flag=false;
                    }
                }
                st.push(x);
            }
        }
    return st.size();
    }
};
