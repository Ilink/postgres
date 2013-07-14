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

// re-routes to another function
// useful because most of these functions alias to others
#define CALL_OTHER(fnOid) \
 		FmgrInfo finfo; \
 		fmgr_info(fnOid, &finfo); \
 		Datum result = FunctionCall2(&finfo, \
 						fcinfo->arg[0], fcinfo->arg[1]); \
 		PG_RETURN_INT32(result);

Datum
btint2posoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(176);
}

Datum
btint4posoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(177);
}

Datum
btint8posoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(463);
}

Datum
btint2negoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(180);
}

Datum
btint4negoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(181);
}

Datum
btint8negoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(464);
}

Datum
btfloat4posoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(204);
}

Datum
btfloat8posoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(218);
}

Datum
btfloat4negoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(205);
}

Datum
btfloat8negoffset(PG_FUNCTION_ARGS)
{
	CALL_OTHER(219);
}