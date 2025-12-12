class Solution {
public:
    int arrayNesting(vector<int>& nums) {
         int n = nums.size();
    vector<bool> visited(n, false);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if (!visited[i]) {     // only start from unvisited nodes
            int x = i;
            int count = 0;

            while (!visited[x]) {
                visited[x] = true;
                x = nums[x];   // follow next pointer
                count++;
            }

            ans = max(ans, count);
        }
    }
    return ans;
        
    }
};