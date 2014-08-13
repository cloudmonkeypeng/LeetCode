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

//从左往右找的

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        
        if(s==NULL||*s=='\0')
            return 0;

        int length = 0;

        bool newSpace = true;

        while(*s!='\0'){

            if(*s==' '){
                newSpace =true;
            }else{
                if(newSpace){
                    length = 1;

                    newSpace = false;

                }else{
                
                    length++;
                }
            }

            s++;
        }

        return length;
    }
};