/**

DISCLAIMER OF WARRANTY

The Software is provided "AS IS" and "WITH ALL FAULTS," 
without warranty of any kind, including without limitation the warranties 
of merchantability, fitness for a particular purpose and non-infringement. 
KUKA makes no warranty that the Software is free of defects or is suitable 
for any particular purpose. In no event shall KUKA be responsible for loss 
or damages arising from the installation or use of the Software, 
including but not limited to any indirect, punitive, special, incidental 
or consequential damages of any character including, without limitation, 
damages for loss of goodwill, work stoppage, computer failure or malfunction, 
or any and all other commercial damages or losses. 
The entire risk to the quality and performance of the Software is not borne by KUKA. 
Should the Software prove defective, KUKA is not liable for the entire cost 
of any service and repair.


COPYRIGHT

All Rights Reserved
Copyright (C)  2014-2016 
KUKA Roboter GmbH
Augsburg, Germany

This material is the exclusive property of KUKA Roboter GmbH and must be returned 
to KUKA Roboter GmbH immediately upon request.  
This material and the information illustrated or contained herein may not be used, 
reproduced, stored in a retrieval system, or transmitted in whole 
or in part in any way - electronic, mechanical, photocopying, recording, 
or otherwise, without the prior written consent of KUKA Roboter GmbH.  






\file
\version {1.10}
*/
#include "friTransformationContainer.h"
#include "pb_frimessages_callbacks.h"

using namespace KUKA::FRI;

//******************************************************************************
TransformationContainer::TransformationContainer():_monMsg(NULL),_cmdMsg(NULL),
 MATRIX_ID_LENGTH(0)
{
  _trafoIDs.reserve(5);
}

//******************************************************************************
void TransformationContainer::linkData()
{
	if(_monMsg)
	{
		tRepeatedTransformationArguments *arguments = (tRepeatedTransformationArguments*)_monMsg->requestedTransformations.arg;
		Transformation* transformations = &arguments->value[0];
  
		_trafoIDs.push_back(transformations->name);
	}
	
	if(_cmdMsg)
	{
	   MATRIX_ID_LENGTH = sizeof(_cmdMsg->commandData.requestedTransformation.name);
	}
}
//******************************************************************************
void TransformationContainer::setTransformation(const char* transformationID, 
      const double transformationMatrix[3][4], unsigned int timeSec, unsigned int timeNanoSec)
{
	if(_cmdMsg)
	{
	   _cmdMsg->has_commandData = true;
	   _cmdMsg->commandData.has_requestedTransformation= true;

	   Transformation& dest = _cmdMsg->commandData.requestedTransformation;
	   size_t lengthTrafoID = strlen(transformationID);
	   // crop to max string size - final \0
	   size_t numOfBytesToCopy = (lengthTrafoID < MATRIX_ID_LENGTH)? lengthTrafoID : MATRIX_ID_LENGTH-1;
	   memset(dest.name, 0, MATRIX_ID_LENGTH);
	   memcpy(dest.name, transformationID, numOfBytesToCopy);
	   
	   memcpy(dest.matrix, transformationMatrix, NUM_MATRIX_ELEMENTS * sizeof(double));
	   dest.matrix_count = NUM_MATRIX_ELEMENTS;
	   dest.has_timestamp = true;
	   dest.timestamp.sec = timeSec;
	   dest.timestamp.nanosec = timeNanoSec;
	}
}
