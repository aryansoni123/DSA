class Solution {
public:

    // bool f()

    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        // vector<int> vals;

        int sum = 0;
        int ones = 0, twos = 0, zeros = 0;

        for(auto x: stones){
            sum += x%3;

            if(x%3 == 1) ones++;
            else if(x%3 == 2) twos++;
            else zeros++;
        }

        if(zeros%2==0){
            return ones>=1 && twos>=1;
        }

        return abs(ones-twos)>2;

        // sum = sum%3;

        // if(sum == 0) return n%2 == 0;

        // cout<<sum<<endl;

        // // for (auto x: vals) cout<<x;

        // cout<<ones<<' '<<twos<<' '<<zeros<<endl;

        // int tone = 0, ttwo = 0;

        // if(ones == twos){
        //     cout<<'1';
        //     if(zeros%2) return false;
        //     return true;
        // }

        // for(int i = 1; i<=n; i++){
        //     if(tone>ttwo){
        //         ones--;
        //         tone++;
        //     }
        //     else if (ttwo>tone){
        //         ttwo++;
        //         twos--;
        //     }

        //     if(tone == ttwo){
        //         if(ones == twos){
        //             cout<<'2';
        //             if(zeros%2 == 0) return i%2;
        //             return i%2 == 0;
        //         } else{
        //             cout<<'3';
        //             if(zeros%2) return i%2 == 0;
        //             return i%2;
        //         }

        //     }
        // }
               

        // cout<<'4';
        // return false;

    }
};