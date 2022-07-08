class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int> > v;
        vector<int> v2;
       if(n>=1){
           
        v2.push_back(1);
        v.push_back(v2);
       }
        if(n>=2){
            
        v2.push_back(1);
        v.push_back(v2);
        }
        for(int i=2;i<n;i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j=1;j<i;j++){
                v1.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v1.push_back(1);
            v.push_back(v1);
        }
        return v;
    }
};