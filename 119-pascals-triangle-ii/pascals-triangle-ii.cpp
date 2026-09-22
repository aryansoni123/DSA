class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int> str = {1};

        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        

        vector<int> prev = {1,1};
        vector<int> curr;

        int n = rowIndex-1;

        while(n>0){
            curr.push_back(1);
            
            for(int i = 0; i<prev.size()-1; i++){
                curr.push_back(prev[i] + prev[i+1]);
            }
            
            curr.push_back(1);
            prev = curr;
            curr.clear();
            n--;
        }

        return prev;
    }
};