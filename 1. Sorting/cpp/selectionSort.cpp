#include <cassert>
#include <vector>
#include <iostream>

void selectionSort(std::vector<int> &arr);
void assertSorted(const std::vector<int> &, const std::vector<int> &);

int main(){
    std::vector<int> test1 = {};
    std::vector<int> test2 = {1};
    std::vector<int> test3 = {1000, 937, 672, 321, 1, -38};
    std::vector<int> test4 = {-838, 19999, 3, 2, 8573, -4};
    std::vector<int> test5 = {1, 2, 3, 4, 5};

    selectionSort(test1);
    selectionSort(test2);
    selectionSort(test3);
    selectionSort(test4);
    selectionSort(test5);

    assert( test1 == std::vector<int>{} );
    assertSorted(test2, std::vector<int> {1});
    assertSorted(test3, std::vector<int> {-38, 1, 321, 672, 937, 1000});
    assertSorted(test4, std::vector<int> {-838, -4, 2, 3, 8573, 19999});
    assertSorted(test5, std::vector<int> {1, 2, 3, 4, 5});

    return 0;
}

void selectionSort(std::vector<int> &arr){
    for(int sortInd = 0; sortInd < int(arr.size() - 1); ++sortInd){
        int smallestInd = sortInd;
        for(int unsortInd = sortInd + 1; unsortInd < arr.size(); ++unsortInd){
            if(arr[unsortInd] < arr[smallestInd]){
                smallestInd = unsortInd;
            }
        }
        std::swap(arr[smallestInd], arr[sortInd]);
    }
}

void assertSorted(const std::vector<int> &arr1, const std::vector<int> &arr2){
    assert( arr1.size() == arr2.size() );
    for(int i = 0; i < arr1.size(); ++i){
        assert( arr1[i] == arr2[i] );
    }
}