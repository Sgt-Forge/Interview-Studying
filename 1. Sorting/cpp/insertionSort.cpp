#include <cassert>
#include <vector>
#include <iostream>

void insertionSort(std::vector<int> &arr);
void assertSorted(const std::vector<int> &, const std::vector<int> &);

int main(){
    std::vector<int> test1 = {};
    std::vector<int> test2 = {1};
    std::vector<int> test3 = {1000, 937, 672, 321, 1, -38};
    std::vector<int> test4 = {-838, 19999, 3, 2, 8573, -4};
    std::vector<int> test5 = {1, 2, 3, 4, 5};

    insertionSort(test1);
    insertionSort(test2);
    insertionSort(test3);
    insertionSort(test4);
    insertionSort(test5);

    assert( test1 == std::vector<int>{} );
    assertSorted(test2, std::vector<int> {1});
    assertSorted(test3, std::vector<int> {-38, 1, 321, 672, 937, 1000});
    assertSorted(test4, std::vector<int> {-838, -4, 2, 3, 8573, 19999});
    assertSorted(test5, std::vector<int> {1, 2, 3, 4, 5});

    return 0;
}

void insertionSort(std::vector<int> &arr){
    for(int i = 0; i < int(arr.size()); ++i){
        int curr = i;
        while(curr > 0){
            if(arr[curr] < arr[curr - 1]){
                std::swap(arr[curr], arr[curr - 1]);
            } else {
                break;
            }
            curr -= 1;
        }
    }
}

void assertSorted(const std::vector<int> &arr1, const std::vector<int> &arr2){
    assert( arr1.size() == arr2.size() );
    for(int i = 0; i < arr1.size(); ++i){
        assert( arr1[i] == arr2[i] );
    }
}