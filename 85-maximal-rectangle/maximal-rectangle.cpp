class Solution {
public:

    int maxRect(vector<int> &nums){
        int n = nums.size();

        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        stack<int> st;

        // PSE

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

                if(!st.empty()) pse[i] = st.top();

                st.push(i);
            }
        }

        st = {};

        // NSE

        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

                if(!st.empty()) nse[i] = st.top();

                st.push(i);
            }
        }

        int ans = 0;

        for(int i = 0; i<n; i++){
            int h = nums[i];

            int dist = nse[i] - pse[i] - 1;

            ans = max(ans, dist*h);
        }

        return ans;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> nums(n, vector<int>(m, 0));

        for(int i = 0; i<m; i++) nums[0][i] = matrix[0][i] - '0';

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] != '0') nums[i][j] = nums[i-1][j] + 1;
                else nums[i][j] = 0;
            }
        }

        int ans = 0;

        // for(auto row: matrix){
        //     for(auto x: row){
        //         cout<<x<<' ';
        //     }
        //     cout<<endl;
        //     // ans = max(ans, maxRect(row));
        // }
        // cout<<endl;

        for(auto row: nums){
            // for(auto x: row){
            //     cout<<x<<' ';
            // }
            // cout<<endl;
            ans = max(ans, maxRect(row));
        }

        return ans;
    }
};