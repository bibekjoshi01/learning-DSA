"""
Bubble Sort revision notes.

Key idea:
- Repeatedly compare adjacent elements and swap them if they are out of order.
- After each outer pass, the largest (asc) or smallest (dsc) unsorted value
  moves to its final position.

Variants in this file:
1. bubble_sort: always runs all passes.
2. optimized_bubble_sort: stops early if a full pass makes no swaps.

Complexity:
- Time (worst/avg): O(n^2)
- Time (best, optimized version): O(n) when already sorted
- Extra space: O(1) auxiliary (in-place)
"""


def bubble_sort(elements, n, type):
    """
    Sort a list using the standard Bubble Sort algorithm.
    """
    for i in range(n):
        print(f"Iteration {i}: {elements}")
        for j in range(0, n - i - 1):
            if type == "asc":
                if elements[j] > elements[j + 1]:
                    elements[j], elements[j + 1] = elements[j + 1], elements[j]
            elif type == "dsc":
                if elements[j] < elements[j + 1]:
                    elements[j], elements[j + 1] = elements[j + 1], elements[j]

    return elements


def optimized_bubble_sort(elements, n, type):
    """
    Sort a list using optimized Bubble Sort with early termination.

    Optimization:
    - Tracks whether any swap happened in a full pass.
    - If no swaps happen, the list is already sorted and the algorithm stops.
    """
    for i in range(n):
        print(f"Iteration {i}: {elements}")
        swapped = False
        for j in range(0, n - i - 1):
            if type == "asc":
                if elements[j] > elements[j + 1]:
                    elements[j], elements[j + 1] = elements[j + 1], elements[j]
                    swapped = True
            elif type == "dsc":
                if elements[j] < elements[j + 1]:
                    elements[j], elements[j + 1] = elements[j + 1], elements[j]
                    swapped = True

        if not swapped:
            break

    return elements


if __name__ == "__main__":
    elements = [4, 1, 0, 9, 2, 3, -1]
    sorted = optimized_bubble_sort(elements, len(elements), "dsc")
    print(sorted)
