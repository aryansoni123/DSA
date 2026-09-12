class Solution {
public:

    struct Node{
        long long scr = 0;
        vector<int> idx = {};
    };


    Node f(int i, int k, vector<vector<int>>& intervals, vector<int> &nxtind, vector<vector<Node>> &dp){
        int n = intervals.size();

        if(k==0 || i>=n) return Node();

        if(dp[i][k].scr!=-1) return dp[i][k];

        Node npick = f(i+1, k, intervals, nxtind, dp);

        Node tmp = Node();
        
        if(nxtind[i] != -1) tmp = f(nxtind[i], k-1, intervals, nxtind, dp);
        Node pick;

        pick.scr = intervals[i][2] + tmp.scr;
        pick.idx = tmp.idx;
        pick.idx.push_back(intervals[i][3]);
        sort(pick.idx.begin(), pick.idx.end());

        if(pick.scr>npick.scr){
            return dp[i][k] = pick;
        } else if(pick.scr<npick.scr){
            return dp[i][k] = npick;
        } else{
            return dp[i][k] = pick.idx>npick.idx ? npick : pick;
        }
    }


    int findnxt(int i, vector<vector<int>>& intervals){
        int l = i+1;
        int r = intervals.size()-1;

        int val = intervals[i][1];

        while(l<=r){
            int m = l + (r-l)/2;

            if(intervals[m][0]>val){
                r = m-1;
            } else{
                l = m+1;
            }
        }

        return l==intervals.size() ? -1: l;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> nxtind(n, -1);

        vector<vector<Node>> dp(n+1, (vector<Node>(5, Node(-1, {}))));
        
        for(int i = 0; i<n; i++){
            intervals[i].push_back(i);
        }
        // for(auto x: intervals){
        //     for(auto y: x){
        //         cout<<y<<' ';
        //     }
        //     cout<<' ';
        // }

        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<n; i++){
            nxtind[i] = findnxt(i, intervals);
        }
            // intervals[i].push_back(i);

        // for(auto x: intervals){
        //     for(auto y: x){
        //         cout<<y<<' ';
        //     }
        //     cout<<' ';
        // } 

        // // scr = 7 + 5
        // cout<<endl;

        // for(auto x: nxtind){
        //     cout<<x<<' ';
        // }


        Node ans = f(0, 4, intervals, nxtind, dp);

        return ans.idx;

        // return {};
    }
};