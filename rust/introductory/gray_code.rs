use std::io;

fn binary_str(num: i32, size: u16) -> String {
    let mut ans = String::new();

    for i in 0..size {
        if (num & (1 << i)) > 0 {
            ans += "1";
        } else {
            ans += "0";
        }
    }

    return ans;
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let n: u16 = buffer.trim().parse().expect("");

    let mut visited = [false; (1 << 16)];

    let mut curr = 0;
    for _i in 0..(1 << n) {
        println!("{}", binary_str(curr, n));
        visited[curr as usize] = true;
        for j in 0..n {
            if visited[(curr ^ (1 << j)) as usize] == false {
                curr = curr ^ (1 << j);
                break;
            }
        }
    }
}
