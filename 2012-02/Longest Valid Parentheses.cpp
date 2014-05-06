class Solution {
public:
    int longestValidParentheses(string s) {
         
    int maxLen = 0, last = -1;
    stack<int> lefts ;
    
    for (int i=0; i<s.length(); ++i) {
        if (s[i]=='(') {
            lefts.push(i);
        } else {
            if (lefts.empty()) {
    
                last = i;
            } else {
                
                lefts.pop();
                
                if (lefts.empty()) {
                    
                    
                    maxLen = max(maxLen, i-last);
                } else {
                    
                    maxLen = max(maxLen, i-lefts.top());
                
                }
            }
        }
    }
    return maxLen;

    }
};