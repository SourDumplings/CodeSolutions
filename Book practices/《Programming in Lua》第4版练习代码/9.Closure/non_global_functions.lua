lib = {
    soo = function (x, y) return x - y end,
    doo = function (x, y) return x / y end
}

lib.aoo = function (x, y) return x + y end
lib.poo = function (x, y) return x * y end

print(lib.soo(2, 3))
print(lib.doo(2, 3))
print(lib.aoo(2, 3))
print(lib.poo(2, 3))