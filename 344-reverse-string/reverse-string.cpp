class Solution {
public:
    void reverseString(vector<char>& s) {
        // here we are required to do this in the same string and not not using any extra space
        
        // hence we use 2 pointer approach

        // one pointer in the starting of the string and one in the end, swap them and move them until they meet
        
        int left = 0, right = s.size()-1;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};