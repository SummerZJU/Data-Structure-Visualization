#include "IntParameter.h"

IntParameter::IntParameter(int para):
	para(para)
{

}

IntParameter::~IntParameter()
{

}

int IntParameter::get() const
{
	return para;
}

void IntParameter::set(int para)
{
	this->para = para;
}

IntParameter::operator int() const
{
	return get();
}