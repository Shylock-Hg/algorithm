fn main() {
}

pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let len1 = nums1.len();
        let len2 = nums2.len();

        // O(M+N)
        let mut i = 0;
        let mut j = 0;
        while(i < len1 && j < len2) {
        }
        4.4
}

#[cfg(test)]
mod tests {

        struct Case{
                input: (Vec<i32>, Vec<i32>),
                output: f64,
        }

        #[test]
        fn test() {
                let c1 = Case {
                        input: (vec![1, 3], vec![2]),
                        output: 2.0,
                };
                let c2 = Case {
                        input: (vec![1, 4], vec![2, 3]),
                        output: 2.5,
                };
                assert_eq!(
                        c1.output,
                        super::find_median_sorted_arrays(c1.input.0, c1.input.1));
                assert_eq!(
                        c2.output,
                        super::find_median_sorted_arrays(c2.input.0, c2.input.1));
        }
}
