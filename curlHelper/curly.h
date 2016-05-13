//
// Created by RayChen on 16/5/12.
//

#ifndef curly_h
#define curly_h

#include <string>
#include <vector>
#include <curl/curl.h>

class Curly{
private:
    std::string        mContent;
    std::string        mType;
    std::vector<std::string>        mHeaders;
    unsigned int       mHttpStatus;
    CURL*              pCurlHandle;
    static size_t      HttpContent(void* ptr, size_t size,
                                   size_t nmemb, void* stream);
    static size_t      HttpHeader(void* ptr, size_t size,
                                  size_t nmemb, void* stream);

public:
    Curly():pCurlHandle(curl_easy_init()){};  // constructor
    ~Curly(){};
    CURLcode    Fetch (std::string);

    inline std::string   Content()    const { return mContent; }
    inline std::string   Type()       const { return mType; }
    inline unsigned int  HttpStatus() const { return mHttpStatus; }
    inline std::vector<std::string>   Headers()    const { return mHeaders; }
};

#endif
