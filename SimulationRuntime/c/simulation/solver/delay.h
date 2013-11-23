/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Linköping University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3
 * AND THIS OSMC PUBLIC LICENSE (OSMC-PL).
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S
 * ACCEPTANCE OF THE OSMC PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköping University, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

/*! \file delay.h
 */

#ifndef _DELAY_H_
#define _DELAY_H_

#include "simulation_data.h"

typedef struct TIME_AND_VALUE
{
  double t; /* time; not named that due to macros */
  double value;
} TIME_AND_VALUE;

typedef struct EXPRESSION_DELAY_BUFFER
{
  long currentIndex;
  long maxExpressionBuffer;
  TIME_AND_VALUE *expressionDelayBuffer;
}EXPRESSION_DELAY_BUFFER;

#ifdef __cplusplus
  extern "C" {
#endif

  void initDelay(DATA* data, double startTime);
  double delayImpl(DATA* data, int exprNumber, double exprValue, double t, double delayTime, double maxDelay);
  void storeDelayedExpression(DATA* data, int exprNumber, double exprValue, double t, double delayTime, double delayMax);

#ifdef __cplusplus
  }
#endif

#endif
