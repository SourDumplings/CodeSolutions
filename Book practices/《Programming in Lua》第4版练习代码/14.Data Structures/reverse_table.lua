require("../print_table")

days = {"Sunday", "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday"}

revDays = {}
for k,v in pairs(days) do
    revDays[v] = k
end

print_r(days)
print_r(revDays)