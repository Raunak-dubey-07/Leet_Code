class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //  long long n=heights.size();
        // long long ans=0;
        // priority_queue<long long>pq;
        // for(long long i=0;i<n-1;i++){
        //     if(heights[i]>=heights[i+1]){
        //         ans++;
        //     }
        //     else{
        //         int a=abs(heights[i]-heights[i+1]);
        //         if(bricks>=a){
        //             bricks-=a;
        //             pq.push(a);
        //         }
        //         else{
        //             long long b=bricks;
        //             long long l=ladders;
        //             while(!pq.empty() && ladders>0 && bricks<a){
        //                 long long x=pq.top();
        //                 bricks+=x;
        //                 pq.pop();
        //                 ladders--;
        //             }
        //             if(bricks>=a){
        //                 bricks-=a;
        //                 ans++;
        //             }
        //             else{
        //                 bricks=b;
        //                 ladders=l;
        //                 if(ladders>0){
        //                 ans++;
        //                 ladders--;
        //                 }
        //                 else{
        //                     break;
        //                 }
        //             }

        //         }
        //     }
        // }
        // return ans;
        priority_queue<int> pq; // max-heap
        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i+1] - heights[i];
            if (diff > 0) {
                bricks -= diff; // use bricks first
                pq.push(diff); // store the climb
                if (bricks < 0) {
                    if (ladders > 0) {
                        bricks += pq.top(); // refund bricks
                        pq.pop();           // give ladder to largest climb
                        ladders--;
                    } else {
                        return i; // can't go further
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};