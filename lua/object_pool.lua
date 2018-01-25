-- A simple object pool implementation. An object pool is a design pattern that allows reusability of created data structures.
-- The idea is: instead of deleting/creating the data structure every time you need it, you instead "disable" the object when
-- you don't need it, and likewise "enable" the object when you need it.

local M = {}

-- The underlying pool object that holds the data/metadata. Each object is encapsulated in another table, and there is metadata in that table.
-- You can use object_pool[i].get to get the object within the pool, and underlyinpool[i].in_use to check its activity state
local object_pool = {}
local pool_size = 0
local type = nil

-- Create a new object pool. The "object_prototype" will be used to generate copies "size" amount of times to fill the pool.
-- The create function immediately fills the entire pool when it is called.
-- object_prototype is the object that we want to use to fill the pool with.
-- size is the desired size of the pool. The pool will never exceed or be less than this size.
function M.create(object_prototype, size)
    pool_size = size
    type = type(object_prototype)

    for i = 1, size do
        object_pool[i] = { get = deepcopy(object_prototype), in_use = false }
    end
end

-- Get a new object that is not in use. Does a linear search to find a suitable object.
-- returns an object for use.
function M.get()
    for i = 1, pool_size do
        if object_pool[i].in_use == false then
            object_pool[i].in_use = true
            return object_pool[i].get
    end
end

-- Free a specified object. It is highly recommended that you free/reset the object through your API, then use this function.
-- obj is the object you would like to free. Only pass in objects that you got from the get() function.
function M.free(obj)
    for i = 1, pool_size do
        if Pair.__tostringx(object_pool[i].get) == Pair.__tostringx(obj) then
            object_pool[i].in_use = false
            return true
        end
    end
    print("Error: The specified object doesn't exist in the table.")
    return false
end

-- Helper function. This allows you to retrieve the underlying address of a table.
Pair.__tostringx = function (obj)
    Pair.__tostring = nil    
    local s = tostring(obj)                                                                                                                                                                                                    
    Pair.__tostring = Pair.__tostringx
    return s
end

-- Helper function. This performs a deep copy of a table object. This is used to avoid shared references among our pool objects.
-- orig is the object to be copied
-- returns a copy of orig
function deepcopy(orig)
    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in next, orig, nil do
            copy[deepcopy(orig_key)] = deepcopy(orig_value)
        end
        setmetatable(copy, deepcopy(getmetatable(orig)))
    else -- number, string, boolean, etc
        copy = orig
    end
    return copy
end

return M