package main

import "fmt"

func foo(nums ...int) int {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	right[n-1] = nums[n-1] + 1

	for i := 1; i < n; i++ {
		if left[i-1] > nums[i-1] {
			left[i] = left[i-1]
		} else {
			left[i] = nums[i-1]
		}
	}

	for i := n - 2; i >= 0; i-- {
		if right[i+1] < nums[i+1] {
			right[i] = right[i+1]
		} else {
			right[i] = nums[i+1]
		}
	}

	ret := -1
	for i := 0; i < n; i++ {
		if left[i] < nums[i] && nums[i] < right[i] {
			ret = i
			break
		}
	}
	return ret
}

func main() {
	nums := []int{5, 1, 4, 3, 6, 8, 10, 7, 9}
	fmt.Println(foo(nums...))
}
