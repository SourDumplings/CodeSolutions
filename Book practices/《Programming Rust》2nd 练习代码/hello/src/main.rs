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

fn main()
{
    let res = gcd(15, 25);
    // let res = gcd(0, 25);
    println!("gcd of 15 and 25 is {}", res);
}
