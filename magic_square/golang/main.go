package main

import "fmt"

func main() {
	size := 3
	matrix := make([]float64, size*size)

	for i := 1; i <= size*size; i++ {
		matrix[i-1] = float64(i)
	}

	if err := MakeMagicSquare(&matrix, size); err != nil {
		fmt.Println(matrix)
		fmt.Println(err)
		return
	}

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			fmt.Printf("%5.2f ", matrix[i*size+j])
		}
		fmt.Println()
	}
}
