use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u32 = buffer.trim().parse().expect("");

    if n > 1 && n <= 3 {
        println!("NO SOLUTION");
    } else {
        for i in (2..(n + 1)).step_by(2) {
            print!("{i} ");
        }
        for i in (1..(n + 1)).step_by(2) {
            print!("{i} ");
        }
    }
}
