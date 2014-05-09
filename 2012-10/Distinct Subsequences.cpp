class Solution {
public:
    int numDistinct(string S, string T) {

    S =' '+S;
    
    T =' '+T;
    
    vector<int> level (S.length(),1);
    
    for(int i=1;i<T.length();i++){
        
        int prev = level[0];
        
        if(T[i]==S[0]){
            level[0] = 1;
            
        }else{
            level[0] = 0;
        }
        
        for(int j=1;j<S.length();j++){
        
            int temp = level[j];
            
            if (T[i]==S[j]) {
            
                level[j] =  level[j-1] +prev;
                
            }else{
            
                level[j] = level[j-1];
                
            }
            
            prev = temp;
            
           
            
        }
        
//        for(int m=0;m<level.size();m++)
//            cout<<level[m]<<" ";
//        
//        cout<<endl;
    
    }
    
    return level[S.length()-1];

    }
};