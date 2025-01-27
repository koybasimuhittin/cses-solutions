use std::io;

fn main() {
    let mut buffer = String::new();
    let mut v = [false; 200005];

    io::stdin().read_line(&mut buffer);

    let n: u64 = match buffer.trim().parse() {
        Ok(val) => val,
        Err(_) => 0,
    };

    buffer = String::new();

    io::stdin().read_line(&mut buffer);

    let numbers: Vec<usize> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("Not a valid number"))
        .collect();

    for num in numbers {
        v[num] = true;
    }

    for num in (1..(n + 1)) {
        let curr = num as usize;
        if !v[curr] {
            println!("{curr}");
        }
    }
}
