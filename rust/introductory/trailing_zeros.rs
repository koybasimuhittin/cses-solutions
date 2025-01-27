use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let mut n: u64 = buffer.trim().parse().expect("");

    let mut ans = 0;

    while n > 0 {
        n /= 5;
        ans += n;
    }

    println!("{ans}");
}
