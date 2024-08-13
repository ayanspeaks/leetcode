class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap using a priority queue to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> q;

        // Iterate through each number in the input vector
        for(int i = 0; i < nums.size(); i++) {
            q.push(nums[i]); // Push the current number onto the min-heap

            // If the size of the heap exceeds k, remove the smallest element
            while(q.size() > k) {
                q.pop(); // Pop the smallest element to maintain only k largest
            }
        }
        
        // The root of the min-heap is the k-th largest element
        return q.top();
    }
};
