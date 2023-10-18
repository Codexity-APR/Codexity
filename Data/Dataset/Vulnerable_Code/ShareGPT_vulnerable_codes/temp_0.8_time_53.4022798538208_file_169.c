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

    // Call search_dir function to start searching
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char abs_path[1000];

    // Open the directory
    dir = opendir(path);

    if (dir == NULL)
    {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create absolute path for the entry
        snprintf(abs_path, sizeof(abs_path), "%s/%s", path, entry->d_name);

        // Get file/directory information
        if (stat(abs_path, &file_stat) == -1)
        {
            printf("Unable to get file/directory information for: %s\n", abs_path);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively search the subdirectory
            search_dir(abs_path);
        }
        else
        {
            // Process the file
            // Add your file processing logic here
            printf("Found file: %s\n", abs_path);
        }
    }

    // Close the directory
    closedir(dir);
}