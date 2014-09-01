class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
 	
 	if(strs.empty()) return "";   //不能返回null
 	
 	if(strs.size()==1) return strs[0];

 	for(int i=0;i<strs[0].size();i++){

 		for(int m=1;m<strs.size();m++){

 			if(strs[m][i]!=strs[0][i]) return strs[0].substr(0,i);

 		}

 	}

 	return strs[0];
 }
};


////////////////

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        int ans = 0;
        
        if(strs.size()==0)
            return "";
        
        ans = strs[0].size() ;
        
        
        int temp = 0;
        
        for(int i=1;i<strs.size();i++){
            
            for( temp = 0;temp<strs[i].size()&&temp<ans;temp++){
            
                if(strs[0][temp]!=strs[i][temp])
                    break;
            }
        
            ans = min(ans,temp);
        }
        
        
        
        return strs[0].substr(0,ans);
    }
};