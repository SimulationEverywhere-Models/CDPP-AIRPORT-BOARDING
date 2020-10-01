/*******************************************************************
*
*  DESCRIPTION: Atomic Model Buffer
*
*  AUTHOR: Pei Jin
*
*  EMAIL: pjin049@uottawa.ca
*
*  DATE: 12/10/2012
*
*******************************************************************/

#include "proc.h"
#include "message.h"
#include "mainsimu.h"

/** public functions **/

/*******************************************************************
* Function Name: Buffer
* Description:
********************************************************************/
Proc::Proc( const string &name )
: Atomic( name )
, procIn( addInputPort( "procIn" ) )
, procFeedback( addOutputPort( "procFeedback" ) )
, procOut( addOutputPort( "procOut" ) )
, procTime( 0, 0, 5, 0 )
{

}

/*******************************************************************
* Function Name: initFunction
* Description:
* Precondition:
********************************************************************/
Model &Proc::initFunction()
{
	this-> passivate();

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Proc::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == procIn && this->state() == passive)
	{
		tempNum = static_cast < int >( msg.value() );
		checkNum = tempNum & 1;
		holdIn (active, procTime);

	}

	return *this;
}


/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Proc::internalFunction( const InternalMessage & )
{

	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Proc::outputFunction( const InternalMessage &msg )
{	if (checkNum == 1)
	{	sendOutput( msg.time(), procOut, tempNum ) ;
		sendOutput ( msg.time(), procFeedback, tempNum );
	}
	else
		sendOutput ( msg.time(), procFeedback, tempNum );
	return *this ;

}
