class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // all elements of pascals triangle are basically C(r,i) where i is the row position and i operators from 1 to rowindex

        //short formula : next val = prev * (rowindex - k + 1)/k;
        vector<int> result(1,1);
        long long prev = 1;
        for(int k = 1;k <= rowIndex;k++){
            long long next_val = prev * (rowIndex - k + 1)/k;
            result.push_back(next_val);
            prev = next_val;
        }
        return result;
    }

};