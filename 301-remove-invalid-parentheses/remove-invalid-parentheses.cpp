class Solution {
public:
    // we use backtracking in this solution to find out all the ways that this a valid string can be matched
    unordered_set<string> result;

    void backtrack(string &s, int index,int leftcount,int rightcount,int leftrem,int rightrem, string current){
        
        //checking if already processed:
        //base condition:

        if(index == s.size()){
            if((leftrem == 0) && (rightrem == 0) && (leftcount == rightcount)){
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        //if character is '(':

        if(ch == '('){
            //option 1 : remove it
            if(leftrem > 0){
                backtrack(s,index+1,leftcount,rightcount,leftrem-1,rightrem,current);
            }
            //option 2: keep it
            backtrack(s,index+1,leftcount+1,rightcount,leftrem,rightrem,current+'(');

        }
        else if(ch == ')'){
            //option 1 : remove it
            if(rightrem > 0){
                backtrack(s,index+1,leftcount,rightcount,leftrem,rightrem-1,current);
            }
            //option 2: keep it
            if(rightcount < leftcount){
                backtrack(s,index+1,leftcount,rightcount+1,leftrem,rightrem,current+')');
            }
        }
        else{
            backtrack(s,index+1,leftcount,rightcount,leftrem,rightrem,current+ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftrem = 0;
        int rightrem = 0;

        //finding minimum removals:
        for(char ch : s){
            if(ch == '('){
                leftrem++;
            }
            else if(ch == ')'){
                if(leftrem > 0){
                    leftrem--;
                }
                else{
                    rightrem++;
                }
            }
        }
        backtrack(s,0,0,0,leftrem,rightrem,"");
        return vector<string>(result.begin(),result.end());
    }

};