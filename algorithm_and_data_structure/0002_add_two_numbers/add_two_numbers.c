/*
** KORO PROJECT, 2026
** LeetCode 2 - Add Two Numbers
** File description:
** add_two_numbers
**
*/

#include <stdlib.h>
#include "add_two_numbers.h"

static int add_digits(list_node_t **l1, list_node_t **l2, int carry)
{
    int sum = carry;

    if (*l1 != NULL) {
        sum += (*l1)->val;
        *l1 = (*l1)->next;
    }
    if (*l2 != NULL) {
        sum += (*l2)->val;
        *l2 = (*l2)->next;
    }
    return (sum);
}

list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2)
{
    list_node_t dummy = {0, NULL};
    list_node_t *tail = &dummy;
    int carry = 0;
    int sum;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum = add_digits(&l1, &l2, carry);
        carry = sum / 10;
        tail->next = malloc(sizeof(list_node_t));
        tail->next->val = sum % 10;
        tail->next->next = NULL;
        tail = tail->next;
    }
    return (dummy.next);
}
