use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: i32 = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let nums: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut ans = i64::MIN;
    let mut curr = 0;

    for num in nums {
        curr += num;
        ans = std::cmp::max(ans, curr);
        if curr < 0 {
            curr = 0;
        }
    }

    println!("{ans}");
}
