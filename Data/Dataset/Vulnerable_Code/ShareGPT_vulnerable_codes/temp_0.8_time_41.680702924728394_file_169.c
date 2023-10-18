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

    // Call the search_dir function to start searching
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

    // Check if opening directory was successful
    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return;
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path of the entry
        char full_path[256];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get the information of the entry
        if (stat(full_path, &file_stat) < 0)
        {
            printf("Error getting file stat for %s.\n", full_path);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively call search_dir for subdirectories
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