class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin=INT_MAX;
        int profit=0;
        int maxprofit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            curmin=min(curmin,prices[i]);
            profit=prices[i]-curmin;
            maxprofit=max(profit,maxprofit);

        }
        return maxprofit;
    }
};
