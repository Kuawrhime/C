# 1. Two Sum

Given an array of integers and a target, return the indices of the two
numbers that add up to the target. Exactly one solution is guaranteed
the same element can't be used twice

## Signature

```c
int *two_sum(int const *nums, int nums_size, int target, int *return_size);
```

Caller owns and must `free()` the returned array.

## Example

```
nums = [2,7,11,15], target = 9 -> [0,1]
nums = [3,2,4], target = 6 -> [1,2]
```

## Build and test

```
make            # compiles the object file
make tests_run   # Criterion unit tests
```

by kuawrhime