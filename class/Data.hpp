#ifndef DATA_HPP
# define DATA_HPP

# include "Server.hpp"

using namespace std;

class Data {
public:
	Data(): _isRunning(true) {};

	~Data() {};

	void print() {
		cout << endl;
		cout << "[BASE]" << endl;
		cout << "workers: " << _workers << endl;

		for (unsigned long i = 0; i < _servers.size(); i++) {
			cout << endl;
			cout << "[SERVER " << i << "]" << endl;
			_servers[i].print();
		}
	};

	bool mandatory() {
		if (_servers.empty()) {
			cerr << "\e[91m[ERROR]\e[0m Mandatory key is missing " << endl;
			return (false);
		}
		for (unsigned long i = 0; i < _servers.size(); i++)
			if (!_servers[i].mandatory(i)) {
				cerr << "\e[91m[ERROR]\e[0m Mandatory key is missing " << endl;
				return (false);
			}
		return (true);
	}

	vector<Server> &getServers() { return _servers; }

	int getWorkers() const { return _workers; }


	void setServers(const vector<Server> &servers) { _servers = servers; }

	void setWorkers(int workers) { _workers = workers; }

	bool IsRunning() const {
		return _isRunning;
	}

	void setIsRunning(bool isRunning) {
		_isRunning = isRunning;
	};

	bool checkFdAlreadyAccepted(int fd) {
		for (vector<int>::iterator it = socket_fd.begin(); it < socket_fd.end(); ++it) {
			if (*it == fd)
				return true;
		}
		return false;
	}

	void pushSocketFdAccepted(int fd) {
		for (vector<int>::iterator it = socket_fd.begin(); it < socket_fd.end(); ++it) {
			if (*it == fd) {
				cerr << "FD already accepted" << endl;
				return ;
			}
		}
		socket_fd.push_back(fd);
	}

	const vector<int> &getSocketFdAccepted() const {
		return socket_fd;
	}

	void setSocketFdAccepted(const vector<int> &socket_fd) {
		this->socket_fd = socket_fd;
	}

	void eraseSocketFd(int fd) {
		for (vector<int>::iterator it = socket_fd.begin(); it < socket_fd.end(); ++it) {
			if (*it == fd) {
				socket_fd.erase(it);
				return ;
			}
		}
	}

private:
	vector<int>	socket_fd;
	vector<Server> _servers;
	int _workers;
	bool _isRunning;
};

#endif