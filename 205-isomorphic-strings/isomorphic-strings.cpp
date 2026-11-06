class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charMap;

        for(int i=0;i<s.length();++i){
            char sc = s[i];
            char tc = t[i];

            if(charMap.count(sc)){ // basically finding if there are any occurences of sc in the charmap
                if(charMap.count(sc)){
                    if(charMap[sc] != tc){
                        return false;
                    }
                }
            }
            else { // there are no sc in key
                for(auto& pair : charMap){ // checking all existing pairs in char map
                    if(pair.second == tc){ // if tc is value for any other value
                        return false;
                    }
                }
                charMap[sc] = tc;
            }

        }
        return true;
    }
};