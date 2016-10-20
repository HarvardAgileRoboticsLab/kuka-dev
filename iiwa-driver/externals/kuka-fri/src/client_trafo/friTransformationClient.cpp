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
#include "friTransformationClient.h"
#include "friClientData.h"
#include "friTransformationContainer.h"

using namespace KUKA::FRI;

//******************************************************************************
TransformationClient::TransformationClient()
{
	_data = new TransformationContainer();
};
      
//******************************************************************************
TransformationClient::~TransformationClient()
{
	delete _data;
};

//******************************************************************************
const std::vector<const char*>* TransformationClient::getRequestedTransformationIDs() const
{
   return _data->getRequestedTransformationIDs();
}

//******************************************************************************
const unsigned int TransformationClient::getTimestampSec() const 
{
   return _data->getTimestampSec();
}

//******************************************************************************
const unsigned int TransformationClient::getTimestampNanoSec() const
{
   return _data->getTimestampNanoSec();
}

//******************************************************************************
void TransformationClient::setTransformation(const char* transformationID, 
      double transformationMatrix[3][4], unsigned int timeSec, unsigned int timeNanoSec)
{
   _data->setTransformation(transformationID, transformationMatrix, timeSec, timeNanoSec);
}

//******************************************************************************
void TransformationClient::linkData(ClientData* clientData)
{
   _data->_monMsg = &clientData->monitoringMsg;
   _data->_cmdMsg = &clientData->commandMsg;
   _data->linkData();
}

//******************************************************************************
ClientData* TransformationClient::createData()
{
   ClientData* clientData = new ClientData(0); // used, when no robot client available-> numDOFs = 0
   
   // set specific message IDs
   clientData->expectedMonitorMsgID = _data->TRAFOMONITORMESSAGEID;
   clientData->commandMsg.header.messageIdentifier = _data->TRAFOCOMMANDMESSAGEID;
   
   linkData(clientData);
   
   return clientData;
}
