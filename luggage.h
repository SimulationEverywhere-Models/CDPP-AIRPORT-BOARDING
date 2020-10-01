#ifndef __LUGGAGE_H
#define __LUGGAGE_H


#include "atomic.h"     // class Atomic

class Luggage : public Atomic
{
public:
	Luggage ( const string &name = "Luggage" );					//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &luggageIn;
	Port &luggageOut;
	Port &overWeightOut;
	Time luggageTime;
	int  luggageWeight;
	int  checkNum;
	bool overWeight;
};

// ** inline ** //

inline string Luggage::className() const
{
	return "Luggage" ;
}

#endif   //__Luggage_H
