class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour == 12 ? 0 : hour;

        hr *= 30;

        hr += (minutes%2==1) ? minutes/2 + 0.5 : minutes/2;

        int mins = minutes * 6;

        double angle = abs(mins - hr);

        return min(angle, 360 - angle);
    }
};