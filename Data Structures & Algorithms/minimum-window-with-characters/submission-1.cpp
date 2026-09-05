class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }
        int start = 0;
        int left = 0;
        int minlen = INT_MAX;
        int required = t.size();
        int have = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] <= need[c]) {
                have++;
            }
            while (have == required) {
                if (right - left + 1 < minlen) {
                    minlen = min(minlen, right- left + 1);
                    start = left;
                }
                char remove = s[left];
                window[remove]--;

                if (need.count(remove) && window[remove] < need[remove]) {
                    have--;
                }

                left++;
            }
        }
        if (minlen == INT_MAX) return "";

        return s.substr(start, minlen);
    }
};
