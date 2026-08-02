#ifndef ADD_TWO_NUMBERS_H_
    #define ADD_TWO_NUMBERS_H_

typedef struct list_node_s {
    int val;
    struct list_node_s *next;
} list_node_t;

list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2);

#endif /* !ADD_TWO_NUMBERS_H_ */
