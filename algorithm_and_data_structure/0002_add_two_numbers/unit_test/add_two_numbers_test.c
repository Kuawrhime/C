#include <criterion/criterion.h>
#include <stdlib.h>
#include "../add_two_numbers.h"

static list_node_t *build_list(int const *vals, int n)
{
    list_node_t dummy = {0, NULL};
    list_node_t *tail = &dummy;

    for (int i = 0; i < n; i++) {
        tail->next = malloc(sizeof(list_node_t));
        tail->next->val = vals[i];
        tail->next->next = NULL;
        tail = tail->next;
    }
    return (dummy.next);
}

static void free_list(list_node_t *head)
{
    list_node_t *next;

    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}

static int list_eq(list_node_t *head, int const *vals, int n)
{
    for (int i = 0; i < n; i++) {
        if (head == NULL || head->val != vals[i])
            return (0);
        head = head->next;
    }
    return (head == NULL);
}

Test(add_two_numbers, example1)
{
    int v1[] = {2, 4, 3};
    int v2[] = {5, 6, 4};
    int expected[] = {7, 0, 8};
    list_node_t *l1 = build_list(v1, 3);
    list_node_t *l2 = build_list(v2, 3);
    list_node_t *res = add_two_numbers(l1, l2);

    cr_assert(list_eq(res, expected, 3));
    free_list(l1);
    free_list(l2);
    free_list(res);
}

Test(add_two_numbers, carries_propagate)
{
    int v1[] = {9, 9, 9, 9, 9, 9, 9};
    int v2[] = {9, 9, 9, 9};
    int expected[] = {8, 9, 9, 9, 0, 0, 0, 1};
    list_node_t *l1 = build_list(v1, 7);
    list_node_t *l2 = build_list(v2, 4);
    list_node_t *res = add_two_numbers(l1, l2);

    cr_assert(list_eq(res, expected, 8));
    free_list(l1);
    free_list(l2);
    free_list(res);
}
