class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (target < 0 || index == candidates.size()) {
            return;
        }

        // Take the current element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            // index stays same because we can reuse the element
            solve(candidates, target - candidates[index],
                  index, current, ans);

            current.pop_back();
        }

        // Don't take the current element
        solve(candidates, target, index + 1,
              current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
        vector<int> current;

        solve(nums, target, 0, current, ans);

        return ans;
    }
};
