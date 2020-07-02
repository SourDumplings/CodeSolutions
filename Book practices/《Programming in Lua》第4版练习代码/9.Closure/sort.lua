require("../print_table")

network = {
    {name = "grauna", IP = "210.26.30.34"},
    {name = "arraial", IP = "210.26.30.23"},
    {name = "lua", IP = "210.26.23.12"},
    {name = "derain", IP = "210.26.23.20"},
}

print_r(network)

table.sort(network, function (a,b) return (a.name < b.name) end)

print_r(network)