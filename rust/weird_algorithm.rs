use std::io;

fn main() {
    let mut n = String::new();

    io::stdin().read_line(&mut n);

    let mut n: u64 = match n.trim().parse() {
        Ok(val) => val,
        Err(_) => return,
    };

    while (n > 1) {
        print!("{n} ");
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    println!("{n}");
}
