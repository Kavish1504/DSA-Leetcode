class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n||heights[st.top()]>heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                area=max(area,height*width);
            }
            st.push(i);
        }
        return area;
    }
};