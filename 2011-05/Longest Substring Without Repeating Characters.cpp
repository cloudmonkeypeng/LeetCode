class Solution {
public:
 int lengthOfLongestSubstring(string s) {
    
    vector<int> dict(128,-1);
    
    int length = s.length();
    
    int count = 0;
    int answer = 0;
    int start = 0;
    
    for(int i=0;i<length;i++){
    
        if(dict[s[i]]==-1||dict[s[i]]<start){
            
            count++;
            
            answer  = max(answer,count);
            
        }else{
            
            count  = i - dict[s[i]];
                
            start = dict[s[i]] +1;

        }
        
        dict[s[i]] = i;
        
        //cout<<s[i]<<" "<<answer<<" "<<count<<endl;
    }
 
    return answer;
}


 

};