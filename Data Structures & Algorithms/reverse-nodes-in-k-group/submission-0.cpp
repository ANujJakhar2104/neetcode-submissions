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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *new_head = nullptr , *tail = nullptr , *prev_tail = nullptr;
        ListNode *temp = head;
        ListNode *prev = nullptr , *curr = nullptr;
        int cnt = 0;
        while (temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        int sets = cnt/k;
        cnt = 0;
        temp = head;
        while (temp != nullptr){
            if (cnt == 0){
                prev_tail = tail;
                tail = temp;
            }
            if (sets == 0) {
                prev_tail->next = temp;
                return new_head;
            }
            curr = temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            cnt++;
            if (cnt == k){
                if (new_head == nullptr) new_head = prev;
                else{
                    prev_tail->next = prev;
                }
                cnt = 0;
                prev = nullptr;
                sets--;
            }
        }

        if (cnt != 0){
            if (new_head == nullptr) new_head = prev;
            else{
                prev_tail->next = prev;
            }
            cnt = 0;
        }

        return new_head;
    }
};
