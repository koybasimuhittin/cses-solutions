use std::io;

fn solve(cnt: &mut [u32; 30], size: usize, curr: String) {
    if size == 0 {
        println!("{}", curr);
        return;
    }
    for i in 0..30 {
        if cnt[i as usize] > 0 {
            cnt[i as usize] -= 1;
            solve(
                cnt,
                size - 1,
                format!("{}{}", curr, (i + 'a' as u8) as char),
            );
            cnt[i as usize] += 1;
        }
    }
}

fn fact(n: u32) -> u32 {
    if n == 0 {
        1
    } else {
        n * fact(n - 1)
    }
}

fn main() {
    let mut buffer = String::new();
    let mut cnt = [0; 30];

    io::stdin().read_line(&mut buffer);
    let buffer = buffer.trim();

    for c in buffer.as_bytes() {
        cnt[(c - 'a' as u8) as usize] += 1;
    }
    let mut ans: u32 = fact(buffer.len() as u32);
    for i in 0..30 {
        ans /= fact(cnt[i as usize]);
    }
    println!("{ans}");
    solve(&mut cnt, buffer.len(), String::new());
}
