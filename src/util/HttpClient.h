//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <cbpro++/Auth.h>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/asio/buffers_iterator.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <openssl/hmac.h>

#include "Base64.h"

#ifndef CBPRO_HTTPCLIENT_H
#define CBPRO_HTTPCLIENT_H

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>

namespace pt = boost::property_tree;

class HttpClient {
public:
    HttpClient();

    ~HttpClient();

    enum class RequestVerb {
        GET, POST, PUT
    }; // scoped enum

    pt::ptree makeRequest(const std::string &target);
    pt::ptree makeRequest(const std::string &target, const std::string &body, Auth &, HttpClient::RequestVerb);

private:
    std::string createSignature(const std::string &target, const std::string &body, Auth &, HttpClient::RequestVerb);



};

#endif //CBPRO_HTTPCLIENT_H