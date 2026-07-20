# Longest Valid Parentheses

## Problem Statement

Given a string containing only `'('` and `')'`, return the length of the **longest valid (well-formed) parentheses substring**.

### Examples

```text
Input: "(()"
Output: 2

Input: ")()())"
Output: 4

Input: ""
Output: 0
```

---

# Solution Approach

## Intuition

A valid parentheses substring always starts after the most recent unmatched `')'` and ends at the current matching `')'`.

Instead of storing the characters themselves, I store **their indices** in a stack. This allows me to directly calculate the length of every valid substring whenever a matching pair is found.

To simplify the calculation, I initially push `-1` into the stack. This acts as a **base index** for the first valid substring.

---

## Algorithm

1. Push `-1` into the stack.
2. Traverse the string from left to right.
3. If the current character is `'('`, push its index.
4. Otherwise (`')'`):

   * Pop one index from the stack.
   * If the stack becomes empty, push the current index as the new base because no valid substring can extend beyond this unmatched `')'`.
   * Otherwise, the current valid substring length is:

     ```
     current_index - stack.top()
     ```

     Update the maximum answer.

---

## Why This Works

The stack always stores the indices of unmatched `'('` along with the latest invalid position.

Whenever a matching `')'` is found:

* The corresponding `'('` is removed.
* The new top of the stack represents the index just before the current valid substring begins.
* Therefore,

```
Length = current_index - stack.top()
```

gives the length of the longest valid substring ending at the current position.

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

where `n` is the length of the string.

---

## Key Learning

The main insight is that storing **indices instead of characters** makes it possible to compute substring lengths efficiently. The sentinel value `-1` eliminates edge cases and allows every valid substring length to be calculated using a simple subtraction.

---

## Technologies Used

* C++
* STL (`stack`)
* Linear Scan
* Stack-Based Algorithm
