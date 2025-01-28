use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let v: Vec<u32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    let (n, m, k) = (v[0], v[1], v[2]);

    buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let mut applicants: Vec<i32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    applicants.sort();

    buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let mut apartments: Vec<i32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect(""))
        .collect();

    apartments.sort();

    let mut applicant: usize = 0;

    let mut cnt = 0;

    'label: for i in 0..m {
        if applicant >= (n as usize) {
            break;
        }

        let mut diff = apartments[i as usize] - applicants[applicant];
        if diff.abs() <= k as i32 {
            cnt += 1;
            applicant += 1;
        } else {
            while diff > k as i32 {
                applicant += 1;
                if applicant >= (n as usize) {
                    break 'label;
                }
                diff = apartments[i as usize] - applicants[applicant];
            }

            if diff.abs() <= k as i32 {
                cnt += 1;
                applicant += 1;
            }
        }
    }

    println!("{cnt}");
}
