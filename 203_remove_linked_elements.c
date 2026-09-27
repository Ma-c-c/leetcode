/*
 * 203. 移除链表元素
 * https://leetcode.cn/problems/remove-linked-list-elements/
 *
 * ── 题目要求 ──
 * 给你一个链表的头节点 head 和一个整数 val，
 * 删除链表中所有满足 Node.val == val 的节点，并返回新的头节点。
 * ── 解法：虚拟头结点 + 一趟遍历 ──
 * 在真正的头节点前面加一个「假的」头结点（fake/dummy），好处是：
 * 原来的第一个节点也有了「前一个节点」，删除它不再需要特判。
 *   fake ──→ head ──→ ... ──→ NULL
 *    ↑
 *   cur 从这里出发
 * ── 我踩过的坑 ──
 * 1. 比较写成 cur->next == val
 *     → cur->next 是指针，val 是 int，类型不匹配。应为 cur->next->val == val
 *
 * 2. 循环条件写成 while (cur != NULL)
 *     → 循环体里用的是 cur->next，条件就该围着它写。
 *       若用 cur != NULL，cur 走到末尾时会访问 NULL->val，空指针解引用 → 崩溃
 *     → 应为 while (cur->next != NULL)
 * 3. 没有 else 分支 → 不需要删的时候 cur 不动 → 死循环
 */

 /*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode fake;
    fake.next = head;
    struct ListNode *cur = &fake;
    while (cur->next!=NULL)
    {
        if (cur->next->val == val)
        {
            cur->next = cur->next->next;
            
        }
        else
        {
        cur = cur->next;
        }
        
    }
   return fake.next;
}
