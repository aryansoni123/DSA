class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack<int> st;
        vector<int> st;

        int n = asteroids.size();

        for(int i = 0; i<n; i++){
            if(st.empty() || (st.back() > 0 && asteroids[i] > 0)) st.push_back(asteroids[i]);

            else{
                int x = st.back();
                int y = asteroids[i];
                while(!st.empty() && ((x>0 && y<0))){
                    if(abs(x) > abs(y)){
                        y = 0;
                        break;
                    }
                    else if(abs(x) == abs(y)){
                        st.pop_back();
                        y = 0;
                        break;
                    } else{
                        st.pop_back();
                        if(!st.empty()) x = st.back();
                    }
                }

                if(y!=0) st.push_back(y);
            }
        }

        // vector<int> a

        return st;
    }
};