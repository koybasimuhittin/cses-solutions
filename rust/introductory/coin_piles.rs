use std::cmp;
use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u64 = buffer.trim().parse().expect("");

    for i in 0..n {
        buffer = String::new();
        io::stdin().read_line(&mut buffer);

        let mut input = buffer.split_whitespace();
        let x: u64 = input.next().unwrap().parse().unwrap();
        let y: u64 = input.next().unwrap().parse().unwrap();

        if (x + y) % 3 == 0 && cmp::max(x, y) <= 2 * cmp::min(x, y) {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
