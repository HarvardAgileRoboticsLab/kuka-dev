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
#ifndef _KUKA_FRI_TRANSFORMATION_CONTAINER_H
#define _KUKA_FRI_TRANSFORMATION_CONTAINER_H

#include <vector>
#include "friClientIf.h"
#include "FRIMessages.pb.h"
#include <cstring>

namespace KUKA
{
namespace FRI
{

/**
 * \brief Container class for the data being related to an FRI Transformation Client.
 */
class TransformationContainer
{
   friend class TransformationClient;

public:

   /**
    * \brief Create a new TransformationContainer.
    */
   TransformationContainer();

   /**
    * \brief Returns a vector of identifiers of requested transformation matrices.
    * 
    * @return vector with transformation identifier strings
    */
      const std::vector<const char*>* getRequestedTransformationIDs() const {return &_trafoIDs;};

   /**
    * \brief Get the timestamp of the current received FRI monitor message in Unix time. 
    * 
    * This method returns the seconds since 0:00, January 1st, 1970 (UTC).
    * Use getTimestampNanoSec() to increase your timestamp resolution when
    * seconds are insufficient. 
    * @return timestamp encoded as Unix time (seconds)
    */
      const unsigned int getTimestampSec() const { return _monMsg->monitorData.timestamp.sec;};

   /**
    * \brief Get the nanoseconds elapsed since the last second (in Unix time).
    * 
    * This method complements getTimestampSec() to get a high resolution 
    * timestamp. 
    * @return timestamp encoded as Unix time (nanoseconds part)
    */
      const unsigned int getTimestampNanoSec() const { return _monMsg->monitorData.timestamp.nanosec;};

   /**
    * \brief Set a new transformation matrix.
    * 
    * @param transformationID identification string
    * @param transformationMatrix numerical values of the matrix
    * @param timeSec timestamp encoded as Unix time (seconds)
    * @param timeNanoSec timestamp encoded as Unix time (nanoseconds part)
    */
   void setTransformation(const char* transformationID,
            const double transformationMatrix[3][4], unsigned int timeSec, unsigned int timeNanoSec);

protected:

   //! \brief linkData to UDP Message
   void linkData();
      static const int TRAFOMONITORMESSAGEID  = 0x245142;  //!< type identifier for the FRI monitoring message corresponding to a transformation provider 
      static const int TRAFOCOMMANDMESSAGEID = 0x34001;    //!< type identifier for the FRI command message corresponding to a transformation provider 

      FRIMonitoringMessage* _monMsg;                    //!< FRI monitoring message (protobuf struct)
      FRICommandMessage*    _cmdMsg;                    //!< FRI command message (protobuf struct)

private:
      const static int NUM_MATRIX_ELEMENTS = 12;      //!< number of elements of an transformation matrix
      size_t MATRIX_ID_LENGTH;                        //!< length of identifier field
      std::vector<const char*> _trafoIDs;             //!< list of requested transformation ids

};

}
}
#endif // _KUKA_FRI_TRANSFORMATION_CONTAINER_H
