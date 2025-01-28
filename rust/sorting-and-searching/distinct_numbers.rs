use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: u32 = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut numbers: Vec<u32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut cnt = 1;

    numbers.sort();

    for i in 1..n {
        if numbers[i as usize] != numbers[(i - 1) as usize] {
            cnt += 1;
        }
    }

    println!("{cnt}");
}
