    class Solution {
    public:

        string str_add(string &prev, string &ans){
            int n = prev.size();
            int m = ans.size();

            string ret;

            int i = n-1, j = m-1;
            int carry = 0;

            while(i>=0 && j>=0){
                int a = prev[i] - '0';
                int b = ans[j] - '0';

                int c = a + b + carry;

                carry = c/10;
                ret+= c%10 + '0';

                i--;
                j--;
            }

            while(i>=0){
                int a = prev[i]-'0';

                int c = a+carry;

                carry = c/10;
                ret+= c%10 + '0';
                i--;
            }

            while(j>=0){
                int a = ans[j]-'0';

                int c = a+carry;

                carry = c/10;
                ret+= c%10 + '0';
                j--;
            }

            if(carry) ret+=carry+'0';

            reverse(ret.begin(), ret.end());

            return ret;
        }

        string multiply(string num1, string num2) {
            int carry = 0;

            int n = num1.size();
            int m = num2.size();

            if(num1 == "0" || num2 == "0") return "0";

            string prev = "";

            for(int i = n-1; i>=0; i--){
                string ans;
                int a = num1[i] - '0';

                carry = 0;

                for(int j = m-1; j>=0; j--){
                    int b = num2[j] - '0';

                    int val = a*b + carry;

                    int to_add = val%10;

                    ans+= to_add + '0';

                    carry = val/10;

                }
                if(carry) ans+= carry + '0';

                reverse(ans.begin(), ans.end());

                if(prev.empty()) swap(prev, ans);

                else{
                    ans += string(n - 1 - i, '0');
                    ans = str_add(prev, ans);
                    swap(prev, ans);
                }

                ans = "";
            }

            return prev;


        }
    };