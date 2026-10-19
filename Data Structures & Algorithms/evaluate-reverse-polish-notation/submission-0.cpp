class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(s=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);

            }
            else if(s=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);

            }
            else if(s=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
