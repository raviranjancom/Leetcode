class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSqArea = 0; // Rename variable for clarity
        
        for(int i = 0; i < n; i++) {
            // Rectangle 1 coordinates
            int ax1 = bottomLeft[i][0], ay1 = bottomLeft[i][1];
            int ax2 = topRight[i][0],   ay2 = topRight[i][1];
            
            for(int j = i + 1; j < n; j++) {
                // Rectangle 2 coordinates
                int bx1 = bottomLeft[j][0], by1 = bottomLeft[j][1];
                int bx2 = topRight[j][0],   by2 = topRight[j][1];
                
                // 1. Calculate Intersection Boundaries
                // The overlap starts at the "inner" edges
                int inter_left = max(ax1, bx1);
                int inter_bottom = max(ay1, by1);
                
                // The overlap ends at the "outer" edges (closest to center)
                int inter_right = min(ax2, bx2);
                int inter_top = min(ay2, by2);
                
                // 2. Check if overlap is valid (Right > Left AND Top > Bottom)
                if (inter_right > inter_left && inter_top > inter_bottom) {
                    // 3. Calculate dimensions of the intersection rectangle
                    long long width = inter_right - inter_left;
                    long long height = inter_top - inter_bottom;
                    
                    // 4. Largest square is limited by the shorter side
                    long long side = min(width, height);
                    maxSqArea = max(maxSqArea, side * side);
                }
            }
        }
        return maxSqArea;
    }
};