
///递归方法超时
#include <iostream>

using namespace std;


//迭代 能通过

bool isMatch(const char *s, const char *p) {

    bool flag =false;
    
    const char *str,*ptr;
    
    str = s; ptr = p;
        
    while(*str!='\0'){
    
    
        if(*ptr==*str||*ptr=='?'){
            str++;ptr++;
            continue;
        }
        
        
        if(*ptr=='*'){
        
            while(*ptr=='*') ptr++;
            
            if(*ptr=='\0') return true;
            
            flag =true;
            
            s = str; p = ptr;
            
            continue;
        }
        
        if(*ptr!=*str){
            
            if(!flag) return false;
            
            str = ++s;
            
            
            ptr = p;
            
        
        }
    }
    
    
    while(*ptr=='*') ptr++;
    
    return *ptr ==  '\0';
    
}



bool isMatch(const char *s, const char *p) {

    
    if(*p=='*'){
    
        while(*p=='*') p++;
        
        if(*p=='\0') return true;
        
        while(*s!='\0'&&!isMatch(s, p)) s++;
              
        return *s!='\0';
        
    }else if(*p=='\0'||*s=='\0') return *p == *s;
    else if(*s==*p||*p=='?') return isMatch(++s,++p);
    else return false;
}


int main(){
    
    char s[]="aab";
    
    char p[] = "*b";
    
    //char p[]="c*a*b";
    
    cout<<isMatch(s, p);
    
    return 0;
}