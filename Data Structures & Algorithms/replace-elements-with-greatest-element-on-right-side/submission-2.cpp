class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        for(int i=0;i<arr.size();i++){
            int max =arr[i+1];
            for(int j=i+1;j<n;j++){
                if(max<arr[j]){
                    max=arr[j];
                }
            }
            ans[i]=max;
        }
        ans[n-1]=-1;
        return ans;
    }
};