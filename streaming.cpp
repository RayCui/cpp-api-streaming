/*
    This is a demo app in C++ for streaming feature using OANDA open api and libcurl
*/

#include <curl/curl.h>
#include <iostream>

int main()
{
    CURL *connection;
    CURLcode code;

    connection = curl_easy_init();
    if (connection)
    {
        // Please update the following parameters with proper value
        // [:domain]      : use either fxpractice.oanda.com or fxtrade.oanda.com
        // [:instruments] : feel free to subscribe more instruments (at most 10 instruments)
        // [:accountId]   : your account ID
        code = curl_easy_setopt(connection, CURLOPT_URL, "https://<domain>/v1/quote?instruments=EUR_USD&accountId=<your account ID>");

        if (code != CURLE_OK)
        {
            std::cout << "Failed to set URL" << std::endl;
        }

        struct curl_slist *headers = NULL;

        // Headers
        // [:access_token] : "Authorization: Bearer <your access token>"
        headers = curl_slist_append(headers, "Authorization: Bearer <your access token>");

        code = curl_easy_setopt(connection, CURLOPT_HTTPHEADER, headers);

        if (code != CURLE_OK)
        {
            std::cout << "Failed to set headers" << std::endl;
        }

        code = curl_easy_setopt(connection, CURLOPT_SSL_VERIFYPEER, 0);

        if (code != CURLE_OK)
        {
            std::cout << "Failed to disable 'verify the peer'" << std::endl;
        }

        code = curl_easy_perform(connection);

        if (code != CURLE_OK)
        {
            std::cout << "Failed to perform connection" << std::endl;
        }

        curl_easy_cleanup(connection);

        curl_slist_free_all(headers);
    }
    return 0;
}
