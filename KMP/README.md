# KMP

### Goal

Finding all occurrences of a pattern (substring) within a larger text efficiently.

### Key Idea

It preprocesses the pattern to create a longest prefix suffix (LPS) array, which helps determine the maximum length of matching prefixes that can be skipped when a mismatch occurs.

### Time Complexity

O(n+m)