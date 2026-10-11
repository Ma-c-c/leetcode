/*
 * 707. 设计链表
 * https://leetcode.cn/problems/design-linked-list/
 *
 * ── 题目要求 ──
 * 实现 MyLinkedList 类，支持：
 *   get(index)              获取第 index 个节点的值，无效返回 -1
 *   addAtHead(val)          头部插入
 *   addAtTail(val)          尾部插入
 *   addAtIndex(index, val)  第 index 个位置前插入；index == 长度时追加到末尾；
 *                           index > 长度时不插入
 *   deleteAtIndex(index)     删除第 index 个节点，无效则不操作
 *
 * ── 核心设计：虚拟头结点 ──
 * 结构体第一个节点是「头结点（dummy）」，不存有效数据，只用来当锚点。
 *
 *      obj → [假] → 数据0 → 数据1 → 数据2 → NULL
 *            ↑
 *       下标相当于 -1
 *
 * 好处：原来的第一个数据节点也有了「前一个节点」，
 *       于是「头插」「中间插」「尾插」全部变成同一套代码。
 * ── 三个通用套路 ──
 * 【套路 1】定位前驱：走 index 步
 *     MyLinkedList* p = obj;        // 从头结点（下标 -1）出发
 *     int i = 0;
 *     while (i < index && p->next != NULL) { p = p->next; i++; }
 *     // 正常结束 → p 停在下标 index-1（插入/删除位置的前一个）
 *     // 提前退出 → i < index，说明 index 超界
 *
 * 【套路 2】插入两步（顺序不能反：先接后，再接前）
 *     s->next = p->next;
 *     p->next = s;
 * 【套路 3】删除三步（先存、再摘、最后 free）
 *     MyLinkedList* target = p->next;   // ① 先存住
 *     p->next = target->next;           // ② 从链上摘下来
 *     free(target);                     // ③ 再释放
 * ── 我踩过的坑 ──
 *  1. 超界检查失效
 *     while (i < index && p->next != NULL) { ... }
 *     if (p == NULL) return;        
 *     → 循环条件用的是 p->next != NULL，p 从头到尾不会变成 NULL
 *     → 后果：index 超界时会错误地插到末尾
 *     → 应检查 i：if (i < index) return;
 * ── 与之前题目的呼应 ──
 *   addAtHead   ← 链表头插（addFront）
 *   addAtTail   ← 尾插建表（inputList），需要 tail 指针
 *   addAtIndex  ← 203 的「虚拟头结点 + 定位前驱」
 *   deleteAtIndex ← 203 的删除核心（改指针），加上 free
 *   free        ← freeList 的遍历释放模式
 *   本题 = 把之前所有链表操作组装到一个结构里。
 */
typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* L = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    L->next = NULL;
    return L;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList* p = obj->next;
    while (p != NULL)
    {
        if (i == index)
        {
            return p->val;
        }
        i++;
        p = p->next;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->next = obj->next;
    obj->next = p;
    p->val = val;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* p = obj;
    while (p->next != NULL)
    {
        p = p->next;
    }
    MyLinkedList* s = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->next = s;
    s->next = NULL;
    s->val = val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
     MyLinkedList* p = obj;
     int i = 0;
    while (i < index && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    if (i < index) return;

        MyLinkedList* s = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        s->val = val;
        s->next = p->next;
        p->next = s;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* p = obj;
     int i = 0;
    while (i < index && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) return;
    MyLinkedList* target = p->next;
    p->next = target->next;
    free(target);
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj != NULL)
    {
         MyLinkedList* tmp = obj->next;
        free(obj);
        obj = tmp;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
