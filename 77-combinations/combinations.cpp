class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start,int n, int k,vector<int>& current){
        if(current.size() == k){
            ans.push_back(current);
        }
        for(int i=start;i<=n;i++){
            current.push_back(i);
            solve(i+1,n,k,current);
            current.pop_back(); // element of backtracking 
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        solve(1,n,k,current);
        return ans;
    }
};