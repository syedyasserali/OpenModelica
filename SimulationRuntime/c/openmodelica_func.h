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

/* File: modelica.h
 * Description: This is the C header file for the C code generated from
 * Modelica. It includes e.g. the C object representation of the builtin types
 * and arrays, etc.
 */

#ifndef OPENMODELICAFUNC_H_
#define OPENMODELICAFUNC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "simulation_data.h"

#include "memory_pool.h"
#include "index_spec.h"
#include "boolean_array.h"
#include "integer_array.h"
#include "real_array.h"
#include "string_array.h"
#include "modelica_string.h"
#include "division.h"
#include "utility.h"

struct OpenModelicaGeneratedFunctionCallbacks {
/* Function for calling external object constructors */
void (*callExternalObjectConstructors)(DATA *data);
/* Function for calling external object deconstructors */
void (*callExternalObjectDestructors)(DATA *_data);

/*! \fn initialNonLinearSystem
 *
 *  This function initialize nonlinear system structure.
 *
 *  \param [ref] [data]
 */
void (*initialNonLinearSystem)(NONLINEAR_SYSTEM_DATA *data);

/*! \fn initialLinearSystem
 *
 *  This function initialize nonlinear system structure.
 *
 *  \param [ref] [data]
 */
void (*initialLinearSystem)(LINEAR_SYSTEM_DATA *data);

/*! \fn initialNonLinearSystem
 *
 *  This function initialize nonlinear system structure.
 *
 *  \param [ref] [data]
 */
void (*initialMixedSystem)(MIXED_SYSTEM_DATA *data);

/*! \fn initialNonLinearSystem
 *
 *  This function initialize state set structure.
 *
 *  \param [ref] [data]
 */
void (*initializeStateSets)(STATE_SET_DATA* statesetData, DATA *data);

/* functionODE contains those equations that are needed
 * to calculate the dynamic part of the system */
int (*functionODE)(DATA *data);

/* functionAlgebraics contains all continuous equations that
 * are not part of the dynamic part of the system */
int (*functionAlgebraics)(DATA *data);

/* function for calculating all equation sorting order
   uses in EventHandle  */
int (*functionDAE)(DATA *data);

/* functions for input and output */
int (*input_function)(DATA*);
int (*output_function)(DATA*);

/* function for storing value histories of delayed expressions
 * called from functionDAE_output()
 */
int (*function_storeDelayed)(DATA *data);

/* function for calculating states on explicit ODE form */
/*used in functionDAE_res function*/
int (*functionODE_inline)(DATA *data, double stepsize);

/*! \fn updateBoundStartValues
 *
 *  This function updates all bound start-values. This are all start-values
 *  which are not constant.
 *  obsolete: initial_function
 *
 *  \param [ref] [data]
 */
int (*updateBoundStartValues)(DATA *data);

/*! \var initialResidualDescription
 *
 * This variable contains a description string for each initial residual.
 */
const char *(*initialResidualDescription)(int i);

/*! \fn initial_residual
 *
 * function for calculate residual values for the initial equations and initial algorithms
 *
 *  \param [in]  [data]
 *  \param [ref] [initialResiduals]
 */
int (*initial_residual)(DATA *data, double* initialResiduals);

/*! \var useSymbolicInitialization
 *
 * is 1 if a system to solve the initial problem symbolically is generated, otherwise 0
 */
const int useSymbolicInitialization;

/*! \var useHomotopy
 *
 * is 1 if homotopy(...) is used during initialization, otherwise 0
 */
const int useHomotopy;

/*! \fn functionInitialEquations
 *
 * function for calculate initial values from the initial equations and initial algorithms
 *
 *  \param [ref] [data]
 */
int (*functionInitialEquations)(DATA *data);

/*! \fn updateBoundParameters
 *
 *  This function calculates bound parameters that depend on other parameters,
 *  e.g. parameter Real n=1/m;
 *  obsolete: bound_parameters
 *
 *  \param [ref] [data]
 */
int (*updateBoundParameters)(DATA *data);

/* function for checking for asserts and terminate */
int (*checkForAsserts)(DATA *data);

/*! \fn function_ZeroCrossings
 *
 *  This function evaluates if a sign change occurs at the cuurect state
 *
 *  \param [ref] [data]
 *  \param [ref] [gout]
 *  \param [ref] [t]
 */
int (*function_ZeroCrossings)(DATA *data, double* gout, double* t);

/*! \fn function_updateRelations
 *
 *  This function evaluates current continuous relations.
 *
 *  \param [ref] [data]
 *  \param [in]  [evalZeroCross] flag for evaluating Relation with hysteresis
 *                              function or without
 */
int (*function_updateRelations)(DATA *data, int evalZeroCross);

/*! \fn checkForDiscreteChanges
 *
 *  This function checks if any discrete variable changed
 *
 *  \param [ref] [data]
 */
int (*checkForDiscreteChanges)(DATA *data);

/*! \var zeroCrossingDescription
 *
 * This variable contains a description string for zero crossing condition.
 */
const char *(*zeroCrossingDescription)(int i);

/*! \var relationDescription
 *
 * This variable contains a description string for continuous relations.
 */
const char *(*relationDescription)(int i);

/*! \fn function_initSample
 *
 *  This function initialize the sample-info struct.
 *
 *  \param [ref] [data]
 */
void (*function_initSample)(DATA *data);

/* function for calculation Jacobian */
/*#ifdef D_OMC_JACOBIAN*/
const int INDEX_JAC_G;
const int INDEX_JAC_A;
const int INDEX_JAC_B;
const int INDEX_JAC_C;
const int INDEX_JAC_D;

/*
 * These functions initialize specific jacobians.
 * Return-value 0: jac is present
 * Return-value 1: jac is not present
 */
int (*initialAnalyticJacobianG)(void* data);
int (*initialAnalyticJacobianA)(void* data);
int (*initialAnalyticJacobianB)(void* data);
int (*initialAnalyticJacobianC)(void* data);
int (*initialAnalyticJacobianD)(void* data);

/*
 * These functions calculate specific jacobian column.
 */
int (*functionJacG_column)(void* data);
int (*functionJacA_column)(void* data);
int (*functionJacB_column)(void* data);
int (*functionJacC_column)(void* data);
int (*functionJacD_column)(void* data);

/*#endif*/

const char *(*linear_model_frame)(void); /* printf format-string with holes for 6 strings */
};

#ifdef __cplusplus
}
#endif

#endif
