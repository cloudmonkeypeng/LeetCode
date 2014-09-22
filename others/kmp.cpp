#include <vector>
#include <string>
#include <iostream>


using namespace std;


class Solution{
    
public:
    
    vector<int> getNext(string p,int nlen){
        
        vector<int> next(p.length(),-1);
        
        
        int pLen = p.length();
        
        int k = -1;
        int j = 0;
        while (j < pLen - 1){
            
            if (k == -1 || p[j] == p[k]){
                
                ++j;
                ++k;
                
                next[j] = k;
            
            }
            else{
                
                k = next[k];
            }
        }
        
        return next;
    }
    
    int strStr(string haystack, string needle) {
    
        if(haystack.length()==0 || needle.length()==0)
            return 0;
        
        int hLen = haystack.length();
        int nLen = needle.length();
        
        if(hLen<nLen)
            return 0;
        
       
        
        vector<int> next = getNext(needle, nLen);
        
        int ans = 0;
        
        int i=0;
        int j=0;
        
        while(i<hLen){
            
            if(j==-1||haystack[i]==needle[j]){
            
                i++;
                j++;
                
            }else{
                
                j = next[j];
                
            }
            
            if(j==nLen){
            
                ans++;
                
                i--;
                
                j--;
                
                j = next[j];
                
            }
            
        }
        
        return ans;
    
    }
    
};

int main(){

    int num;
    
    cin>>num;
    
    while(num>0){
    
        class Solution sol;
        
        string needle;
        
        string haystack;
        
        cin>>needle;
        
        cin>>haystack;
        
        
        int ans = sol.strStr(haystack, needle);
        
        cout<<ans<<endl;
        
        num--;
    }
    
    return 0;
   
}
