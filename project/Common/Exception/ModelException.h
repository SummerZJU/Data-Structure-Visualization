#ifndef MODELEXCEPTION_H_
#define MODELEXCEPTION_H_

#include <exception>
#include <string>

class ModelException : public std::exception {	
	std::string str;
public:	
	ModelException(const std::string& str);
    virtual const char *what() const noexcept override;
};

#endif
