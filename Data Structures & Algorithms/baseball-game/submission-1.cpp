class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="C"){
                if(!st.empty())st.pop();
            }
            else if(s[i]=="D"){
                int a=st.top();
                st.push(2*a);
            }
            else if(s[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }else{
                st.push(stoi(s[i]));
            }
            
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};