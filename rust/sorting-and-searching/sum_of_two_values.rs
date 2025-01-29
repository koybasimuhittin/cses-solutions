use std::io;

fn binary_search(target: i32, nums: &Vec<(i32, i32)>) -> usize {
    let mut l = 0usize;
    let mut r = nums.len();

    while l < r {
        let m = (l + r) / 2;
        if nums[m].0 < target {
            l = m + 1;
        } else if nums[m].0 >= target {
            r = m;
        }
    }
    return l;
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut v: Vec<i32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let (n, m) = (v[0], v[1]);

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    v = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut nums = Vec::new();

    for i in 0..n {
        nums.push((v[i as usize], i));
    }

    nums.sort();

    for (num, index) in &nums {
        if *num < m {
            let mut target_index = binary_search(m - *num, &nums);
            if target_index < n as usize && (nums[target_index].0 + *num) == m {
                if nums[target_index].1 == *index {
                    target_index += 1;
                }

                if target_index >= n as usize || (nums[target_index].0 + *num) != m {
                    continue;
                }

                println!("{} {}", index + 1, nums[target_index].1 + 1);
                return;
            }
        }
    }

    println!("IMPOSSIBLE");
}
