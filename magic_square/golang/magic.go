package main

import (
	"errors"
)

func IsMagic(arr *[]float64, size int) bool {
	magic := ColSum((*arr), size, 0)

	for i := 0; i < size; i++ {
		if magic != ColSum(*arr, size, i) {
			return false
		}

		if magic != RowSum(*arr, size, i) {
			return false
		}
	}

	if magic != PrimaryDiagonalSum(*arr, size) {
		return false
	}

	if magic != SecondaryDiagonalSum(*arr, size) {
		return false
	}

	return true
}

func Permutation(arr *[]float64, size, idx int) bool {
	if idx == len(*arr)-1 {
		return IsMagic(arr, size)
	}

	for i := idx; i < len(*arr); i++ {
		(*arr)[idx], (*arr)[i] = (*arr)[i], (*arr)[idx]
		if Permutation(arr, size, idx+1) {
			return true
		}
		(*arr)[idx], (*arr)[i] = (*arr)[i], (*arr)[idx]
	}

	return false
}

func MakeMagicSquare(arr *[]float64, size int) error {
	tmp := make([]float64, len(*arr))
	_ = copy(tmp, *arr)

	if !Permutation(&tmp, size, 0) {
		return errors.New("square isn't magical")
	}

	_ = copy(*arr, tmp)

	return nil
}
