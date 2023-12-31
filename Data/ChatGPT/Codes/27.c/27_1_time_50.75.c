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

    // Remove trailing newline character
    path[strcspn(path, "\n")] = '\0';

    // Call the search_dir function to search the directory
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    // Open the directory
    dir = opendir(path);

    // Check if directory was opened successfully
    if (dir == NULL)
    {
        printf("Error opening directory.\n");
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the absolute path of the entry
        char abs_path[100];
        snprintf(abs_path, sizeof(abs_path), "%s/%s", path, entry->d_name);

        // Retrieve file information
        if (stat(abs_path, &file_stat) == -1)
            continue;

        // Check if the entry is a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively call search_dir for subdirectories
            search_dir(abs_path);
        }
        else
        {
            // Process the file (e.g., print its name)
            printf("%s\n", abs_path);
        }
    }

    // Close the directory
    closedir(dir);
}