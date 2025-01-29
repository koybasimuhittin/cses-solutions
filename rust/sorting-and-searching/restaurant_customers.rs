use std::cmp::max;
use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: i32 = buffer.trim().parse().expect("");

    let mut vec: Vec<(i32, bool)> = vec![];

    for _ in 0..n {
        buffer = String::new();
        io::stdin().read_line(&mut buffer).unwrap();

        let pair: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().expect(""))
            .collect();

        vec.push((pair[0], true));
        vec.push((pair[1], false));
    }

    vec.sort();

    let mut index: usize = 0;
    let mut cnt: i32 = 0;
    let mut ans: i32 = 0;

    while index < vec.len() {
        let (a, b) = vec[index];
        index = index + 1;

        if b {
            cnt += 1;
        } else {
            cnt -= 1;
        }

        while index < vec.len() && vec[index].0 == a {
            if vec[index].1 {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            index += 1;
        }

        ans = max(ans, cnt);
    }

    println!("{ans}");
}
