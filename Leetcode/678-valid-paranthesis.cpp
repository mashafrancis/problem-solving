class Solution {
public:
    bool checkValidString(string s) {
        stack<int> parenthesis, asterix;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (!parenthesis.empty()) parenthesis.pop();
                else if(!asterix.empty()) asterix.pop();
                else return false;
            }
            else if (s[i] == '(') parenthesis.push(i);
            else asterix.push(i);
        }
        
        while(!parenthesis.empty() && !asterix.empty()) {
            if(parenthesis.top() > asterix.top()) return false;
            parenthesis.pop();
            asterix.pop();
        }
        return parenthesis.empty();
    }
};