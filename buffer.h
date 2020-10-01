#ifndef __BUFFER_H
#define __BUFFER_H


#include "atomic.h"     // class Atomic

class Buffer : public Atomic
{
public:
	Buffer( const string &name = "Buffer" );					//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &bufferIn;
	const Port &notifyDone;
	Port &bufferOut;
	Time bufferTime;
	int passengerNum;
	int totalPassengerNum;
	bool done;
	bool sendPassenger;

};

// ** inline ** //

inline string Buffer::className() const
{
	return "Buffer" ;
}

#endif   //__SENDER_H
