local fact
fact = function (n)
    if n == 0 then return 1
    else return fact(n - 1) * n
    end
end

print(fact(5))