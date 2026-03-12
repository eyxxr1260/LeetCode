# 3600. Maximize Spanning Tree Stability with Upgrades

## Problem Description

You are given an integer `n`, representing `n` nodes numbered from `0` to `n - 1` and a list of `edges`, where $edges[i] = [u_i, v_i, s_i, must_i]$:

* $u_i$ and $v_i$ indicates an undirected edge between nodes $u_i$ and $v_i$.
* $v_i$ is the strength of the edge.
* $must_i$ is an integer (0 or 1). If `musti == 1`, the edge **must** be included in the spanning tree. These edges **cannot** be upgraded.

You are also given an integer `k`, the maximum number of upgrades you can perform. Each upgrade **doubles** the strength of an edge, and each eligible edge (with `musti == 0`) can be upgraded at most once.
The **stability** of a spanning tree is defined as the **minimum** strength score among all edges included in it.
Return the **maximum** possible stability of any valid spanning tree. If it is impossible to connect all nodes, return `-1`.

**Constraints:**

* `2 <= n <= 10^5`
* `1 <= edges.length <= 10^5`
* `1 <= si <= 10^5`

---

## Approach

This problem combines two powerful concepts: **Binary Search on the Answer** and **Disjoint Set Union (DSU)**.

### Step 1: Binary Search on Answer ("Maximize the Minimum")

Whenever a problem asks to "maximize the minimum" value, it is a massive hint to use Binary Search. Instead of trying to build the optimal tree directly (which is incredibly complex with the `k` constraint), we **guess** a target stability score.
We then ask: *"Is it possible to build a valid spanning tree where every single edge has a strength of at least `target`?"*

* If **Yes**, we try a higher target (greedily maximizing).
* If **No**, we lower our target.

### Step 2: The `check(target)` Function using DSU

For a guessed `target`, we greedily try to connect the graph using DSU in three strict phases:

1. **Mandatory Edges (`must = 1`)**: We must use these. If any mandatory edge has a strength strictly less than our `target`, it's an immediate failure because they cannot be upgraded.
2. **Free Optional Edges (`must = 0` and `strength >= target`)**: These edges already meet our target stability. We greedily add as many as possible because they don't consume any upgrade points (`k`).
3. **Upgradable Edges (`must = 0` and `strength * 2 >= target`)**: These edges fall short, but can meet the target *only if* we spend `1` upgrade point. We add them as needed, tracking how many upgrades we consume. If we exceed `k` upgrades, it fails.

If we successfully connect all `n` nodes using $n - 1$ edges within these rules, the guessed `target` is valid.

---


## Complexity Analysis

* **Time Complexity:** $O(E \log(MaxStrength) \cdot \alpha(V))$
Where $E$ is the number of edges and $V$ is the number of nodes. The binary search runs $\log_2(200000) \approx 18$ times. In each iteration, we traverse the edge list taking $O(E)$ time. DSU operations take near-constant time $O(\alpha(V))$ due to path compression. This is highly optimal and comfortably passes the 100,000 node constraint.
* **Space Complexity:** $O(V)$
We initialize the DSU parent array of size `n` (which is $V$), giving us a linear space complexity.
