class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
        if (points.size() < 3) return points.size();
        
        int result = 0;
        
        for (int i = 0; i < points.size()-1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int sign = 0;
                int a, b, c;
                if (points[i].x == points[j].x) {
                    sign = 1;
                }else {
                    a = points[j].x - points[i].x;
                    b = points[j].y - points[i].y;
                    c = a * points[i].y - b * points[i].x;   
                }
                
                int count = 0;
                for (int k = 0; k < points.size(); k++) {
                    
                    if ((0 == sign && a * points[k].y == c +  b * points[k].x) ||
                        (1 == sign&&points[k].x == points[j].x))
                        count++;
                }
                
                result = max(count,result);
            }
        }
        
        return result;
    
    }
};