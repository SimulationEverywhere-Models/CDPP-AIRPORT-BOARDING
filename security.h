#ifndef __SECURITY_H
#define __SECURITY_H

#include "atomic.h"

class Security : public Atomic

{
public :
	Security ( const string &name = "Security" );

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction ( const InternalMessage & );

private:
	const Port &securityIn;
	Port &securityOut;
	Port &securityFailOut;
	Time securityTime;
	int checkNum;
	int checkSecurityNum;
	bool qualify;

};

inline string Security::className() const
{
	return "Security";
}

#endif
