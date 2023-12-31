#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl) {
        // Open file for writing
        fp = fopen("output.txt", "wb");
        if (fp == NULL) {
            printf("File cannot be opened.\n");
            return 1;
        }

        // Set URL to download from
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/file.txt");
        // Set file to write to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Download failed: %s\n", curl_easy_strerror(res));
            fclose(fp); // Close the file before returning
            return 1;
        }

        // Clean up
        curl_easy_cleanup(curl);
        // Close the file
        fclose(fp);
    }

    return 0;
}