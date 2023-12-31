#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // Open file for writing
    fp = fopen("output.txt","w");

    // Initialize CURL
    curl = curl_easy_init();
    
    if(curl) {
        // Set URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

        // Set file handler for output
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        // Cleanup
        curl_easy_cleanup(curl);

        // Close the file
        fclose(fp);
    }
    return 0;
}