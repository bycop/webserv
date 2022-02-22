//
// Created by Codage on 25/01/2022.
//

#ifndef WEBSERV_HEADERRESPONSE_H
#define WEBSERV_HEADERRESPONSE_H
#include <iostream>
#include <map>
#include <string>
#include "Data.hpp"

using namespace std;

class Response {
private:
	string	status;
    string	contentType;
    string	contentLength;
    string	header;
    string	body;
	string	response;
	map<string, string>	types;
	void setMapType(void);
public:
    Response();
    ~Response();
    Response(Response const &cpy);
    Response &operator=(Response const &cpy);
	string	getStatus(void);
    string	getHeader();
	string	getBody();
	string	getResponse();
	void	setStatus(const string&);
	void	response_http(int new_socket);
	void	setContentType(string &path);
    void	fillHeader(string &path, map<string, string> & request_header, bool set_content_type);
	void	fillBody(string const& content);
	void	responseCGI(const string& cgi_content, map<string, string> & request_header, Server &server);
	string	findExtension(string &path);
	void	resetResponse();

};

#endif //WEBSERV_HEADERRESPOc NSE_H