class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int m=intervals[0].size();
        if(n==0) return ans;
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end());
        int start=0,end=1;
        vector<int> v= intervals[0];
        for(auto it : intervals){
            if(it[0]<=v[1]){
                v[1]=max(v[1],it[1]);
            }else{
                ans.push_back(v);
                v=it;
            }
        }
        ans.push_back(v);
        return ans;
    }
};