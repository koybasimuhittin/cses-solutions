use std::io;

fn solve(from: u8, to: u8, n: u8) {
    if n == 0 {
        return;
    }

    solve(from, 6 - (from + to), n - 1);
    println!("{from} {to}");
    solve(6 - (from + to), to, n - 1);
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u8 = buffer.trim().parse().expect("");

    println!("{}", (1 << n) - 1);
    solve(1, 3, n);
}
