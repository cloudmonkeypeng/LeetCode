class Solution {
public:
    int lengthOfLastWord(const char *s) {
        
        
        int len = strlen(s);
        
        if(len<=0) return 0;
        
        int end = len-1;
        
        while(s[end]==' ')
            end--;
        
        len = 0;
        
        while(s[end]!=' '&&end>=0){
            len++;
            end--;
        }
            
        return len;
        
    }
};