class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int> pqs;
        priority_queue<int> pql;

        int mx = INT_MIN;

        for(int i = 0; i<3; i++){
            mx = max(nums[i], mx);
            pqs.push(-nums[i]);
            pql.push(nums[i]);
        }

        for(int i = 3; i<n; i++){
            mx = max(nums[i], mx);
            pqs.push(-nums[i]);
            pql.push(nums[i]);
            pqs.pop();
            pql.pop();
        }

        if (pql.size()>=3) pql.pop();


        // sort(nums.begin(), nums.end());

        // while(pqs.size()){
        //     cout<<-pqs.top();
        //     pqs.pop();
        // }

        // cout<<endl;

        // while(pql.size()){
        //     cout<<pql.top();
        //     pql.pop();
        // }
        // cout<<mx;

        int a = 1;

        while (pqs.size()){
            a *= -pqs.top();
            pqs.pop();
        }

        while(pql.size()){
            mx *= pql.top();
            pql.pop();
        }

        // for(auto x: pqs) cout<<x<<' '<<endl;
        // for(auto x: pql) cout<<x<<' ';

        // int a = nums[0] * nums[1] * nums[n-1];
        // int b = nums[n-1] * nums[n-2] * nums[n-3];

        return max(a,mx);
        // return max(a,b);
    }
};