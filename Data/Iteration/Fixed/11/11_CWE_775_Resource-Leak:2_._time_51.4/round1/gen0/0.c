#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // Open file for writing
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file for writing\n");
        return 1;
    }

    // Initialize curl
    curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize curl\n");
        fclose(fp); // Close the file before returning
        return 1;
    }

    // Set URL to download
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

    // Set file to write the response into
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Failed to perform request: %s\n", curl_easy_strerror(res));
        fclose(fp); // Close the file before returning
        curl_easy_cleanup(curl);
        return 1;
    }

    // Clean up curl and close the file
    curl_easy_cleanup(curl);
    fclose(fp);

    return 0;
}