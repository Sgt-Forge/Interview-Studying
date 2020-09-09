from typing import List

def swap(arr: List[int], i: int, j: int):
    arr[i], arr[j] = arr[j], arr[i]

def insertion_sort(arr: List[int]) -> List[int]:
    for i in range(len(arr) - 1):
        next_elem = i + 1
        while next_elem > 0 and arr[next_elem] < arr[next_elem - 1]:
            swap(arr, next_elem, next_elem - 1)
            next_elem -= 1

    return arr

if __name__ == '__main__':
    test1 = []
    test2 = [1]
    test3 = [1000, 937, 672, 321, 1, -38]
    test4 = [-838, 19999, 3, 2, 8573, -4]
    test5 = [1, 2, 3, 4, 5]

    assert(insertion_sort(test1) == [])
    assert(insertion_sort(test2) == [1])
    assert(insertion_sort(test3) == [-38, 1, 321, 672, 937, 1000])
    assert(insertion_sort(test4) == [-838, -4, 2, 3, 8573, 19999])
    assert(insertion_sort(test5) == [1, 2, 3, 4, 5])
