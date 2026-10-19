class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            // collison will only happen if upcoming is negative and last one is positive
            bool flag = false;
            while (st.size() != 0 && a < 0 && st.back() > 0) {
            int b = st.back();
                if (abs(a) > abs(b)) {
                    st.pop_back();
                } else if (abs(a) == abs(b)) {
                    st.pop_back() ;flag = true;
                    break;
                } else {
                    flag = true;
                    break;
                }
            }
            if(!flag){
                st.push_back(a);
            }
        }
        return st;
    }
};