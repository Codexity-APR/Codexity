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
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0';

    // Call the function to search the directory
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    char file_path[200];

    // Open the directory
    directory = opendir(path);
    if (directory == NULL)
    {
        printf("Error opening directory.\n");
        return;
    }

    // Read directory entries
    printf("Files in directory %s:\n", path);
    while ((entry = readdir(directory)) != NULL)
    {
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        // Get file status
        if (stat(file_path, &file_stat) < 0)
        {
            printf("Error getting file status.\n");
            continue;
        }

        // Check if it's a regular file
        if (S_ISREG(file_stat.st_mode))
        {
            printf("%s\n", entry->d_name);
        }
    }

    // Close the directory
    closedir(directory);
}