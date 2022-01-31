//
// Created by Quentin Robert de beauchamp on 14/01/2022.
//

#ifndef WEBSERV_SEND_PAGE_HPP
#define WEBSERV_SEND_PAGE_HPP
#include "Response.hpp"

int display_page(int new_socket, std::map<std::string, std::string> request, bool autoindex, Response &response);
std::string ft_openFile(std::string path, std::string status, std::string content_type, Response &response);
std::string ft_header(int length, std::string s, std::string content_type);

#endif //WEBSERV_SEND_PAGE_HPP
