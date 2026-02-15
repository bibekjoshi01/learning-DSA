"""
Insertion Sort revision notes.

Key idea:
- Keep two parts of the list: sorted (left) and unsorted (right).
- Pick one element from the unsorted part.
- Shift larger elements right, then insert the picked element in place.

Complexity:
- Time (best): O(n)
- Time (avg/worst): O(n^2)
- Extra space: O(1) auxiliary (in-place)

Important point:
- Insertion Sort is stable when equal elements are not swapped across
  each other (as in this implementation).
"""


def insertion_sort(elements, n):
    """
    Sort a list in ascending order using Insertion Sort.
    """
    for i in range(1, n):
        key = elements[i]
        j = i - 1

        while j >= 0 and key < elements[j]:
            elements[j + 1] = elements[j]
            j = j - 1

        elements[j + 1] = key

    return elements


if __name__ == "__main__":
    elements = [4, 1, 0, 9, 2, 0, 3, 4, -1]
    sorted = insertion_sort(elements, len(elements))
    print(sorted)
