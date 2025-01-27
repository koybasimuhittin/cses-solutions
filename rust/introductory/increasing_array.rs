use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u32 = buffer.trim().parse().expect("");

    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let mut numbers: Vec<u64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut ans = 0;
    for index in (1..(numbers.len())) {
        if numbers[index] < numbers[index - 1] {
            ans += numbers[index - 1] - numbers[index];
            numbers[index] = numbers[index - 1];
        }
    }

    println!("{ans}");
}
