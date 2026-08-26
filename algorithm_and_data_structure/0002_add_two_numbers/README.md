# 2. Add Two Numbers

Two non-negative integers are given as linked lists, each digit a node,
least-significant digit first

Add the numbers and return the sum in the same format


```c
list_node_t *add_two_numbers(list_node_t *l1, list_node_t *l2);
```

Caller owns and must free the returned list

## Example

```
l1 = 2->4->3 (342), l2 = 5->6->4 (465) -> 7->0->8 (807)
```

## Build and test

```
make            # compiles the object file
make tests_run   # Criterion unit tests
```
