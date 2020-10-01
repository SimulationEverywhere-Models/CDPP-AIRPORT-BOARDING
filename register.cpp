/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Pei Jin
*
*  EMAIL: pjin049@uottawa.ca
*
*  DATE: 14/10/2012
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "buffer.h"
#include "proc.h"
#include "custom.h"
#include "security.h"
#include "luggage.h"

void MainSimulator::registerNewAtomics()
{

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Buffer>(), "Buffer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Proc>(), "Proc" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Custom>(), "Custom" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Security>(), "Security" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Luggage>(),"Luggage");
}


