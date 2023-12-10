#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    const char* edamam_app_id = "8289e8eb";
    const char* edamam_app_key = "2e36acaf5913fc7d2f2401776374ee85";
    const char* api_endpoint = "https://api.edamam.com/api/recipes/v2?type=public&q=chicken";

    // Construct the API endpoint with the application ID and key
    std::string api_url = api_endpoint + "&app_id=" + std::string(edamam_app_id) + "&app_key=" + std::string(edamam_app_key);

    // Initialize libcurl
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the API endpoint
        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());

        // Set the write callback function to handle the response
        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        // Perform the HTTP request
        CURLcode res = curl_easy_perform(curl);

        // Check if the request was successful
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Process the response (in this example, just printing the response)
            std::cout << "API Response:\n" << responseBuffer << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    return 0;
}
