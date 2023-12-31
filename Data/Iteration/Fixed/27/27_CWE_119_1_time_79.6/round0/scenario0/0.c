List of vulnerabilities detected: 
 Error type: CWE-119 at line: 15. Error message: scanf() without field width limits can crash with huge input data.


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
    search_dir(path);
    return 0;
}
void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char filepath[256];
    // Open the directory
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return;
    }
    // Loop through all the files and directories in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        // Construct the filepath
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
        // Get the file information
        if (stat(filepath, &file_stat) == -1)
        {
            printf("Unable to get file information.\n");
            continue;
        }
        // Check if it's a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively call the search_dir function for subdirectories
            search_dir(filepath);
        }
        // Print the file path
        printf("%s\n", filepath);
    }
    // Close the directory
    closedir(dir);
}