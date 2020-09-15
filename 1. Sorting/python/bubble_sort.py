def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def bubble_sort(arr):
    count = 0 
    while count < len(arr):
        i = 0
        while i < len(arr) - 1 - count:
            if arr[i] > arr[i + 1]:
                swap(arr, i, i + 1)
            i += 1
        count += 1


def main():
    test1 = []
    test2 = [1]
    test3 = [1000, 937, 672, 321, 1, -38]
    test4 = [-838, 19999, 3, 2, 8573, -4]
    test5 = [1, 2, 3, 4, 5]

    bubble_sort(test1)
    bubble_sort(test2)
    bubble_sort(test3)
    bubble_sort(test4)
    bubble_sort(test5)

    assert(test1 == [])
    assert(test2 == [1])
    assert(test3 == [-38, 1, 321, 672, 937, 1000])
    assert(test4 == [-838, -4, 2, 3, 8573, 19999])
    assert(test5 == [1, 2, 3, 4, 5])


if __name__ == '__main__':
    main()