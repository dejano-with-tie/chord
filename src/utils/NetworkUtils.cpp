//
// Created by dejan-osmanovic on 22.5.20..
//

#include <iostream>
#include "NetworkUtils.h"
#include <curl/curl.h>

size_t CurlWrite_CallbackFunc_StdString(void *contents, size_t size, size_t nmemb, std::string *s) {
  size_t newLength = size * nmemb;
  try {
    s->append((char *) contents, newLength);
  }
  catch (std::bad_alloc &e) {
    return 0;
  }
  return newLength;
}

std::string NetworkUtils::ip() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  CURL *handle = curl_easy_init();

  std::string body;
  if (handle) {
    curl_easy_setopt(handle, CURLOPT_URL, IP_API_URL);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &body);
    CURLcode response = curl_easy_perform(handle);
    if (response != CURLE_OK) {
      std::string error_message = "http request failed: ";
      std::string curl_error_message(curl_easy_strerror(response));
      throw std::runtime_error(error_message + curl_error_message);
    }
  }
  curl_global_cleanup();

  return body;
}
