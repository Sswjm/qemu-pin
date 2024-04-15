#include "qemu/qemu-plugin.h"
#include "pin-types.h"
#include "args.h"
#include "pin-ds.h"


/*INS:Instruction Object
* Including three kinds of API:
* 
* Instrumentation API
* Inspection API for LA64
* Generic modification API
* 
*/

/*Ins Instrumentation API*/
// PIN_CALLBACK INS_AddInstrumentFunction(INS_INSTRUMENT_CALLBACK fun, VOID *val)

VOID INS_InsertPredicatedCall(INS ins, IPOINT ipoint);
VOID INS_InsertCall(INS ins, IPOINT action, AFUNPTR funptr, ...);
VOID InsertIfCall(INS ins, IPOINT action, AFUNPTR funptr, ...);
VOID INS_InsertThenCall (INS ins, IPOINT action, AFUNPTR funptr, ...);
VOID INS_InsertIfPredicatedCall (INS ins, IPOINT action, AFUNPTR funptr, ...);
VOID INS_InsertThenPredicatedCall (INS ins, IPOINT action, AFUNPTR funptr, ...);
// VOID INS_InsertFillBuffer (INS ins, IPOINT action, BUFFER_ID id,...);
// VOID INS_InsertFillBufferPredicated (INS ins, IPOINT action, BUFFER_ID id,...);
// VOID INS_InsertFillBufferThen (INS ins, IPOINT action, BUFFER_ID id,...);

/*Ins Inspection API*/
BOOL INS_HasRealRep(INS ins);
BOOL INS_IsStandardMemop(INS ins);
BOOL INS_IsCacheLineFlush(INS ins);
INT32 INS_Category(const INS ins);