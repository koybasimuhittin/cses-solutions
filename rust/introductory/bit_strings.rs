use std::io;

const MOD: u64 = 1000000007;

fn fastpow(base: u64, pow: u64) -> u64 {
    if pow == 0 {
        1
    } else {
        let x = fastpow(base, pow / 2);
        if pow % 2 == 0 {
            (x * x) % MOD
        } else {
            (((x * x) % MOD) * base) % MOD
        }
    }
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u64 = buffer.trim().parse().expect("");

    println!("{}", fastpow(2, n));
}
