use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let input: Vec<usize> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let (n, m): (usize, usize) = (input[0], input[1]);

    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();

    let mut v: Vec<i64> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let mut positions = vec![0; n + 2];

    for i in 1..=n {
        positions[v[(i - 1) as usize] as usize] = i;
    }
    positions[n + 1] = n + 1;

    let mut bool_arr: Vec<bool> = Vec::new();

    let mut curr: usize = 0;
    let mut cnt = 0;

    while curr <= n + 1 {
        cnt += 1;
        while curr <= n && positions[curr + 1] > positions[curr] {
            curr += 1;
            bool_arr.push(true);
        }
        bool_arr.push(false);
        curr += 1;
    }

    let mut q: Vec<usize> = Vec::new();
    for _i in 0..m {
        buffer.clear();
        io::stdin().read_line(&mut buffer).unwrap();

        q = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().expect(""))
            .collect();
        let (a, b) = (v[q[0] - 1], v[q[1] - 1]);

        let temp = positions[a as usize];
        positions[a as usize] = positions[b as usize];
        positions[b as usize] = temp;

        v[q[0] - 1] = b;
        v[q[1] - 1] = a;

        let mut old = bool_arr[(a - 1) as usize];
        let mut new = positions[(a - 1) as usize] < positions[a as usize];

        if old == true && new == false {
            cnt += 1;
        } else if old == false && new == true {
            cnt -= 1;
        }

        bool_arr[(a - 1) as usize] = new;

        old = bool_arr[a as usize];
        new = positions[(a + 1) as usize] > positions[a as usize];

        if old == true && new == false {
            cnt += 1;
        } else if old == false && new == true {
            cnt -= 1;
        }

        bool_arr[a as usize] = new;

        old = bool_arr[(b - 1) as usize];
        new = positions[(b - 1) as usize] < positions[b as usize];

        if old == true && new == false {
            cnt += 1;
        } else if old == false && new == true {
            cnt -= 1;
        }

        bool_arr[(b - 1) as usize] = new;

        old = bool_arr[b as usize];
        new = positions[(b + 1) as usize] > positions[b as usize];

        if old == true && new == false {
            cnt += 1;
        } else if old == false && new == true {
            cnt -= 1;
        }

        bool_arr[b as usize] = new;

        println!("{cnt}");
    }
}
