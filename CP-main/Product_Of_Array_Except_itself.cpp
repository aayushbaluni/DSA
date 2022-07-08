//it is not best approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        vector<int> ans;
        for(int i=0;i<=end;i++){
            int n=end;
            int j=start;
            
            int element=1;
            while(j!=n){
                while(j!=i ){
                element=element*nums[j];
                    j++;
                    }
                while(n!=i){
                    element*=nums[n];
                    n--;
                    }
                
            }
            ans.push_back(element);
        }
        
        return ans ;
    }
};

//best approach in O(n) space and time compplexity without division

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size()-1;
        vector<int> left(n+1),right(n+1),ans(n+1);
        left[0]=nums[0];
        right[n]=nums[n];
        for(int i=1;i<=n;i++){
            left[i]=left[i-1]*nums[i];
            }
        for(int i=n-1;i>=0;i--){
            right[i]=right[i+1]*nums[i];
            }
            ans[0]=right[1];
            ans[n]=left[n-1];
        for(int i=1;i<n;i++){
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
};