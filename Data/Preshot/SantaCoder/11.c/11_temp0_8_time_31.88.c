#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen("example.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}