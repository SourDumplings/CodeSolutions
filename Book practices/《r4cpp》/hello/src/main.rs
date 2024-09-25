fn foo(_x: &'static str) -> &'static str
{
    // "World No Return"
    return "FooWorld";
}

fn main()
{
    // let world = "World";
    // let world: &'static str = "World";
    println!("Hello, {}!", foo("bar"));
}
