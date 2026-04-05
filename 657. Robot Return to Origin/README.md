# 657. Robot Return to Origin

## Problem Description

There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at `(0, 0)` after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its ith move. Valid moves are `'R'` (right), `'L'` (left), `'U'` (up), and `'D'` (down).

Return `true` if the robot returns to the origin after it finishes all of its moves, or `false` otherwise.

**Note:** The way that the robot is "facing" is irrelevant. `'R'` will always make the robot move to the right once, `'L'` will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

### Examples

**Example 1:**
* **Input:** moves = "UD"
* **Output:** true
* **Explanation:** The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.

**Example 2:**
* **Input:** moves = "LL"
* **Output:** false
* **Explanation:** The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.

### Constraints
* `1 <= moves.length <= 2 * 10^4`
* `moves` only contains the characters `'U'`, `'D'`, `'L'` and `'R'`.

---

## Approach

### Core Concept
The problem asks whether the robot returns to its exact starting coordinates `(0, 0)` on a 2D Cartesian plane. Because the robot operates on two independent axes (X-axis for horizontal movement and Y-axis for vertical movement), we can track its position by separating the horizontal and vertical moves. 

For the robot to return to the origin, any movement in one direction must be exactly canceled out by an equal amount of movement in the opposite direction. Specifically:
* Every `'U'` (Up) must be offset by a `'D'` (Down).
* Every `'R'` (Right) must be offset by an `'L'` (Left).

### Step-by-Step Logic
1.  **Initialize Coordinate Trackers:** Create two integer variables, `vertical` and `horizen` (horizontal), starting at 0. These represent the Y and X coordinates of the robot, respectively.
2.  **Iterate Through the Moves:**
    Loop through each character `c` in the string `moves`.
    * If `c == 'D'`, increment `vertical` by 1.
    * If `c == 'U'`, decrement `vertical` by 1.
    * If `c == 'R'`, increment `horizen` by 1.
    * If `c == 'L'`, decrement `horizen` by 1.
    *(Note: The exact addition or subtraction mapping does not matter, as long as opposite directions have opposite mathematical operations. For example, 'U' as +1 and 'D' as -1 works exactly the same way).*
3.  **Evaluate Final Position:**
    After processing all characters, check if both `vertical` and `horizen` equal `0`. If they do, the robot is back at the origin, and the function returns `true`. If either value is non-zero, it returns `false`.



---

## Complexity Analysis

* **Time Complexity:** $O(N)$
    Where $N$ is the length of the string `moves`. The algorithm iterates through each character of the string exactly once. The operations inside the loop (if-else conditions and variable increments/decrements) take constant time $O(1)$.
* **Space Complexity:** $O(1)$
    The memory used does not scale with the size of the input string. Only two integer variables (`vertical` and `horizen`) are created to store the coordinates, requiring constant extra space.