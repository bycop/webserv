#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <iostream>
# include <string>

class Location {
public:
	Location() {};

	~Location() {};

	void print() {
		std::cout << "autoindex: " << this->autoindex << std::endl;
		std::cout << "index: " << this->index << std::endl;
		std::cout << "root: " << this->root << std::endl;
		std::cout << "default_pages: " << this->allow_methods << std::endl;
	};

	bool autoindex;
	std::string index;
	std::string root;
	std::string allow_methods;
};

#endif
