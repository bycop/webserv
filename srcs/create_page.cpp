//
// Created by Quentin Robert de beauchamp on 1/18/22.
//

#include "webserv.hpp"

void create_indexing_page(DIR *dir, std::string path, Response &response, map<string, string> request_header){
	std::ostringstream mypage;
	std::string dir_p = ".";
	std::string content_type = "text/html";
	mypage << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<title>Index of " << path << "</title>\n</head>\n" << std::endl;
	mypage << "<body><h1>Index of " << path << "\n</h1><hr/><br>";
	struct dirent *ent;
	ent = readdir(dir);

	if (path[path.length() - 1] != '/')
		path.insert(path.length(), "/");
	while ((ent = readdir(dir)) != NULL) {
		std::string name = ent->d_name;
		if (opendir(const_cast<char *>(("." + path + name).c_str())) != NULL && name != "..") {
			mypage << "<a href=\"" << path << name << "\">" << ent->d_name << "/" << "</a><br>";
		}
		else
			mypage << "<a href=\"" << path << name << "\">" << ent->d_name << "</a><br>";
	}
	closedir (dir);
	mypage << "<br><hr/></body></html>\n";
	response.setStatus("200 OK");
    response.fillHeader(mypage.str(), path, request_header);
}

void 		create_error_page(std::string &path, Response &response, map<string, string> request_header) {
	std::ostringstream mypage;
	mypage << "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<title>Error " << response.getStatus() << "</title>\n</head>\n" << std::endl;
	mypage << "<body><h1>Error " << response.getStatus() << "\n</h1></body></html>";
	response.fillHeader(mypage.str(), path, request_header);
}
