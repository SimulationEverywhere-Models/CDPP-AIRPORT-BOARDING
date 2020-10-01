/*******************************************************************
*
*  DESCRIPTION: Atomic Model Security
*
*  AUTHOR: Pei Jin
*
*  EMAIL: pjin049@uottawa.ca
*
*  DATE: 12/10/2012
*
*******************************************************************/

/** include files **/
#include "security.h"      // class security
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Security
* Description:
********************************************************************/
Security::Security( const string &name )
: Atomic( name )
, securityIn( addInputPort( "securityIn" ) )
, securityOut( addOutputPort( "securityOut" ) )
, securityFailOut( addOutputPort( "securityFailOut" ) )
, securityTime( 0, 0, 10, 0 )
{

}

/*******************************************************************
* Function Name: initFunction
* Description: define the initial state
* Precondition: the model should be passive
********************************************************************/
Model &Security::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Security::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == securityIn  && this->state() == passive)
	{	checkSecurityNum = static_cast < int > ( msg.value());
		checkNum = checkSecurityNum & '?' ;
		if (checkNum != '1')
		{
			qualify = true;
			holdIn( active, securityTime );
		}
		else{
			qualify = false;
			holdIn( active, securityTime );
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Security::internalFunction( const InternalMessage & )
{
	passivate();

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Security::outputFunction( const InternalMessage &msg )
{	if (qualify)
	{	sendOutput( msg.time(), securityOut, checkSecurityNum ) ;

	}
	else
	{
		if ((double)rand() / (double) RAND_MAX  > 0.80)
		{
			sendOutput( msg.time(), securityOut, checkSecurityNum ) ;
		}
		else
			sendOutput ( msg.time(), securityFailOut, checkSecurityNum);

	}
	return *this ;
}


