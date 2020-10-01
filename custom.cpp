/*******************************************************************
*
*  DESCRIPTION: Atomic Model Buffer
*
*  AUTHOR: Pei Jin
*
*  EMAIL: pjin049@uottawa.ca
*
*  DATE: 14/10/2012
*
*******************************************************************/

#include "custom.h"
#include "message.h"
#include "mainsimu.h"

/** public functions **/

/*************************************************************************
* Function Name: Custom
* Description:	define in, out ports and the process time of custom check
**************************************************************************/
Custom::Custom( const string &name )
: Atomic( name )
, customIn( addInputPort( "customIn" ) )
, customOut( addOutputPort( "customOut" ) )
, customFailOut( addOutputPort( "customFailOut" ) )
, customTime( 0, 0, 15, 0 )
{

}

/*******************************************************************
* Function Name: initFunction
* Description: define the initial state
* Precondition: the model should be in the passive mode
********************************************************************/
Model &Custom::initFunction()
{
	this-> passivate();

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Custom::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == customIn && this->state() == passive)
	{
		interPassengerNum = static_cast < int >( msg.value() );
		checkNum = interPassengerNum & 15;
		holdIn (active, customTime);

	}

	return *this;
}


/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Custom::internalFunction( const InternalMessage & )
{

	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Custom::outputFunction( const InternalMessage &msg )
{	if (checkNum == 15)
	{
		if ((double)rand() / (double) RAND_MAX  > 0.90)
			{
				sendOutput( msg.time(), customOut, interPassengerNum ) ;
			}
		else{
			sendOutput( msg.time(), customFailOut, interPassengerNum ) ;
		}
	}
	else
		sendOutput ( msg.time(), customOut, interPassengerNum );
	return *this ;

}
