-- local count = 0

function newCounter ()
    local count = 0
    return function () -- anonymous function
        count = count + 1
        return count
    end
end

c1 = newCounter()
c2 = newCounter()

print(c1())
print(c2())
print(c1())
print(c2())
print(c1())
