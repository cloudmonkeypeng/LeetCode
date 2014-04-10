class Solution {
public:

    vector<vector<int>> res;
    
    vector<int> subset;
    
    void findsubset(vector<int> &s, int index)
	{
		res.push_back(subset);
		for(int i = index; i< s.size(); i++)
		{
			if(i!=index&&s[i]==s[i-1]) continue;
			
			subset.push_back(s[i]);
			findsubset(s,i+1);
			subset.pop_back();
		}
	}
	
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
       
		sort(S.begin(),S.end());
		findsubset(S,0);
		return res;
    }
};