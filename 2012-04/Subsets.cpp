///////////
//利用位运算

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};
/////////
class Solution{
    
public:
    vector<vector<int> > subsets(vector<int> &S) {
        
        sort(S.begin(),S.end());
        
        vector<vector<int>> ans;
        
        
        ans = dfs(S,0,S.size()-1);
        
        
       
        return ans;
        
    }
    
private:
    vector<vector<int>> dfs(vector<int> &S,int begin,int end){
        
        vector<vector<int>> temp;
        
        vector<int> level;
        
        if(begin>end){
            temp.push_back(level);
            return temp;
        }
        
        temp = dfs(S,begin+1,end);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
            
            level = temp[i];
            
            level.insert(level.begin(),S[begin]);
            
            ans.push_back(level);
        }
        
        return ans;
        
    }
    
};
