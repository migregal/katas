const N: usize = 3;

fn horizontal_sum(values: &[f64], j: usize) -> f64 {
    let mut sum = 0.0;

    for i in 0..N {
        sum += values[i + j * N]
    }

    sum
}

fn vertical_sum(values: &[f64], i: usize) -> f64 {
    let mut sum = 0.0;

    for j in 0..N {
        sum += values[i + j * N]
    }

    sum
}

fn primary_diagonal_sum(values: &[f64]) -> f64 {
    let mut sum = 0.0;

    for i in 0..N {
        sum += values[i + i * N]
    }

    sum
}

fn secondary_diagonal_sum(values: &[f64]) -> f64 {
    let mut sum = 0.0;

    for i in 0..N {
        sum += values[N - 1 - i + i * N]
    }

    sum
}

fn is_magic(values: &[f64]) -> bool {
    let sum = horizontal_sum(values, 0);
    (sum == horizontal_sum(values, 1))
        && (sum == horizontal_sum(values, 2))
        && (sum == vertical_sum(values, 0))
        && (sum == vertical_sum(values, 1))
        && (sum == vertical_sum(values, 2))
        && (sum == primary_diagonal_sum(values))
        && (sum == secondary_diagonal_sum(values))
}

#[allow(unused)]

fn permutation(values: &mut Vec<f64>, start: usize, end: usize) -> bool {
    if start == end {
        return is_magic(values.as_slice());
    }

    for i in start..=end {
        values.swap(i, start);

        if permutation(values, start + 1, end) {
            return true;
        }

        values.swap(i, start);
    }

    false
}

fn make_magic_square(values: &[f64]) -> Option<Vec<f64>> {
    let mut result = values.to_vec();

    if permutation(&mut result, 0, N * N - 1) {
        Some(result)
    } else {
        None
    }
}

fn main() {
    unimplemented!()
}

#[cfg(test)]
mod test {
    use super::*;
    use rand::Rng;

    #[test]
    fn zeros() {
        let values = [0.0; N * N];
        make_magic_square(&values).unwrap();
    }

    #[test]
    fn base_square() {
        let values: [f64; N * N] = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0];
        assert!(is_magic(make_magic_square(&values).unwrap().as_slice()));
    }

    #[test]
    fn one_hundred_random_magic_squares() {
        let mut rng = rand::thread_rng();

        let mut values = [0.0; N * N];

        for _i in 0..100 {
            for j in 0..N * N {
                values[j] = rng.gen_range(0..10) as f64;
            }

            if let Some(square) = make_magic_square(&values) {
                assert!(is_magic(square.as_slice()))
            }
        }
    }
}
