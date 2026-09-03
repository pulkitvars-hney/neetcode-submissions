class Solution {
public:
    int maxArea(vector<int>& heights) {
      int left=0;
      int right=heights.size()-1;
      int maxarea=INT_MIN;
      while(left<right){
        int area=(right-left)*min(heights[left],heights[right]);
        maxarea=max(area,maxarea);
        if(heights[left]<heights[right]){
            left++;
        }else{
            right--;
        }
      }  
      return maxarea;
    }
};
