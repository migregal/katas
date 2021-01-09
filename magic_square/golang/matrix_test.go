package main

import "testing"

func TestColSum(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		col      int
		expected float64
	}{
		{[]float64{}, 0, 0, 0},
		{[]float64{0}, 1, 0, 0},
		{[]float64{1}, 1, 0, 1},
		{[]float64{1, 0, 0, 4}, 2, 1, 4},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, 0, 0},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 1, 15},
	}

	for _, test := range tests {
		actual := ColSum(test.matrix, test.size, test.col)
		if actual != test.expected {
			t.Errorf(
				"Expected ColSum(%+v, %v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.col,
				test.expected,
				actual,
			)
		}
	}
}

func TestRowSum(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		row      int
		expected float64
	}{
		{[]float64{}, 0, 0, 0},
		{[]float64{0}, 1, 0, 0},
		{[]float64{1}, 1, 0, 1},
		{[]float64{1, 0, 0, 4}, 2, 1, 4},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, 0, 1},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 0, 6},
	}

	for _, test := range tests {
		actual := RowSum(test.matrix, test.size, test.row)
		if actual != test.expected {
			t.Errorf(
				"Expected RowSum(%+v, %v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.row,
				test.expected,
				actual,
			)
		}
	}
}

func TestPrimaryDiagonalSum(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		expected float64
	}{
		{[]float64{}, 0, 0},
		{[]float64{0}, 1, 0},
		{[]float64{1}, 1, 1},
		{[]float64{1, 0, 0, 4}, 2, 5},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, 1},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 15},
	}

	for _, test := range tests {
		actual := PrimaryDiagonalSum(test.matrix, test.size)
		if actual != test.expected {
			t.Errorf(
				"Expected PrimaryDiagonalSum(%+v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.expected,
				actual,
			)
		}
	}
}

func TestSecondaryDiagonalSum(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		expected float64
	}{
		{[]float64{}, 0, 0},
		{[]float64{0}, 1, 0},
		{[]float64{1}, 1, 1},
		{[]float64{1, 0, 0, 4}, 2, 0},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, 0},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 15},
	}

	for _, test := range tests {
		actual := SecondaryDiagonalSum(test.matrix, test.size)
		if actual != test.expected {
			t.Errorf(
				"Expected SecondaryDiagonalSum(%+v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.expected,
				actual,
			)
		}
	}
}
