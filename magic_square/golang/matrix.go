package main

func ColSum(array []float64, size, col int) float64 {
	result := 0.

	for i := 0; i < size; i++ {
		result += array[i*size+col]
	}

	return result
}

func RowSum(array []float64, size, row int) float64 {
	result := 0.

	for i := 0; i < size; i++ {
		result += array[i+row*size]
	}

	return result
}

func PrimaryDiagonalSum(array []float64, size int) float64 {
	result := 0.

	for i := 0; i < size; i++ {
		result += array[i+i*size]
	}

	return result
}

func SecondaryDiagonalSum(array []float64, size int) float64 {
	result := 0.

	for i := 0; i < size; i++ {
		result += array[size-1-i+i*size]
	}

	return result
}
