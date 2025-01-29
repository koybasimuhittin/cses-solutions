use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: i32 = buffer.trim().parse().expect("");
    let mut vec = Vec::new();

    for _ in 0..n {
        buffer = String::new();
        io::stdin().read_line(&mut buffer).unwrap();

        let pair: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().expect(""))
            .collect();

        vec.push((pair[1], pair[0]));
    }

    vec.sort();

    let mut cnt = 0i32;
    let mut current_time = 0i32;

    for (end, start) in vec {
        if start >= current_time {
            cnt += 1;
            current_time = end;
        }
    }

    println!("{cnt}");
}
