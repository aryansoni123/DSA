class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int r = radius;

        // int nx = clamp(xCenter, x1, x2) - xCenter;
        // int ny = clamp(yCenter, y1, y2) - yCenter;

        int nx = x1;
        int ny = y1;

        if(x1>xCenter){
            nx = x1;
        } else if(x2<xCenter){
            nx = x2;
        } else{
            nx = xCenter;
        }

        if(y1>yCenter){
            ny = y1;
        } else if(y2<yCenter){
            ny = y2;
        } else{
            ny = yCenter;
        }

        int dist = (xCenter - nx)*(xCenter - nx) + (yCenter - ny)*(yCenter - ny);
        return dist<=r*r;
    }
};