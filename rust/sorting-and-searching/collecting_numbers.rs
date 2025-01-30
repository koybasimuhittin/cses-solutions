use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: usize = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let v: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut positions = vec![0; n + 1];

    for i in 1..=n {
        positions[v[(i - 1) as usize] as usize] = i;
    }

    let mut curr: usize = 1;
    let mut cnt = 0;

    while curr <= n {
        cnt += 1;
        while curr + 1 <= n && positions[curr + 1] > positions[curr] {
            curr += 1;
        }

        curr += 1;
    }

    println!("{cnt}");
}
