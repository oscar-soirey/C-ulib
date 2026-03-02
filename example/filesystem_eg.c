#include "../cfilesystem.h"

#define LOG_PATH for(int i = 0; i < p.components.size; i++) { printf("%s/\n", p.components.data[i]); }

int main()
{
	cfs_path p = cfs_str_to_path("file/file.txt.h");
	
	if(cfs_exists(p))
	{
		printf("exists\n");
	}
	else
	{
		printf("doesnt exists\n");
	}

	if(cfs_is_file(p))
	{
		printf("is file\n");
		printf("file size : %d bytes\n", cfs_file_size(p));
		printf("file name : %s\n", cfs_file_name(p));
		printf("file extension : %s\n", cfs_extension(p));
		printf("parent path : %s\n", cfs_to_str(cfs_parent_path(p)));

		printf("cfs to str : %s\n", cfs_to_str(p));
		printf("cfs to str Win : %s\n", cfs_to_str_Win(p));

		char* win_str = cfs_to_str_Win(p);
		cfs_normalize_slashes(win_str);
		printf("cfs to str Win normalized : %s\n", win_str);
	}
	if(cfs_is_dir(p))
	{
		printf("is dir\n");
	}

	return 0;
}