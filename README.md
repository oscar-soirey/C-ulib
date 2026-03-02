# C-ULIB
C-ulib is an extension of C-standard library and offers features such as vector, map, smart string, and others.

---

## Class (2.0)
This header provides a complete objet oriented programming features in C.

---

## Map (1.1)

---

## String (1.1)

---

## Vector (1.0)
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

---

## Umap (1.0)

---

## Memory (1.0)
The cmemory lib is a collection of helpers to manage C memory, it offers features such as safe-delete, memory alloc check, value swap, static array count, ...
List of features : 
- `cnew(type)` allocate on the heap an instance of the desired type and returns a pointer.
- `ccheck(ptr)` checks the allocation and throws an error if the allocation failed.
- `cdelete(inst_ptr)` safe-delete an instance and make the ptr NULL.
- `cswap(type, a, b)` swap the values between two instances.
- `ccount(arr)` returns the number of elements in the static C array.
- `cmin(a, b)` returns the less
- `cmax(a, b)` returns the greater

---

## Optional (1.0)
The coptional library allows functions to return either a value or nothing, which can be useful for:
- Functions that might fail without throwing exceptions,
- Replacing sentinel values (-1, NULL) with safe handling,
- Expressing optional parameters or results.

List of features :
With {T} being the type registered via the macro COPTIONAL(TYPE, NAME):
- `{T}_opt_return(value)` – returns an optional containing a value.
- `{T}_opt_none()` – returns an empty optional.

---

## Filesystem (1.0)
The cfilesystem library provides utilities to manipulate file paths and interact with the filesystem in a cross-platform way. Paths are represented by the cfs_path struct, which internally uses a vector of strings for path components.
Functions:

### Notes:

All functions returning strings allocate memory that the caller must free.
Paths are internally normalized to / for simplicity; use `cfs_to_str_Win` for Windows-specific operations.
`cfs_path` vectors must be freed using `char_ptr_vec_freevec(&path.components)` when no longer needed to avoid memory leaks.

### Normalization and conversion:

- `cfs_normalize_slashes(char* path)` – converts all backslashes (\) to slashes (/) in a string.
- `cfs_str_to_path(const char* in)` – converts a C string path into a cfs_path object, splitting components at / or \.
- `cfs_to_str(cfs_path in)` – converts a cfs_path back to a Unix-style string path (/ separators).
- `cfs_to_str_Win(cfs_path in)` – converts a cfs_path back to a Windows-style string path (\ separators).

### Filesystem checks:

- `cfs_exists(cfs_path path)` – returns 1 if the path exists.
- `cfs_is_file(cfs_path path)` – returns 1 if path is a regular file.
- `cfs_is_dir(cfs_path path)` – returns 1 if path is a directory.
- `cfs_file_size(cfs_path path)` – returns file size in bytes, -1 on error.

### Path component utilities:

- `cfs_file_name(cfs_path path)` – returns the filename without extension of the last component, or NULL if none.
- `cfs_extension(cfs_path path)` – returns the extension of the last component, or NULL if none.
- `cfs_parent_path(cfs_path in)` – returns a cfs_path representing the parent directory, removing the last component.

### Not Implemented yet:
This functions are not implemented yet but will be for the 1.0.0 release.

- `void cfs_is_absolute(cfs_path path)` – returns 1 if path is absolute.
- `void cfs_create_dir(cfs_path path)` – creates a new directory at the given path.
- `void cfs_remove_file(cfs_path path)` – removes a file at the given path.
- `void cfs_remove_dir(cfs_path path)` – removes a directory at the given path (non-recursive by default).
- `void cfs_rename(cfs_path path, const char* name)` – renames the last component of the path.
- `void cfs_copy(cfs_path src, cfs_path dst)` – copies a file from src to dst.
- `void cfs_move(cfs_path src, cfs_path dst)` – moves or renames a file or directory from src to dst.
- `char_ptr_vec cfs_list_dir(cfs_path path, int glob)` – lists files and directories under path; if glob is true, lists recursively.
- `cfs_path cfs_join(cfs_path a, cfs_path b)` – joins two paths into a single cfs_path.
- `double cfs_last_modified(cfs_path path)` – returns the last modified timestamp of a file.
- `file_rights cfs_permissions(cfs_path path)` – returns the file rights (read, write, execute) of the path.