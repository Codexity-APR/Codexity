#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void search_dir(char *path);

int main()
{
    char path[100];

    // Prompt user for the drive path to search
    printf("Enter drive path to search: ");
    scanf("%s", path);

    // Call the search_dir function with the given path
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[100];

    // Open the directory
    dir = opendir(path);

    // Check if directory was opened successfully
    if (dir == NULL)
    {
        printf("Error opening directory\n");
        return;
    }

    // Loop through all entries in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // Construct the full path of the entry
        sprintf(full_path, "%s/%s", path, entry->d_name);

        // Get the file status
        if (stat(full_path, &file_stat) < 0)
        {
            printf("Error getting file status\n");
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively call search_dir with the subdirectory path
            search_dir(full_path);
        }
        else
        {
            // Print the file path
            printf("%s\n", full_path);
        }
    }

    // Close the directory
    closedir(dir);
}
