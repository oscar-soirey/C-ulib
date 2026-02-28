# C-ULIB
C-ulib is an extension of C-standard library and offers features such as vector, map, smart string, and others.

## Class
### ulib ver. 2.0
This header provides a complete objet oriented programming features in C.

## Map
### ulib ver. 1.1

## String
### ulib ver. 1.1

## Vector
### ulib ver. 1.0
To register a user-defined type, you can use the macro : `CVECTOR(type, name, eq_operator_func)` The equal operator func needs to have this signature : int {func_name}(const {T}* a, const {T}* b) with {T} the type of the vector
List of vector functions with {T} the name of the type : 
- `{T}_freevec(vec)` free the vector allocated memory.
- `{T}_pushback(vec, elem)` push the element at the end of the vector.
- `{T}_find(vec, elem)` returns the index of the first matching element, returns vec size if element was not found.
- `{T}_findall(vec, elem)` returns a size_t_vec of indexes of every matching elements.
- `{T}_at(vec, index)` returns the element at specified index, returns vec size if the element was not found.
- `{T}_remove(vec, index)` remove the element at specified index.
- `{T}_pop(vec)` remove the last element of the vector.
- `{T}_front(vec)` returns the first element.
- `{T}_end(vec)` returns the last element.
- `{T}_insert(vec, index, elem)` insert element at a given location.
- `{T}_erase(vec, start_index, end_index)` remove 
- `{T}_clear(vec)` clear the vector.
- `{T}_shrink_to_fit(vec)` 
- `{T}_append(vec, vec)` concatenate second vector to the first.
- `{T}_contains(vec, elem)` returns 1 if vec contains the element.

## Umap
### ulib ver. 1.0

## Memory
### ulib ver. 1.0
The cmemory lib is a collection of helpers to manage C memory, it offers features such as safe-delete, memory alloc check, value swap, static array count, ...
List of features : 
- `cnew(type)` allocate on the heap an instance of the desired type and returns a pointer.
- `ccheck(ptr)` checks the allocation and throws an error if the allocation failed.
- `cdelete(inst_ptr)` safe-delete an instance and make the ptr NULL.
- `cswap(type, a, b)` swap the values between two instances.
- `ccount(arr)` returns the number of elements in the static C array.
- `cmin(a, b)` returns the less
- `cmax(a, b)` returns the greater

## Filesystem
### ulib ver 1.0