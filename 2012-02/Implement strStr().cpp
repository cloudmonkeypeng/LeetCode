//kmp

class Solution {
public:
  vector<int> getNext(char *needle,int nlen){
    
    vector<int> next;
    
    
    next =vector<int>(nlen,-1);
    
    
    for(int i=1,j=0;i<nlen;i++){
    
        if(needle[j]==needle[i]){
        
            next[i] = next[i-1]+1;
            
            j++;
        }else{
            j=0;
        }
    }
    
//    for(int i=0;i<nlen;i++){
//        cout<<next[i]<<" ";
//    }
//    cout<<endl;
    
    return next;
}

char *strStr(char *haystack, char *needle) {
    if(haystack == NULL || needle == NULL)
        return NULL;
    
    int hLen = strlen(haystack);
    int nLen = strlen(needle);
    
    if(hLen<nLen)
        return NULL;
    
    vector<int> next;
    
    next = getNext(needle,nLen);
    
    
    for(int i=0,j=0;i<hLen-nLen+1;){
        
        for(;j<nLen&&i+j<hLen&&haystack[i+j]==needle[j];j++);
        
        if(j==nLen) return haystack+i;
        
        if(j>0){
            
            i = i+j -next[j-1]-1;
            j = next[j-1]+1;
        
        }else{
            
            i++;
            j = 0;
        }
    }
    return NULL;
}
 
};


///最普通方法

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
      if(haystack == NULL || needle == NULL)
        return NULL;
    int hLen = strlen(haystack);
    int nLen = strlen(needle);
    if(hLen<nLen)          return NULL;
    for(int i=0; i<hLen - nLen+1; i++)
    {
        int j=0;
        char *p = &haystack[i];
        for(; j< nLen; j++)
        {
            if(*p != needle[j])
                break;
            p++;
        }
        if(j == nLen)
            return &haystack[i];
    }
    return NULL;
    }
};