#include<bits/stdc++.h>
class Solution {
public:
  bool isAnagram(string s, string t)
{
    unordered_map<char, int> mpp1, mpp2;
    if (s.size()!=t.size()){
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        mpp1[s[i]]++;
    }
     for (int i = 0; i < t.size(); i++)
    {
        mpp2[t[i]]++;
    }
    if(mpp2==mpp1){
        return true;
    }
    else{ return false;}
}
};
