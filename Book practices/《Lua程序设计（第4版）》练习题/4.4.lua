-- Ref: chatgpt4
-- Exercise 4.4: Redo the previous exercise for UTF-8 strings:
--
-- > insert ("ação", 5, "!") --> ação!
--
-- (Note that the position now is counted in codepoints.)
-- function utf8_insert(original_str, pos, insert_str)
--     -- 将字符串分解为UTF-8码点的表
--     local function to_utf8_codepoints(str)
--         local codepoints = {}
--         for uchar in string.gmatch(str, "([%z\1-\127\194-\244][\128-\191]*)") do
--             table.insert(codepoints, uchar)
--         end
--         return codepoints
--     end
--     -- 将UTF-8码点表重新组合成字符串
--     local function from_utf8_codepoints(codepoints)
--         return table.concat(codepoints)
--     end
--     -- 将原始字符串和插入字符串转换为UTF-8码点表
--     local original_codepoints = to_utf8_codepoints(original_str)
--     local insert_codepoints = to_utf8_codepoints(insert_str)
--     -- 在指定位置插入字符串
--     for i = #insert_codepoints, 1, -1 do
--         table.insert(original_codepoints, pos, insert_codepoints[i])
--     end
--     -- 将码点表转换回字符串并返回
--     return from_utf8_codepoints(original_codepoints)
-- end
-- -- 示例使用
-- local original_str = "你好世界"
-- local insert_str = " Lua 的"
-- local pos = 3 -- 在"好"和"世"之间插入
-- local new_str = utf8_insert(original_str, pos, insert_str)
-- print(new_str) -- 输出: 你好 Lua 的世界
-- utf8_insert("你好", 2, "真是") --> 你真是好
-- utf8_insert("你好", 1, "真是") --> 真是你好
-- 
-- 
-- Lua 5.3
-- -- Ref: https://github.com/oitofelix/pil-4th/blob/main/ex-4.4.lua
-- -- Exercise 4.4: Redo the previous exercise for UTF-8 strings:
-- --
-- -- > insert ("ação", 5, "!") --> ação!
-- --
-- -- (Note that the position now is counted in codepoints.)
-- function insert(to, i, from)
--     return to:sub(1, utf8.offset(to, i - 1)) .. from .. to:sub(utf8.offset(to, i), -1)
-- end

-- insert("ação", 5, "!") -- > ação!

-- 
-- Lua 5.4.4
function insert(to, i, from)
    -- print(utf8.offset(to, i - 1))
    -- print(utf8.offset(to, i))
    -- print(utf8.offset(to, i + 1))
    -- print(to:sub(1, utf8.offset(to, i - 1)))
    -- print(to:sub(1, utf8.offset(to, i) - 1))
    -- print(to:sub(utf8.offset(to, i), -1))
    return to:sub(1, utf8.offset(to, i) - 1) .. from .. to:sub(utf8.offset(to, i), -1)
end

-- Original string, insert string, and position
local original_str = "你好世界"
local insert_str = " Lua 的"
local pos = 3 -- Insert between "好" and "世"

-- Perform the insertion
local new_str = insert(original_str, pos, insert_str)

-- Output the new string
print(new_str) -- Expected output: 你好 Lua 的世界

insert("你好", 1, "真是") -- > 真是你好
insert("你好", 2, "真是") -- > 你真是好
insert("你好", 2, "真 tm ") -- > 你真 tm 好
