"""
Binary Search quick revision notes:
- Works only on sorted data.
- Compare target with middle element, then discard half of the search space.
- Repeat until found or range becomes empty.
- Time: O(log n)
- Space: O(1) auxiliary (iterative version)
"""


def binary_search(elements, target):
    """Return target index if found, else False."""
    low = 0
    high = len(elements) - 1

    while low <= high:
        mid = low + (high - low) // 2
        if elements[mid] == target:
            return mid
        elif elements[mid] > target:
            high = mid - 1
        elif elements[mid] < target:
            low = mid + 1

    return False


if __name__ == "__main__":
    elements = [5, 7, 9, 12, 32, 59]
    target = 32
    index = binary_search(elements, target)

    # Use explicit check so index 0 is treated as a valid match.
    if index is not False:
        print(f"Element '{target}' found at index {index}")
    else:
        print("Not Found")
