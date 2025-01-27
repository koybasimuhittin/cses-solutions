use std::cmp::max;
use std::io;

fn main() {
    let mut buffer = String::new();

    io::stdin().read_line(&mut buffer);
    let chars: Vec<char> = buffer.chars().collect();

    let mut cnt: u32 = 1;
    let mut ans: u32 = 1;

    for i in (1..(chars.len())) {
        if chars[i] != chars[i - 1] {
            cnt = 0;
        }
        cnt += 1;
        ans = max(ans, cnt);
    }

    println!("{ans}");
}
