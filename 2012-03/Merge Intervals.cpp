/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> answer;
        
        for(int i=0;i<intervals.size();i++){
                answer = insert(answer,intervals[i]);
            
        }
        return answer;
    }
private:
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval>::iterator it = intervals.begin();
    
    if(intervals.size()==0){
        intervals.push_back(newInterval);
        return intervals;
    }
    
    if(intervals[intervals.size()-1].end<newInterval.start){
        intervals.push_back(newInterval);
        return intervals;
        
    }
    
    while(it!=intervals.end()){
    
        if(newInterval.end<it->start){
            
            intervals.insert(it, newInterval);
            return intervals;
        }else if(newInterval.start>it->end){
            it++;
        }else{
            
            newInterval.start = min(newInterval.start,it->start);
            
            newInterval.end = max(newInterval.end,it->end);
            
            intervals.erase(it);
        
        }
    }
    
    intervals.insert(intervals.end(),newInterval);
    return intervals;
}
};