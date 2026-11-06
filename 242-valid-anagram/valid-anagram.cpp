class Solution {
public:
    bool isAnagram(string s, string t) {
        // here we map the elements of s and then compare with t
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp; // character and number of occurences
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        //iterating through t and checking for all occurences of all characters
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;
                if(mp[t[i]] < 0) return false;
            }
            else{
                return false;
            }
        }
        for(auto& pair : mp){
            if(pair.second != 0){
                return false;
            }
        }
        return true;
    }
};