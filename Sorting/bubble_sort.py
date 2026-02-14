def bubble_sort(elements, n, type):
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
