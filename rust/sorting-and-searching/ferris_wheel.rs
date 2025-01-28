use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let v: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let (n, m) = (v[0], v[1]);

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut v: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    v.sort();

    let mut r = (n - 1) as usize;
    let mut l = 0usize;

    let mut cnt = 0;

    while l <= r && r < (n as usize) && l < (n as usize) {
        if (v[l] + v[r]) <= m {
            cnt += 1;
            l += 1;
            r -= 1;
        } else {
            r -= 1;
            cnt += 1;
        }
    }

    println!("{cnt}");
}
