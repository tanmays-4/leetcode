
class Solution { 
public: 
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) { 
        int m = logs.size(); 
        
        // 1. Sort logs based on time (index 1)
        auto lambda = [](const vector<int>& vec1, const vector<int>& vec2){ 
            return vec1[1] < vec2[1]; 
        }; 
        sort(begin(logs), end(logs), lambda); 
        
        int q = queries.size(); 
        vector<int> result(q); 
        
        // 2. Store queries with their original indices and sort them
        vector<pair<int,int>> queriesIndex; 
        for(int i = 0; i < q; i++){ 
            queriesIndex.push_back({queries[i], i}); 
        } 
        sort(queriesIndex.begin(), queriesIndex.end()); 
        
        // 3. Sliding window pointers and server frequency map
        unordered_map<int, int> mp; 
        int i = 0; // Left pointer (shrinking)
        int j = 0; // Right pointer (expansion)
        
        for(auto [time, idx] : queriesIndex){ 
            int start = time - x; 
            int end = time; 
            
            // Expansion: add logs that fall before or at query 'end' time
            while(j < m && logs[j][1] <= end){ 
                mp[logs[j][0]]++;               
                j++; 
            } 
            
            // Shrinking: remove logs that fell out before 'start' time
            while(i < m && logs[i][1] < start){ 
                mp[logs[i][0]]--; 
                if(mp[logs[i][0]] == 0){ 
                    mp.erase(logs[i][0]); 
                } 
                i++; 
            } 
            
            // Total servers minus the active ones in the current window
            result[idx] = n - mp.size(); 
        } 
        
        return result; 
    } 
};
