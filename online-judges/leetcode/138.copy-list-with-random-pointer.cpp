/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copy = NULL;

        Node* curOrg = head;
        Node* curCopy = copy;

        curOrg = head, curCopy = copy;
        while (curOrg != NULL) {
            curCopy = new Node(curOrg->val);
            curCopy->next = curOrg->next;
            curOrg->next = curCopy;
            curOrg = curCopy = curCopy->next;
        }

        curOrg = head;
        while (curOrg != NULL) {
            curCopy = curOrg->next;

            if (curOrg->random != NULL)
                curCopy->random = curOrg->random->next;

            curOrg = curOrg->next->next;
        }
        
        copy = head == NULL ? NULL : head->next;

        curOrg = head;
        while (curOrg != NULL) {
            curCopy = curOrg->next;

            curOrg->next = curCopy->next;
            if (curCopy->next != NULL)
                curCopy->next = curOrg->next->next;

            curOrg = curOrg->next;
        }

        return copy;
    }
};
// @lc code=end

