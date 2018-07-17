#ifndef INTPARAMETER_H_
#define INTPARAMETER_H_

#include "Parameter.h"

class IntParameter : public Parameter {
	int para;
public:
	IntParameter(int para);
	virtual ~IntParameter();
	int get() const;
	void set(int para);
	operator int() const;
};

#endif