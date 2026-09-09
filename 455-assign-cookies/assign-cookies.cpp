class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childindex = 0 ;
        int cookieindex = 0;

        while(childindex < g.size() && cookieindex < s.size()){
            if(s[cookieindex] >= g[childindex]){
                childindex++;
            }
            cookieindex++;
        }
        return childindex;
    }
};