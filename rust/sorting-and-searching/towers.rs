use std::io;

const N: usize = 200005;

fn binary_search(target: u32, array: &[u32; N]) -> usize {
    let mut l = 0usize;
    let mut r = N;

    while l < r {
        let m = (l + r) / 2;

        if array[m] <= target {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let n: usize = buffer.trim().parse().expect("");

    buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let v: Vec<u32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut towers = [u32::MAX; N];

    let mut ans = 0;

    for num in v {
        let index = binary_search(num, &towers);
        if towers[index] == u32::MAX {
            ans += 1;
        }

        towers[index] = num;
    }

    println!("{ans}");
}
