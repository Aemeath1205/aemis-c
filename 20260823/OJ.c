#include <stdio.h>
#include <stdlib.h>

//移除链表元素 
//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
 
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* newhead = head;
    struct ListNode* tmphead = head;
    if (newhead == NULL) {
        return NULL;
    }
    while (newhead->val == val) {
        struct ListNode* tmphead1 = newhead;
        newhead = newhead->next;
        free(tmphead1);
        if (newhead == NULL) {
            return newhead;//NULL
        }
    }
    tmphead = newhead;
    while (tmphead->next != NULL) {
        if (tmphead->next->val == val) {
            struct ListNode* tmphead2 = tmphead->next;
            tmphead->next = tmphead->next->next;
            free(tmphead2);
        }
        else {
            tmphead = tmphead->next;
        }

    }
    return newhead;
}

//反转链表
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    struct ListNode* tmp = NULL;
    slow->next = NULL;
    while (fast != NULL) {
        tmp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = tmp;
    }
    return slow;
}

//链表中间结点
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    while (fast != NULL) {
        if (fast->next == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow;
}

//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode tmphead;
    tmphead.next = NULL;
    struct ListNode* realhead = &tmphead;//实际最后返回的是realhead->next
    struct ListNode* tmprealhead = realhead;
    if (list1 == NULL || list2 == NULL) {
        return (list1 == NULL ? list2 : list1);
    }
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tmprealhead->next = list1;
            list1 = list1->next;
            tmprealhead = tmprealhead->next;
        }
        else {
            tmprealhead->next = list2;
            list2 = list2->next;
            tmprealhead = tmprealhead->next;
        }
    }
    if (list1 == NULL) {
        tmprealhead->next = list2;
    }
    else {
        tmprealhead->next = list1;
    }
    return realhead->next;
}

//链表分割
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
// 且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
struct ListNode* partition(struct ListNode* pHead, int x) {
    struct ListNode newhead = {0,NULL};
    struct ListNode* realhead = &newhead;//最后实际返回realhead->next
    struct ListNode* tmprealhead = realhead;
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }

    struct ListNode beforehead = { 0,pHead };
    struct ListNode* leftphead = &beforehead;
    //leftphead = pHead;
    while (leftphead->next != NULL) {
        if (leftphead->next->val < x) {
            tmprealhead->next = leftphead->next;
            leftphead->next = leftphead->next->next;
            tmprealhead = tmprealhead->next;
            tmprealhead->next = NULL;
        }
        else {
            leftphead = leftphead->next;
        }
    }
    tmprealhead->next = beforehead.next;
    return realhead->next;
}

#include <stdbool.h>
//反转链表
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    struct ListNode* tmp = NULL;
    slow->next = NULL;
    while (fast != NULL) {
        tmp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = tmp;
    }
    return slow;
}

//回文链表
bool chkPalindrome(struct ListNode* A) {
    if (A == NULL) {
        printf("判断回文列表非法");
        exit(1);
    }
    struct ListNode* B = reverseList(middleNode(A));
    while (A != NULL && B != NULL) {
        if (A->val != B->val) {
            return false;
        }
        else {
            A = A->next;
            B = B->next;
        }
    }
    return true;
}

//相交列表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode* pa = headA;
    struct ListNode* pb = headB;
    int count1 = 0;
    int count2 = 0;
    while (pa != NULL) {
        pa = pa->next;
        count1++;
    }
    while (pb != NULL) {
        pb = pb->next;
        count2++;
    }
    int tmp = 0;
    if (count1 < count2) {
        tmp = count2 - count1;
        while (tmp != 0) {
            headB = headB->next;
            tmp--;
        }
    }
    else {
        tmp = count1 - count2;
        while (tmp != 0) {
            headA = headA->next;
            tmp--;
        }
    }
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        else {
            headA = headA->next;
            headB = headB->next;
        }
    }
    return NULL;
}

//判断是否有环
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

//判断入环点
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* tmp = NULL;
    int count = 0;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            tmp = fast;
            count = 1;
            break;
        }
    }
    if (count != 1) {
        return NULL;
    }
    else {
        while (1) {
            if (tmp == head) {
                return tmp;
            }
            else {
                tmp = tmp->next;
                head = head->next;
            }
        }
    }
}

 // Definition for a Node.
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
//随机链表的复制
struct Node* copyRandomList(struct Node* head) {
    
}