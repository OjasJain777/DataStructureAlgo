class Solution {
public:
    double angleClock(int h, int m) {
        h = h%12;
        double a = abs((6*m) - ((30*h) + (0.5 * m)));
        if(a>180){
            return 360-a;
        }
        return a;
    }
};