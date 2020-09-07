package main

import "fmt"

func selectionSort(array []int) []int {
	for currentInd := 0; currentInd <= len(array)-1; currentInd++ {
		smallestInd := currentInd
		for i := currentInd + 1; i < len(array); i++ {
			if array[i] < array[smallestInd] {
				smallestInd = i
			}
		}
		array[currentInd], array[smallestInd] = array[smallestInd], array[currentInd]
	}

	return array
}

func main() {
	test1 := []int{5, 4, 3, 2, 1}
	output := selectionSort(test1)
	fmt.Println(output)
}