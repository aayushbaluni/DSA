class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        int left,right;
        
        set<vector<int>> s;
        
        for(int i=0;i<=n-2;i++){
            right=n;
            left=i+1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
            if(sum==0){
                s.insert({nums[left],nums[i],nums[right]});
                left++;
                right--;
            }
                else if (sum>0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        vector<vector<int>> ans (s.begin(),s.end());
        return ans;
    }
};