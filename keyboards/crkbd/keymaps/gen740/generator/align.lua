local function smart_split(s)
	local result = {}
	local buf = {}
	local i = 1
	local in_bracket = false
	local bracket_depth = 0

	while i <= #s do
		local c = s:sub(i, i)

		if c == "[" then
			in_bracket = true
			bracket_depth = bracket_depth + 1
			table.insert(buf, c)
		elseif c == "]" and in_bracket then
			bracket_depth = bracket_depth - 1
			table.insert(buf, c)
			if bracket_depth == 0 then
				in_bracket = false
			end
		elseif c == "," and not in_bracket then
			local field = table.concat(buf):match("^%s*(.-)%s*$")
			table.insert(result, field)
			buf = {}
		else
			table.insert(buf, c)
		end

		i = i + 1
	end

	if #buf > 0 then
		local field = table.concat(buf):match("^%s*(.-)%s*$")
		table.insert(result, field)
	end

	return result
end

vim.api.nvim_create_user_command("Align", function(args)
	local start_line = args.line1
	local end_line = args.line2
	local text = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)

	local data = {}

	for i, v in ipairs(text) do
		data[i] = vim.tbl_map(function(x)
			return x:match("^%s*(.-)%s*$")
		end, smart_split(v))
	end

	local text_width = {
		math.max(data[1][1]:len(), data[2][1]:len(), data[3][1]:len()),
		math.max(data[1][2]:len(), data[2][2]:len(), data[3][2]:len()),
		math.max(data[1][3]:len(), data[2][3]:len(), data[3][3]:len(), data[4][1]:len()),
		math.max(data[1][4]:len(), data[2][4]:len(), data[3][4]:len(), data[4][2]:len()),
		math.max(data[1][5]:len(), data[2][5]:len(), data[3][5]:len(), data[4][3]:len()),
		math.max(data[1][6]:len(), data[2][6]:len(), data[3][6]:len(), data[4][4]:len()),
		math.max(data[1][7]:len(), data[2][7]:len(), data[3][7]:len(), data[4][5]:len()),
		math.max(data[1][8]:len(), data[2][8]:len(), data[3][8]:len(), data[4][6]:len()),
		math.max(data[1][9]:len(), data[2][9]:len(), data[3][9]:len()),
		math.max(data[1][10]:len(), data[2][10]:len(), data[3][10]:len()),
	}

	local ret = {}

	for i = 1, 3 do
		ret[i] = {}
		for j = 1, 10 do
			ret[i][j] = string.format("%-" .. text_width[j] .. "s,", data[i][j])
		end
	end

	ret[4] = {
		string.rep(" ", text_width[1] + text_width[2] + 3),
	}
	for j = 1, 6 do
		ret[4][j + 1] = string.format("%-" .. text_width[j + 2] .. "s,", data[4][j])
	end

	local ret_text = {}
	for i = 1, 4 do
		ret_text[i] = table.concat(ret[i], " ")
	end
    vim.api.nvim_buf_set_lines(0, start_line - 1, end_line, false, ret_text)
end, {
	range = true,
})
