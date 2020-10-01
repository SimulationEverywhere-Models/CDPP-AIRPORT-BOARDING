#ifndef __PROC_H
#define __PROC_H


#include "atomic.h"     // class Atomic

class Proc : public Atomic
{
public:
	Proc( const string &name = "Proc" );					//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &procIn;
	//const Port &notifyDone;
	Port &procOut;
	Port &procFeedback;
	Time procTime;
	int tempNum;
	int checkNum;
};

// ** inline ** //

inline string Proc::className() const
{
	return "Proc" ;
}

#endif   //__PROCESSOR_H
