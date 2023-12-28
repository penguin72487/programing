#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string wget(std::string url)
{

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // std::cin >> url;
    // if (url[url.length() - 1] == '/') {
    //     url.pop_back();
    // }

    // 檢查 URL 是否符合 HTTP 網址的規定
    std::regex url_regex("(http|https)://([^/]+)/(.*)");
    if (!std::regex_match(url, url_regex)) {
        std::cerr << "Invalid URL format" << std::endl;
        return "/";
    }

    // 使用 "/" 來切割 URL，並將最後一段作為 output.html 的名稱
    std::istringstream iss(url);
    std::string segment;
    std::string filename;
    while (std::getline(iss, segment, '/')) {
        filename = segment;
    }
    filename += ".html";

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            std::cout << readBuffer << std::endl;

            std::ofstream outFile(filename);
            outFile << readBuffer;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return filename;
}
