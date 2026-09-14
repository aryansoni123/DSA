class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int x2 = rec1[2];
        int y2 = rec1[3];
        int x1 = rec2[0];
        int y1 = rec2[1];
        return (x1 < x2 && y1 < y2) && (rec2[2] > rec1[0] && rec2[3] > rec1[1]);
        
    }
};