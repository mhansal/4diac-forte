/*************************************************************************
 *** Copyright (c) 2024 HR Agrartechnik GmbH  
 *** This program and the accompanying materials are made available under the  
 *** terms of the Eclipse Public License 2.0 which is available at  
 *** http://www.eclipse.org/legal/epl-2.0.  
 ***  
 *** SPDX-License-Identifier: EPL-2.0  
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: E_TON
 *** Description: standard timer function block (on-delay timing)
 *** Version:
 ***     1.0: 2024-03-04/Franz Hoepfinger - HR Agrartechnik GmbH -
 *************************************************************************/

#include "E_TON_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_TON_fbt_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_E_TON, g_nStringIdE_TON)

const CStringDictionary::TStringId FORTE_E_TON::scmDataInputNames[] = {g_nStringIdIN, g_nStringIdPT};
const CStringDictionary::TStringId FORTE_E_TON::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdTIME};
const CStringDictionary::TStringId FORTE_E_TON::scmDataOutputNames[] = {g_nStringIdQ};
const CStringDictionary::TStringId FORTE_E_TON::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_E_TON::scmEIWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_E_TON::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_E_TON::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_E_TON::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_E_TON::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_E_TON::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_E_TON::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_E_TON::FORTE_E_TON(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CCompositeFB(paContainer, &scmFBInterfaceSpec, paInstanceNameId, scmFBNData),
    var_conn_Q(var_Q),
    conn_CNF(this, 0),
    conn_IN(nullptr),
    conn_PT(nullptr),
    conn_Q(this, 0, &var_conn_Q) {
};

void FORTE_E_TON::setInitialValues() {
    var_IN = 0_BOOL;
    var_PT = 0_TIME;
    var_Q = 0_BOOL;
}

const SCFB_FBInstanceData FORTE_E_TON::scmInternalFBs[] = {
  {g_nStringIdE_SWITCH, g_nStringIdE_SWITCH},
  {g_nStringIdE_DELAY, g_nStringIdE_DELAY},
  {g_nStringIdE_RS, g_nStringIdE_RS}
};


const SCFB_FBConnectionData FORTE_E_TON::scmEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEO1), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTART), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdEO0), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdSTOP), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdEO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_RS, g_nStringIdS), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_RS, g_nStringIdEO), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_E_TON::scmFannedOutEventConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_RS, g_nStringIdR), 2},
};

const SCFB_FBConnectionData FORTE_E_TON::scmDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdIN), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_SWITCH, g_nStringIdG), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_DELAY, g_nStringIdDT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdE_RS, g_nStringIdQ), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdQ), -1},
};

const SCFB_FBNData FORTE_E_TON::scmFBNData = {
  3, scmInternalFBs,
  5, scmEventConnections,
  1, scmFannedOutEventConnections,
  3, scmDataConnections,
  0, nullptr,
  0, nullptr,
  0, nullptr
};

void FORTE_E_TON::readInternal2InterfaceOutputData(const TEventID paEOID) {
  switch(paEOID) {
    case scmEventCNFID: {
      if(CDataConnection *conn = getIn2IfConUnchecked(0); conn) { conn->readData(var_Q); }
      break;
    }
    default:
      break;
  }
}
void FORTE_E_TON::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_IN, conn_IN);
      readData(1, var_PT, conn_PT);
      break;
    }
    default:
      break;
  }
}

void FORTE_E_TON::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Q, conn_Q);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_E_TON::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_IN;
    case 1: return &var_PT;
  }
  return nullptr;
}

CIEC_ANY *FORTE_E_TON::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Q;
  }
  return nullptr;
}

CEventConnection *FORTE_E_TON::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_E_TON::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_IN;
    case 1: return &conn_PT;
  }
  return nullptr;
}

CDataConnection *FORTE_E_TON::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Q;
  }
  return nullptr;
}

