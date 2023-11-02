class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_min = 6.0 * minutes, angle_hour = 30.0 * (hour + (double)minutes / 60);
        double diff = angle_min > angle_hour ? angle_min - angle_hour : angle_hour - angle_min;
        return diff > 180 ? 360 - diff : diff;
    }
};