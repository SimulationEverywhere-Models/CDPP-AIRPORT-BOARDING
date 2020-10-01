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

#include "luggage.h"
#include "message.h"
#include "mainsimu.h"


/** public functions **/

/*************************************************************************
* Function Name: Luggage
* Description:	define in, out ports and the process time of custom check
**************************************************************************/
Luggage::Luggage( const string &name )
: Atomic( name )
, luggageIn( addInputPort( "luggageIn" ) )
, luggageOut( addOutputPort( "luggageOut" ) )
, overWeightOut( addOutputPort( "overWeightOut" ) )
, luggageTime( 0, 0, 9, 0 )
{

}

/*******************************************************************
* Function Name: initFunction
* Description: define the initial state
* Precondition: the model should be in the passive mode
********************************************************************/
Model &Luggage::initFunction()
{
	this-> passivate();

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Luggage::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == luggageIn && this->state() == passive)
	{
		luggageWeight = static_cast < int >( msg.value() );
		checkNum = luggageWeight & 31 ;
		if( checkNum > 23 )
		{
			overWeight = true;
			holdIn ( active, luggageTime );
		}
		else{

			overWeight = false;
			holdIn( active, luggageTime );

		}
	}

	return *this;
}


/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Luggage::internalFunction( const InternalMessage & )
{

	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Luggage::outputFunction( const InternalMessage &msg )
{	if ( overWeight )
	{	sendOutput( msg.time(), overWeightOut, luggageWeight ) ;

	}
	else
		sendOutput ( msg.time(), luggageOut, luggageWeight );
	return *this ;

}
