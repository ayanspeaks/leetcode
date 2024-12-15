class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double sum = 0.0;
        
        priority_queue<tuple<double, int, int>> q;   // heap will compare the elements of tuple sequentially 
        
        for (const auto& class_ : classes) {
            int a = class_[0], b = class_[1];
            
            sum += (double)(a) / b; 
            
            q.push({calculateDelta(a, b), a + 1, b + 1}); 
        }
    
        
        while (extraStudents) {
            auto [delta, a, b] = q.top(); q.pop();
            
            sum += delta;
            
            q.push({calculateDelta(a, b), a + 1, b + 1});
            
            extraStudents--;
        }
        
        return sum / classes.size();
    }
    
    double calculateDelta(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)(a) / b;
    }
};