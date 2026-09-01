class Solution {
public:
    bool isSubsequence(string s, string t) {
     if(s.size()==0) return true;
     if( t.size()==0) return false;
    int index=0;
    for(int i=0;i<s.size();i++){
        int flag=0;
        for(int j=index;j<t.size();j++){
            if(s[i]==t[j])
            {
                flag=1;
                index=j+1;
                break;
            }
        }
        if(flag==0 ) return false;
    }
     return true;
    }
};