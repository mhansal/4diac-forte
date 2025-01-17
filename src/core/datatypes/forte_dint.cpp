/*******************************************************************************
 * Copyright (c) 2005 - 2013 Profactor GmbH, ACIN, fortiss GmbH
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Thomas Strasser, Ingomar Müller, Alois Zoitl, Ingo Hegny, Monika Wenger,
 *      - initial implementation and rework communication infrastructure
 *******************************************************************************/
#include "forte_dint.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "forte_dint_gen.cpp"
#endif

DEFINE_FIRMWARE_DATATYPE(DINT, g_nStringIdDINT)

template CIEC_DINT &CIEC_DINT::operator=<>(const CIEC_SINT &paValue);

template CIEC_DINT &CIEC_DINT::operator=<>(const CIEC_INT &paValue);

template CIEC_DINT &CIEC_DINT::operator=<>(const CIEC_USINT &paValue);

template CIEC_DINT &CIEC_DINT::operator=<>(const CIEC_UINT &paValue);
