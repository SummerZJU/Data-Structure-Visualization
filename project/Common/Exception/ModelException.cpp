#include "ModelException.h"
#include <iostream>


ModelException::ModelException(const std::string& str):
	str(str)
{

}

const char *ModelException::what() const noexcept
{
	//std::cerr << "Model Exception: " << str << std::endl;
    return ("Model Exception: " + str).c_str();
}
