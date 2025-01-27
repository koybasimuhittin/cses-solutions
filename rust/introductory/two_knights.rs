use std::io;

fn twoKnights(n: i64) -> i64 {
    (n * n) * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2)
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u32 = buffer.trim().parse().expect("");

    for i in (1..(n + 1)) {
        println!("{}", twoKnights(i.into()));
    }
}
