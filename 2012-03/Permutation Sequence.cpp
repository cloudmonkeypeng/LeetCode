class Solution {
public:
    string itos(int i) {
    stringstream s;
    s << i;
    return s.str();
}

string getPermutation(int n, int k) {

    if(n>9) return NULL;
    
    int multi = 1;
    
    for(int i=1;i<=n;i++)
        multi *=i;
    
    if(k>multi) return NULL;
    
    vector<int> numArray = vector<int>(n,1);
    
    for(int i=1;i<n;i++)
        numArray[i] = numArray[i-1]+1;
    
    
    string answer ="";
    
    k--;
    
    multi = multi/n;

    for(int i=0;i<n;i++){
        
        int temp = k/multi;
        
        k = k%multi;
        
        if (temp>=n) {
            return "error";
        }
        
        answer = answer + itos(numArray[temp]);
        
        numArray.erase(numArray.begin()+temp);
        
        if(n-1-i!=0){
            multi = multi/(n-1-i);
        }else{
            multi = 1;
        }
        
    }

    
    
    return answer;
}

};