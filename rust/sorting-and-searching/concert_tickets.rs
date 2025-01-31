use std::collections::{BTreeSet, HashMap};
use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();

    let v: Vec<usize> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("Invalid input"))
        .collect();

    let (_n, _m) = (v[0], v[1]);

    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();

    let tickets: Vec<u32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("Invalid ticket price"))
        .collect();

    buffer.clear();
    io::stdin().read_line(&mut buffer).unwrap();

    let customers: Vec<u32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("Invalid customer budget"))
        .collect();

    let mut set: BTreeSet<u32> = BTreeSet::new();
    let mut map: HashMap<u32, u32> = HashMap::new();

    for &ticket in &tickets {
        *map.entry(ticket).or_insert(0) += 1;
        set.insert(ticket);
    }

    for &customer in &customers {
        if let Some(&ticket) = set.range(..=customer).next_back() {
            print!("{} ", ticket);

            if let Some(count) = map.get_mut(&ticket) {
                *count -= 1;
                if *count == 0 {
                    map.remove(&ticket);
                    set.remove(&ticket);
                }
            }
        } else {
            print!("-1 ");
        }
    }
    println!();
}
