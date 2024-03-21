#ifndef MD5_HPP_
#define MD5_HPP__

#include <cstdint>
#include <cstdlib>
#include <string>

namespace MD5 {
	void md5_init();
	std::string hash(const std::string&);
	void hash(const std::string*, std::string*);
};

#endif
