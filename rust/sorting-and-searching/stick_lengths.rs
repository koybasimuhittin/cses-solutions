use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: usize = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut nums: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut ans = 0;

    nums.sort();

    for num in &nums {
        let diff = nums[n / 2] - *num;
        ans += diff.abs();
    }

    println!("{ans}");
}
