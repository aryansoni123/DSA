/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    bool isCritical(ListNode* prev, ListNode* curr){
        if(curr->next == NULL) return false;

        return (prev->val < curr->val && curr->next->val < curr->val) || (prev->val > curr->val && curr->next->val > curr->val);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int cnt = 1;

        int first = -1, last = -1;
        int prevcritical = -1;
        int mini = INT_MAX;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr){
            cnt++;

            if(isCritical(prev, curr)){
                
                // cout<<cnt;
                // cout<<endl;
                // cout<<prev->val<<' '<<curr->val;
                // cout<<endl;

                if(first == -1){
                    first = cnt;
                } else{
                    last = cnt;
                }

                if(prevcritical != -1) mini = min(mini, cnt - prevcritical);

                prevcritical = cnt;
            }

            prev = curr;
            curr = curr->next;
        }

        int maxi = last - first;

        if(first == -1 || last == -1){
            maxi = -1;
        }

        if(mini == INT_MAX){
            mini = -1;
        }

        return {mini, maxi};


    }
};