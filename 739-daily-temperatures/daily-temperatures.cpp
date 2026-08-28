class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        vector<int> answer(n);
        vector<int> stk; stk.reserve(n);

        for(int i=0;i<n;i++){
            while(!stk.empty() && tem[stk.back()]<tem[i]){
                int ind=stk.back();
                answer[ind]=i-ind;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        return answer;
    }
};