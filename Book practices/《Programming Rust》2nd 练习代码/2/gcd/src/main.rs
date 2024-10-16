use std::env;
use std::str::FromStr;

fn gcd(mut n: u64, mut m: u64) -> u64
{
    // assert!(n != 0 && m != 0);
    debug_assert!(n != 0 && m != 0); // cargo run --release 下不会检查
    while m != 0
    {
        if m < n
        {
            let t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    n
}

#[test]
fn test_gcd()
{
    assert_eq!(gcd(14, 15), 1);
    assert_eq!(gcd(2 * 3 * 5 * 11 * 17, 3 * 7 * 11 * 13 * 19), 3 * 11);
}

/* 
cargo run 799459 28823 27347
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.00s
     Running `target\debug\gcd.exe 799459 28823 27347`
The greatest common divisor of [799459, 28823, 27347] is 41
*/
fn main()
{
    let mut numbers = Vec::new();
    for arg in env::args().skip(1)
    {
        numbers.push(u64::from_str(&arg).expect("error parsing argument"));
    }
    if numbers.len() == 0
    {
        eprintln!("Usage: gcd NUMBER ...");
        std::process::exit(1);
    }
    let mut d = numbers[0];
    for m in &numbers[1..]
    {
        d = gcd(d, *m);
    }
    println!("The greatest common divisor of {:?} is {}", numbers, d);
}
