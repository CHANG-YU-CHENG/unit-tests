#include <stdio.h>
#include <stdlib.h>

typedef struct List_node {
    int value;
    struct List_node *next;
} List;

List *swap(List *head, List *node_1, List *node_2)
{
    /*
    這邊先排除掉三個node其中為0  以及
    要交換的node相同的情形  有交換和沒交換是一樣的
    */
    if ( (head == NULL) ||
            (node_1 == NULL) || (node_2 == NULL) ||
            (node_1 == node_2))
        return head;


    /* _head用來暫時紀錄linked list最開頭的node address */
    List *_head = head;

    /*
    pre_node_1與pre_node_2用來紀錄在node_1與node_2之前的node
    tmp_node用來記錄其中一個(node_1 or node_2)的next address
    */
    List *pre_node_1 = NULL, *pre_node_2 = NULL, *tmp_node;

    if(head == node_1) { // pre_node_1 == NULL  ,  (head != node_2) is always true
        while (head && head->next) {
            if (head->next == node_2) {
                pre_node_2 = head;
                break;
            }
            head = head->next;
        }
        head = _head;
        if(pre_node_2 == NULL) // if node_2 was not found
            return head;
    } else if(head == node_2) { // pre_node_2 == NULL  ,  (head != node_1) is always true
        while (head && head->next) {
            if (head->next == node_1) {
                pre_node_1 = head;
                break;
            }
            head = head->next;
        }
        head = _head;
        if(pre_node_1 == NULL) // if node_1 was not found
            return head;
    } else { // (head != node_1) and (head != node_2) is always true
        while (head && head->next) {
            if (head->next == node_1)
                pre_node_1 = head;
            else if(head->next == node_2)
                pre_node_2 = head;
            head = head->next;
            if(pre_node_1 != NULL && pre_node_2 != NULL)
                break;
        }
        head = _head;
        if(pre_node_1 == NULL || pre_node_2 == NULL)
            return head;
    }

    /*以下兩個if處理node_1 或 node_2為head的情形*/
    if (pre_node_1 == NULL) {
        pre_node_2->next = node_1;
        tmp_node = node_1->next;
        node_1->next = node_2->next;
        node_2->next = tmp_node;
        return node_2;
    }

    if (pre_node_2 == NULL) {
        pre_node_1->next = node_2;
        tmp_node = node_2->next;
        node_2->next = node_1->next;
        node_1->next = tmp_node;
        return node_1;
    }

    /* 以下兩個if處理node_1 與 node_2相鄰 */
    if (node_2->next == node_1) {
        pre_node_2->next = node_1;
        node_2->next = node_1->next;
        node_1->next = node_2;
        return head;
    }

    if (node_1->next == node_2) {
        pre_node_1->next = node_2;
        node_1->next = node_2->next;
        node_2->next = node_1;
        return head;
    }

    pre_node_1->next = node_2;
    tmp_node = node_2->next;
    node_2->next = node_1->next;
    pre_node_2->next = node_1;
    node_1->next = tmp_node;
    return head;
}
