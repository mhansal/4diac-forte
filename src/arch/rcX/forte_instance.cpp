/*******************************************************************************
 * Copyright (c) 2017-2018 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *  Jose Cabral - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "forte_instance.h"

#include "fortenew.h"
#include "forte_architecture.h"
#include "forte_printer.h"
#include <stdio.h>
#include <string>
#include "device.h"

#include "../utils/mainparam_utils.h"

unsigned int forte_default_port = 61499;

/*!\brief Check if the correct endianess has been configured.
 *
 * If the right endianess is not set this function will end FORTE.
 */
bool checkEndianess();

void forteGlobalInitialize(){
  CForteArchitecture::initialize();
}

void forteGlobalDeinitialize(){
  CForteArchitecture::deinitialize();
}

int forteStartInstance(unsigned int pa_port, TForteInstance* paResultDevice){

  if (65535 < pa_port){
    return FORTE_WRONG_PARAMETERS;
  }

  if (0 == pa_port){
    pa_port = forte_default_port;
  }

  char progName[] = "forte";
  char flag[] = "-c";
  char address[17] = "localhost:";
  char port[6];
  forte_snprintf(port, 6, "%u", paPort);
  strcat(address, port);

  char* arguments[] = { progName, flag, address };
  return forteStartInstanceGeneric(3, arguments, paResultDevice);
}


int forteStartInstanceGeneric(int argc, char *arg[], TForteInstance* paResultDevice){

  if(!CForteArchitecture::isInitialized()){
    return FORTE_ARCHITECTURE_NOT_READY;
  }

  if(0 == pa_resultDevice){
    return FORTE_WRONG_PARAMETERS;
  }

  if (0 != *pa_resultDevice){
    return FORTE_DEVICE_ALREADY_STARTED;
  }

  if (!checkEndianess()){
    return FORTE_WRONG_ENDIANESS;
  }

  const char *pIpPort = parseCommandLineArguments(argc, arg);
  if((0 != strlen(pIpPort)) && (nullptr != strchr(pIpPort, ':'))){
    C4diacFORTEInstance *instance = new C4diacFORTEInstance();
    if(!instance->startupNewDevice(ipPort)) {
      delete instance;
      return FORTE_COULD_NOT_CREATE_DEVICE;
    }
    *paResultDevice = instance;
    DEVLOG_INFO("FORTE is up and running\n");
  }
  else{ //! If needed call listHelp() to list the help for FORTE
    return FORTE_WRONG_PARAMETERS;
  }

  return FORTE_OK;
}

void forteStopInstance(int, TForteInstance paInstance){
  if(!CForteArchitecture::isInitialized()|| paInstance != nullptr){
    return;
  }
  C4diacFORTEInstance *instance = static_cast<C4diacFORTEInstance*>(paInstance);
  instance->triggerDeviceShutdown();
  instance->awaitDeviceShutdown();
  delete instance;
  DEVLOG_INFO("FORTE finished\n");
}


bool checkEndianess(){
  int i = 1;
  char *p = (char *) &i;
  if(p[0] == 1){
    //we are on a little endian platform
#ifdef FORTE_BIG_ENDIAN
    DEVLOG_ERROR("Wrong endianess configured! You are on a little endian platform and have configured big endian!\n");
    return false;
#endif
  }
  else{
    //we are on a big endian platform
#ifdef FORTE_LITTLE_ENDIAN
    DEVLOG_ERROR("Wrong endianess configured! You are on a big endian platform and have configured little endian!\n");
    return false;
#endif
  }

  return true;
}
