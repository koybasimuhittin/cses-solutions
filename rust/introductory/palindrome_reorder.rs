use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);
    let buffer = buffer.trim();

    let mut cnt = [0; 30];

    for c in buffer.as_bytes() {
        cnt[(c - ('A' as u8)) as usize] += 1;
    }

    let mut index: i32 = -1;

    for i in 0..30 {
        if index != -1 && cnt[i as usize] % 2 == 1 {
            println!("NO SOLUTION");
            return;
        } else if cnt[i as usize] % 2 == 1 {
            index = i as i32;
        }
    }

    for i in 0..30 {
        if i == index {
            continue;
        }

        for j in 0..(cnt[i as usize] / 2) {
            print!("{}", (i as u8 + 'A' as u8) as char);
        }
    }

    if index != -1 {
        for j in 0..(cnt[index as usize]) {
            print!("{}", (index as u8 + 'A' as u8) as char);
        }
    }

    for i in (0..30).rev() {
        if i == index {
            continue;
        }

        for j in 0..(cnt[i as usize] / 2) {
            print!("{}", (i as u8 + 'A' as u8) as char);
        }
    }
}
