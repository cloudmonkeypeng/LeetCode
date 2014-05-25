///抄的  懒得做了。。。

class Solution {
public:
    bool isNumber(const char *s) {
          char* endptr;
    
    strtod (s, &endptr);
    
    if (endptr == s) return false;
    
    for (; *endptr; ++endptr)
        if (!isspace (*endptr)) return false;
    return true;
    }
};