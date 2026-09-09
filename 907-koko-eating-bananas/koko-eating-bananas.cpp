class Solution {
public:
    int findMax(vector<int>& v){
        int maxi = INT_MIN;
        for(int i=0;i<v.size();i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
    long long findHours(vector<int> &v,int h){
        long long totalH = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            totalH += ceil((double)v[i]/(double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while(low <= high){
            int mid = low + (high-low)/2;
            if(findHours(piles,mid) <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};