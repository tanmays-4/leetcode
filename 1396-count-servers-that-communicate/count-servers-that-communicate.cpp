class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //first approach : brute force
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    bool flag_row = false;
                    bool flag_column = false;
                    for(int k=0;k<m;k++){
                        if((k != i) && grid[k][j] == 1){
                            flag_column = true;
                        }
                    }
                    for(int k=0;k<n;k++){
                        if((k != j) && grid[i][k] == 1){
                            flag_row = true;
                        }
                    }
                    if(flag_column || flag_row){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};