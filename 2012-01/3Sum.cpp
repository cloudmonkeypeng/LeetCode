////注意多次去重的问题


vector<vector<int> > threeSum(vector<int> &num) {
    
    std::sort(num.begin(), num.end());
    vector<vector<int> > result;
    int len = num.size();
    
    for(int i =0; i< len; i++){
        
        int target = 0-num[i];
        int start = i+1, end =len-1;
        
        while(start<end){
            
            if(num[start] + num[end] == target){
                
                vector<int> solution;
                
                solution.push_back(num[i]);
                solution.push_back(num[start]);
                solution.push_back(num[end]);
                result.push_back(solution);
                
                start++; end--;
                
                while(start<end && num[start] == num[start-1]) start++;
                while(start<end && num[end] == num[end+1]) end--;
            
            }else if(num[start] + num[end] < target){
                
                start++;
            
            }else{
                
                end--;
            }
        }
        
        if(i<len-1){
            while(num[i] == num[i+1]) i++;
        }
    }
    return result;
}
