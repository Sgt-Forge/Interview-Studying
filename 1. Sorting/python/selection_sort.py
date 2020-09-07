from typing import List

def swap(arr: List[int], i: int, j: int):
    arr[i], arr[j] = arr[j], arr[i]

def selection_sort(arr: List[int]) -> List[int]:
    for sorted_ind in range(len(arr) - 1):
        smallest_ind = sorted_ind
        for unsorted_ind in range(sorted_ind + 1, len(arr)):
            if arr[unsorted_ind] < arr[smallest_ind]:
                smallest_ind = unsorted_ind
        swap(arr, sorted_ind, smallest_ind)

    return arr

if __name__ == '__main__':
    test1 = []
    test2 = [1]
    test3 = [1000, 937, 672, 321, 1, -38]
    test4 = [-838, 19999, 3, 2, 8573, -4]
    test5 = [1, 2, 3, 4, 5]

    assert(selection_sort(test1) == [])
    assert(selection_sort(test2) == [1])
    assert(selection_sort(test3) == [-38, 1, 321, 672, 937, 1000])
    assert(selection_sort(test4) == [-838, -4, 2, 3, 8573, 19999])
    assert(selection_sort(test5) == [1, 2, 3, 4, 5])
