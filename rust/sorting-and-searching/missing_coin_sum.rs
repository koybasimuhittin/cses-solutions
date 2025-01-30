use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: i32 = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut v: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    v.sort();

    let mut searching = 1;

    for num in v {
        if num > searching {
            break;
        }

        searching = num + searching;
    }

    println!("{searching}");
}
