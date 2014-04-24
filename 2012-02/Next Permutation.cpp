class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int index = -1;
    
    for(int i=num.size()-1;i>0;i--){
        if(num[i-1]<num[i]){
            index = i-1;
            break;
        }
    }
    
    if(index==-1){
        
        reverse(num.begin(),num.end());
        
        return;
    }
    
    int nextMin = numeric_limits<int>::max();
    
    int nextIndex =-1;
    
    for(int i=index+1;i<num.size();i++){
        
        if(nextMin>num[i]&&num[i]>num[index]){
            
            nextMin = num[i];
            
            nextIndex = i;
        }
        
    }
    
    swap(num[index], num[nextIndex]);
    
    sort(num.begin()+index+1,num.end());
    }
};