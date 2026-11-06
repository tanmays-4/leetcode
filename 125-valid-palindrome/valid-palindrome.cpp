class Solution {
public:
    bool isPalindrome(string s) {
        // here instead of converting the string to the desired form, we ignore all the whitespace and only consider alpha numerical characters

        // 2 pointers approach:
        int start = 0;
        int end = s.size()-1;
        while(start <= end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }

        }
        return true;
    }
};