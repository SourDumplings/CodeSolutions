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

fn main()
{
    let res = gcd(15, 25);
    // let res = gcd(0, 25);
    println!("gcd of 15 and 25 is {}", res);
}
