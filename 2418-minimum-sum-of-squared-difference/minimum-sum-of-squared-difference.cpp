class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<int> arr;
        unordered_map<int, int> mpp;

        arr.push(0);

        int n = nums1.size();

        for(int i = 0; i<n; i++){
            int val = abs(nums1[i] - nums2[i]);
            if(!mpp.contains(val)) arr.push(val);
            mpp[val]++;
        }

        // for(auto x: mpp){
        //     cout<<x.first<<' '<<x.second;
        //     cout<<endl;
        // }

        int chng = k1+k2;

        while(chng>0){
            int tp = arr.top();
            arr.pop();

            // cout<<tp;
            // cout<<endl;

            if(tp!=0){
                if(mpp[tp]<=chng){
                    chng -= mpp[tp];
                    if(!mpp.contains(tp-1)) arr.push(tp-1);
                    mpp[tp-1] += mpp[tp];
                    mpp[tp] = 0;

                } else{
                    if(!mpp.contains(tp-1)) arr.push(tp-1);
                    mpp[tp-1] += chng;
                    mpp[tp] -= chng;
                    arr.push(tp);
                    break;                    
                }
                
            }
            else break;

            // arr.push(tp);
            // chng--;
        }

        // for(auto x: mpp){
        //     cout<<x.first<<' '<<x.second;
        //     cout<<endl;
        // }
        // cout<<'p';


        // 3334

        long long ans = 0;

        while(!arr.empty()){
            long long val = (long long)arr.top() * arr.top();
            val*= mpp[arr.top()];
            // cout<<arr.top()<<endl;
            arr.pop();

            ans+=val;
        }

        return ans;

    }
};