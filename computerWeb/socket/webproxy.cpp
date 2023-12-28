#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "wget.hpp"
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;


std::string get_file_content(std::string path) {
    if(path[0]=='/')
        path = path.substr(1);
    std::ifstream file(path);
    if (!file) {
        return "<html><body><h1>HTTP-wireshark-file1.html</h1></body></html>";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
int main()
{
    try
    {
        auto const address = net::ip::make_address("0.0.0.0");
        auto const port = static_cast<unsigned short>(std::atoi("8080"));

        net::io_context ioc{1};

        tcp::acceptor acceptor{ioc, {address, port}};
        for(;;)
        {
            tcp::socket socket{ioc};

            acceptor.accept(socket);

            beast::flat_buffer buffer;

            http::request<http::dynamic_body> req;
            beast::error_code ec;
            http::read(socket, buffer, req, ec);
            if(ec == http::error::end_of_stream)
                break;
            if(ec)
                throw beast::system_error{ec};

            http::response<http::string_body> res{http::status::ok, req.version()};
            res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
            res.set(http::field::content_type, "text/html");
            std::string url = req.target();
            if (url[1]=='?')
            {
                std::string url2 = url.substr(2);
                // std::cout << url2 << "\n";
                res.body() = get_file_content(wget(url2));
            }
            else{
                // std::cout << url << "\n";
                res.body() = get_file_content(req.target());
            }
            http::write(socket, res);
        }
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}