use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u64 = buffer.trim().parse().expect("");

    if n * (n + 1) % 4 != 0 {
        println!("NO");
        return;
    }

    let mut target = (n * (n + 1)) / 4;

    let mut set1 = Vec::new();
    let mut set2 = Vec::new();

    for i in (1..(n + 1)).rev() {
        if target >= i {
            target -= i;
            set1.push(i);
        } else {
            set2.push(i);
        }
    }

    println!("YES\n{}", set1.len());
    for e in set1 {
        print!("{e} ");
    }
    println!("\n{}", set2.len());
    for e in set2 {
        print!("{e} ");
    }
}
