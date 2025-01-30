use std::collections::HashMap;
use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: usize = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let v: Vec<i32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut map: HashMap<i32, bool> = HashMap::new();

    let mut l: usize = 0;
    let mut r: usize = 0;
    let mut ans = 0;

    while r < n {
        while l < n && *map.get(&v[r]).unwrap_or(&false) {
            map.remove(&v[l]);
            l += 1;
        }

        map.insert(v[r], true);
        ans = std::cmp::max(ans, r - l + 1);
        r += 1;
    }

    println!("{ans}");
}
