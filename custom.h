#ifndef __CUSTOM_H
#define __CUSTOM_H


#include "atomic.h"     // class Atomic

class Custom : public Atomic
{
public:
	Custom ( const string &name = "Custom" );					//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &customIn;
	Port &customOut;
	Port &customFailOut;
	Time customTime;
	int  interPassengerNum;
	int  checkNum;
};

// ** inline ** //

inline string Custom::className() const
{
	return "Custom" ;
}

#endif   //__Custom_H
