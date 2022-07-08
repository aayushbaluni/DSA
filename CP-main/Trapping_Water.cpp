
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int> st;
        int best=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()] <height[i]){
                   int curr=st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int length= i-st.top() -1;
                best+=(min(height[i],height[st.top()]) -height[curr])*length;
                
                
            }
            st.push(i);
            
        }
        return best;
    }
    
};