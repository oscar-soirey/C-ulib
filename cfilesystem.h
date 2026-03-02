#ifndef CFILESYSTEM_CULIB_H
#define CFILESYSTEM_CULIB_H

#include <stdio.h>
#include "cvector.h"

#ifdef _WIN32
#include <windows.h>
#define SYS_PATH_MAX MAX_PATH   //260 by default
#else
#include <limits.h>
#define SYS_PATH_MAX PATH_MAX   //4096 most of time
#endif

#include <sys/stat.h>


typedef struct {
	//maybe later change vector type to cstring
	char_ptr_vec components;
}cfs_path;

void cfs_normalize_slashes(char* path)
{
	for (char* p = path; *p; ++p)
	{
		if(*p == '\\')
		{
			*p = '/';
		}
	}
}

//convertions
cfs_path cfs_str_to_path(const char* in)
{
	//create path object
	cfs_path path;

	//init vector before we use it, replace with vec_init function
	memset(&path.components, 0, sizeof(path.components));
	path.components.size = 0;
	path.components.capacity = 0;

	//modifiable copy
	char* temp = strdup(in);
	cfs_normalize_slashes(temp);

	//split at '/' or '\'
	char* token = strtok(temp, "/\\");
	while(token)
	{
		//copy the token because we free the temp after the function
		char* tok_copy = strdup(token);
		char_ptr_pushback(&path.components, tok_copy);
		token = strtok(NULL, "/\\");
	}

	free(temp);

	return path;
}

//unix version (with '/')
char* cfs_to_str(cfs_path in)
{
	char* buffer = (char*)malloc(SYS_PATH_MAX*sizeof(char));
	buffer[0] = '\0';
	for(int i = 0; i < in.components.size; i++)
	{
		strcat(buffer, in.components.data[i]);
		if(i+1 != in.components.size)
		{
			strcat(buffer, "/");
		}
	}
	return buffer;
}
//Windows version (with '\')
char* cfs_to_str_Win(cfs_path in)
{
	char* buffer = (char*)malloc(SYS_PATH_MAX*sizeof(char));
	buffer[0] = '\0';
	for(int i = 0; i < in.components.size; i++)
	{
		strcat(buffer, in.components.data[i]);
		if(i+1 != in.components.size)
		{
			strcat(buffer, "\\");
		}
	}
	return buffer;
}

//verifications / informations
int cfs_exists(cfs_path path)
{
	return access(cfs_to_str(path), F_OK) == 0;
}

int cfs_is_file(cfs_path path)
{
	struct stat st;
	if(stat(cfs_to_str(path), &st) != 0) 
	{
		//not a file
		return 0;
	}
	//return true if regular file
	return S_ISREG(st.st_mode);
}

int cfs_is_dir(cfs_path path)
{
	struct stat st;
	if(stat(cfs_to_str(path), &st) != 0)
	{
		return 0;
	}
	//true if directory
	return S_ISDIR(st.st_mode);
}

size_t cfs_file_size(cfs_path path)
{
	FILE* f = fopen(cfs_to_str(path), "rb");
	if(f == NULL)
	{
		perror("cfs_file_size open file error\n");
		return -1;
	}

	//move at the end of the file
	fseek(f, 0, SEEK_END);

	//get current location
	size_t s = ftell(f);

	fclose(f);
	return s;
}

int cfs_is_absolute(cfs_path path)
{

}

char* cfs_file_name(cfs_path path)
{
	//copy the last element of the path (the file)
	char* filename = (char*)malloc(SYS_PATH_MAX*sizeof(char));
	strcpy(filename, char_ptr_back(&path.components));

	//search for last '.'
	char* dot = strrchr(filename, '.');
	if(dot != NULL)
	{
		*dot = '\0';
		return filename;
	}
	return NULL;
}

char* cfs_extension(cfs_path path)
{
	//same as file_name
	char* filename = (char*)malloc(SYS_PATH_MAX*sizeof(char));
	strcpy(filename, char_ptr_back(&path.components));

	char* dot = strrchr(filename, '.');
	if(dot == NULL || *(dot + 1) == '\0')
	{
		//no extension
		return NULL;
	}
	//return everything after the '.'
	return dot + 1;
}

cfs_path cfs_parent_path(cfs_path in)
{
	cfs_path path;
	//replace with vec_init function
	memset(&path.components, 0, sizeof(path.components));
	path.components.size = 0;
	path.components.capacity = 0;

	for(int i = 0; i < in.components.size; i++)
	{
		//not the last one
		if(i+1 != in.components.size)
		{
			char_ptr_pushback(&path.components, in.components.data[i]);
		}
	}

	return path;
}

void cfs_create_dir(cfs_path path)
{

}

void cfs_remove_file(cfs_path path)
{

}

void remove_dir(cfs_path path)
{

}

/**
 * Rename the last part of the path
 */
void cfs_rename(cfs_path path, const char* name)
{

}

void cfs_copy(cfs_path src, cfs_path dst)
{

}

void cfs_move(cfs_path src, cfs_path dst)
{

}

/**
 * List path and file of a directory
 * @param glob recursive list
 */
char_ptr_vec cfs_list_dir(cfs_path path, int glob)
{

}

cfs_path cfs_join(cfs_path a, cfs_path b)
{

}

/**
 * @return Last modified timestamp
 */
double cfs_last_modified(cfs_path path)
{

}

typedef enum {
	W, R, X
}file_rights;

file_rights cfs_permissions(cfs_path path)
{

}

#endif