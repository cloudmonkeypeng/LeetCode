class Solution {
public:
    int maxArea(vector<int> &height) {
        
        int first = 0;
        int end = height.size()-1;
        
        int max =0;
        int temp = 0;
        
        while(first<=end){
            
            if(height[first]>height[end]){
                
                temp = (end-first)*height[end];
                end--;
            }else{
                temp = (end-first)*height[first];
                first++;
            }
             
            if(temp>max) max =temp;
            
        }
        
        return max;
    }
};