# 1. Two Sum

Given an array of integers and a target, return the indices of the two
numbers that add up to the target. Exactly one solution is guaranteed;
the same element can't be used twice.

## Approach

Single pass with a hash map from value to index. For each element, first
check whether its complement (`target - nums[i]`) is already in the map
— if so, that pair is the answer. Otherwise insert the current element's
value and index before moving on. Checking before inserting is what
prevents an element from pairing with itself. O(n) average time, O(n)
space.

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
