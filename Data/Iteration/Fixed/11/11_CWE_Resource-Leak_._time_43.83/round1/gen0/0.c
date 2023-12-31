#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen("output.txt", "wb");
        if (fp == NULL)
        {
            printf("Error opening the file.\n");
            return 1;
        }
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp); // Close the file before returning
            return 1;
        }
        curl_easy_cleanup(curl);
        fclose(fp); // Close the file
    }
    return 0;
}