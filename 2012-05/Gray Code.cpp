class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;  //1左移
        
        vector<int> grayCodes;
        

        for (int i = 0; i < size; i++){
            int gCode = i ^ i>>1;
            grayCodes.push_back(gCode);
        }

        return grayCodes;
    }
};