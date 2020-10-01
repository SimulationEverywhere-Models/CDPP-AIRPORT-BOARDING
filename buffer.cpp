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

/** include files **/
#include "buffer.h"
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Buffer
* Description:
********************************************************************/
Buffer::Buffer( const string &name )
: Atomic( name )
, bufferIn( addInputPort( "bufferIn" ) )
, notifyDone( addInputPort( "notifyDone" ) )
, bufferOut( addOutputPort( "bufferOut" ) )
, bufferTime( 0, 0, 5, 0 )
{

}

/*******************************************************************
* Function Name: initFunction
* Description:
* Precondition:
********************************************************************/
Model &Buffer::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Buffer::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == bufferIn  && this->state() == passive)
	{	totalPassengerNum = static_cast < int > ( msg.value());
		if (totalPassengerNum > 0)
		{	passengerNum = 1;
			done = false;
			sendPassenger = true;
			holdIn(active, bufferTime );
		}
	}
	if( msg.port() == notifyDone )
	{

			done = true;
			sendPassenger = false;
			holdIn(active, Time::Zero) ;


	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &Buffer::internalFunction( const InternalMessage & )
{	if (done)
	{	if (passengerNum < totalPassengerNum)
		{	passengerNum ++;
			done = false;
		    sendPassenger = true;
			holdIn( active, bufferTime );

		}
		else
			passivate();
	}
		else
			passivate();

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &Buffer::outputFunction( const InternalMessage &msg )
{	if (sendPassenger)
	{	sendOutput( msg.time(), bufferOut, passengerNum ) ;

	}
	return *this ;
}
