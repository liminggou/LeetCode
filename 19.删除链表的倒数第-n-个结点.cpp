/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = 0;
        ListNode* cur = head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        while(cur != NULL) {
            index++;
            cur = cur->next;
        }
        if (index == 1) {
            head = NULL;
            return head;
        }
        int a = index - n;
        cur = head;
        ListNode* pre = newHead;
        while(a--) {
            cur = cur->next;
            pre = pre->next;
        }
       // cout<<cur->val<<endl;
        /*if(cur->next != NULL && cur->next->next != NULL) {
            cur->next = cur->next->next;
        }
        else {
            cur->next = NULL;
        }*/
        pre->next = cur->next;
        //delete cur;
        head = newHead->next;
        delete newHead;
        return head;
    }
};
// @lc code=end

