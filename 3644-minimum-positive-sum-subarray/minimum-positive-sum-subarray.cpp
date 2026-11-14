class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        //brute force solution:
        int n = nums.size();
        int best = INT_MAX;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j< min(i+r,n);++j){
                sum += nums[j];
                if((j-i+1) >= l && ((sum > 0) && (sum < best))){
                    best = sum;
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};