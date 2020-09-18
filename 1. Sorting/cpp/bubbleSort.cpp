#include <cassert>
#include <vector>
#include <iostream>

void bubbleSort(std::vector<int> &arr);
void assertSorted(const std::vector<int> &, const std::vector<int> &);

int main(){
    std::vector<int> test1 = {};
    std::vector<int> test2 = {1};
    std::vector<int> test3 = {1000, 937, 672, 321, 1, -38};
    std::vector<int> test4 = {-838, 19999, 3, 2, 8573, -4};
    std::vector<int> test5 = {1, 2, 3, 4, 5};

    bubbleSort(test1);
    bubbleSort(test2);
    bubbleSort(test3);
    bubbleSort(test4);
    bubbleSort(test5);

    assert( test1 == std::vector<int>{} );
    assertSorted(test2, std::vector<int> {1});
    assertSorted(test3, std::vector<int> {-38, 1, 321, 672, 937, 1000});
    assertSorted(test4, std::vector<int> {-838, -4, 2, 3, 8573, 19999});
    assertSorted(test5, std::vector<int> {1, 2, 3, 4, 5});

    return 0;
}

void bubbleSort(std::vector<int> &arr){
    int count = 0;
    while(count < arr.size()){
        int i = 0;
        while(i < arr.size() - 1 - count){
            if(arr[i] > arr[i + 1]){
                std::swap(arr[i], arr[i + 1]);
            }
            ++i;
        }
        ++count;
    }
}

void assertSorted(const std::vector<int> &arr1, const std::vector<int> &arr2){
    assert( arr1.size() == arr2.size() );
    for(int i = 0; i < arr1.size(); ++i){
        assert( arr1[i] == arr2[i] );
    }
}