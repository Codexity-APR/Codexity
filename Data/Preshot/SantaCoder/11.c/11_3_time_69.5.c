#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // initialize curl
    curl = curl_easy_init();
    if (curl) {
        // open file
        fp = fopen("example.txt", "wb");
        if (fp) {
            // set URL
            curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

            // write file to disk
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

            // perform the request
            res = curl_easy_perform(curl);

            // check for errors
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }

            // close file
            fclose(fp);
        } else {
            fprintf(stderr, "Failed to open file\n");
        }

        // cleanup curl
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }

    return 0;
}