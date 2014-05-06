class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
    
    int maxArea = 0;
    
    stack<int> s;
    
    for(int i=0;i<height.size();){
    
        if(s.empty()||height[i]>=height[s.top()]){
            
            s.push(i);
            i++;
            
        }else{
            
            int temp  = s.top();
            
            s.pop();
            
            if(s.empty()){
            
                maxArea = max(maxArea,height[temp]*i);
                
            }else{
                
                maxArea = max(maxArea,height[temp]*(i-1-s.top()));
                
            }
        
        }
    
    }
    
    return maxArea;

    }
};