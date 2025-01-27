use std::io;

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

    let mut n: u32 = buffer.trim().parse().expect("");

    while n > 0 {
        buffer = String::new();
        io::stdin().read_line(&mut buffer);

        let mut input = buffer.split_whitespace();
        let row: u64 = input.next().unwrap().parse().unwrap();
        let col: u64 = input.next().unwrap().parse().unwrap();

        if (row > col) {
            if (row % 2 == 0) {
                println!("{}", row * row - col + 1);
            } else {
                println!("{}", (row - 1) * (row - 1) + col);
            }
        } else {
            if (col % 2 == 0) {
                println!("{}", (col - 1) * (col - 1) + row);
            } else {
                println!("{}", col * col - row + 1);
            }
        }
        n -= 1;
    }
}
