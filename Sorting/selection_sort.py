"""
Selection Sort revision notes.

Key idea:
- Keep two parts of the list: sorted (left) and unsorted (right).
- In each pass, find the minimum value from the unsorted part.
- Swap it with the first index of the unsorted part.

Complexity:
- Time (best/avg/worst): O(n^2)
- Extra space: O(1) auxiliary (in-place)

Important point:
- Basic Selection Sort is not stable because swapping can change
  the relative order of equal elements.
"""


def selection_sort(elements, n, type):
    """
    Sort a list in ascending order using Selection Sort.
    """

    for step in range(n):
        idx = step

        for j in range(step + 1, n):

            if type == "asc":
                if elements[j] < elements[idx]:
                    idx = j
            elif type == "dsc":
                if elements[j] > elements[idx]:
                    idx = j

        (elements[step], elements[idx]) = (elements[idx], elements[step])

    return elements


if __name__ == "__main__":
    elements = [4, 1, 0, 9, 2, 0, 3, 4, -1]
    sorted = selection_sort(elements, len(elements), "dsc")
    print(sorted)
