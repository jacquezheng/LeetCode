/**
 * Sort List https://oj.leetcode.com/problems/sort-list/
 * Sort a linked list in O(n log n) time using constant space complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *mid = split(head);
        mid = sortList(mid);
        head = sortList(head);
        return merge(head, mid);
    }
    ListNode *split(ListNode *curr){
        ListNode *ret = curr;
        ListNode *temp = curr;
        while(temp->next != NULL && temp->next->next!=NULL){
            temp = temp->next->next;
            ret = ret->next;
        }
        temp = ret->next;
        ret->next = NULL;
        return temp;
    }
    ListNode *merge(ListNode *list1, ListNode* list2){
        ListNode *ret;
        ListNode *tracker1 = list1, *tracker2 = list2;
        if(list1->val >= list2->val){
            ret = list2;
            tracker2 = tracker2->next;
        }
        else{
            ret = list1;
            tracker1 = tracker1->next;
        }
        ListNode *curr = ret;
        
        while(tracker1!=NULL && tracker2!=NULL){
            if(tracker2->val >= tracker1->val){
                curr->next = tracker1;
                tracker1 = tracker1->next;
            }
            else{
                curr->next = tracker2;
                tracker2 = tracker2->next;
            }
            curr = curr->next;
        }
        
        if(tracker1 == NULL)
            curr->next = tracker2;
        else
            curr->next = tracker1;
            
        return ret;
    }
};
