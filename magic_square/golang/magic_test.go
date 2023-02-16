package main

import "testing"

func TestIsMagic(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		expected bool
	}{
		{[]float64{}, 0, true},
		{[]float64{0}, 1, true},
		{[]float64{1}, 1, true},
		{[]float64{1, 0, 0, 4}, 2, false},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, false},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, false},
		{[]float64{2, 7, 6, 9, 5, 1, 4, 3, 8}, 3, true},
	}

	for _, test := range tests {
		actual := IsMagic(&test.matrix, test.size)
		if actual != test.expected {
			t.Errorf(
				"Expected IsMagic(%+v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.expected,
				actual,
			)
		}
	}
}

func TestPermutation(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		expected bool
	}{
		{[]float64{}, 0, false},
		{[]float64{0}, 1, true},
		{[]float64{1}, 1, true},
		{[]float64{1, 0, 0, 4}, 2, false},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, false},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, true},
		{[]float64{2, 7, 6, 9, 5, 1, 4, 3, 8}, 3, true},
	}

	for _, test := range tests {
		actual := Permutation(&test.matrix, test.size, 0)
		if actual != test.expected {
			t.Errorf(
				"Expected Permutation(%+v, %v) to be %v, got %v",
				test.matrix,
				test.size,
				test.expected,
				actual,
			)
		}
	}
}

func TestMakeMagicSquare(t *testing.T) {
	var tests = []struct {
		matrix   []float64
		size     int
		expected bool
	}{
		{[]float64{}, 0, false},
		{[]float64{0}, 1, true},
		{[]float64{1}, 1, true},
		{[]float64{1, 0, 0, 4}, 2, false},
		{[]float64{1, 0, 0, -1, 0, 0, 0, 0, 0}, 3, false},
		{[]float64{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, true},
		{[]float64{2, 7, 6, 9, 5, 1, 4, 3, 8}, 3, true},
	}

	for _, test := range tests {
		actual := MakeMagicSquare(&test.matrix, test.size)
		if (test.expected && actual != nil) || (!test.expected && actual == nil) {
			t.Errorf(
				"Expected MakeMagicSquare(%+v, %v) to be with error (%v), got with (%v)",
				test.matrix,
				test.size,
				test.expected,
				actual,
			)
		}
	}
}
