class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        vector<int> freq(26,0);
        int maxfreq=0;
        int ans=INT_MIN;
        for(int j=0;j<s.size();j++){
            freq[s[j]-'A']++;
            maxfreq=max(freq[s[j]-'A'],maxfreq);
            int count=(j-i+1)-maxfreq;
            if(count>k){
                freq[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
