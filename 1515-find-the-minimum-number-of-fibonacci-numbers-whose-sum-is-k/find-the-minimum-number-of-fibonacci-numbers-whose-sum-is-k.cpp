class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};
        int sum = 1;
        while (sum < k) {
            fib.push_back(sum + fib[fib.size() - 2]);
            sum = fib[fib.size() - 1];
            //cout<<sum<<endl;
        }
        //return sum;
        int ans=0;
        int i = fib.size() - 1;
        while (k) {
            if (fib[i] <= k) {
            k = k - fib[i];
            //cout<<fib[i]<<endl;
            ans++;
            }
            i--;
        }
     
        return ans;

    }
    
}
;