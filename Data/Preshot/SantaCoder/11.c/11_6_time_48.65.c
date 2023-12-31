#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // create file pointer to save downloaded data
    fp = fopen("data.txt", "w");

    // initialize curl
    curl = curl_easy_init();

    // set URL
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");

    // set file to write to
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // perform the request
    res = curl_easy_perform(curl);

    // cleanup
    curl_easy_cleanup(curl);
    fclose(fp);

    return 0;
}