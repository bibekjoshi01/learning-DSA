"""
Linear Search quick revision notes:
- Scan elements from left to right and compare each with the target.
- Works on unsorted data.
- Returns the first match when duplicates exist.
- Time: O(n) worst/average, O(1) best (target at first index).
- Space: O(1) auxiliary.
"""


def linear_search(elements, target):
    """Return index of first match, else False if target is not present."""
    for i in range(len(elements)):
        if target == elements[i]:
            return i

    return False


if __name__ == "__main__":
    elements = [7, 5, 4, 32, 9, 5, -1]
    target = 32
    index = linear_search(elements, target)

    # Use explicit check so index 0 is treated as a valid match.
    if index is not False:
        print(f"Element '{target}' found at index {index}")
    else:
        print("Not Found")
