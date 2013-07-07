/*-------------------------------------------------------------------------
 *
 * nbtoffset.c
 *	  Offset functions for btree access method.
 *
 * Portions Copyright (c) 1996-2013, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  src/backend/access/nbtree/nbtoffset.c
 *
 * NOTES
 *
 *	These functions are stored in pg_amproc.  For each operator class
 *	defined on btrees, they compute the positive or negative offset 
 *  between two values. 
 *
 *	NOTE: these routines must not leak memory, since memory allocated
 *	during an index access won't be recovered till end of query.  This
 *	primarily affects comparison routines for toastable datatypes;
 *	they have to be careful to free any detoasted copy of an input datum.
 *-------------------------------------------------------------------------
 */
#include "postgres.h"

#include "utils/builtins.h"

Datum
btint4posoffset(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	int32		arg2 = PG_GETARG_INT32(1);
	int32		result;

	result = arg1 + arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	// if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
	// 	ereport(ERROR,
	// 			(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
	// 			 errmsg("integer out of range")));

	// elog(NOTICE, "btint4posoffset result: %i from arg1: %i, arg2: %i", result, arg1, arg2);
	PG_RETURN_INT32(result);
}

Datum
btint4negoffset(PG_FUNCTION_ARGS)
{
	int32		arg1 = PG_GETARG_INT32(0);
	int32		arg2 = PG_GETARG_INT32(1);
	int32		result;

	result = arg1 - arg2;

	/*
	 * Overflow check.	If the inputs are of different signs then their sum
	 * cannot overflow.  If the inputs are of the same sign, their sum had
	 * better be that sign too.
	 */
	// if (SAMESIGN(arg1, arg2) && !SAMESIGN(result, arg1))
	// 	ereport(ERROR,
	// 			(errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
	// 			 errmsg("integer out of range")));

	// elog(NOTICE, "btint4posoffset result: %i from arg1: %i, arg2: %i", result, arg1, arg2);
	PG_RETURN_INT32(result);
}