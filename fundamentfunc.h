#ifndef FUNDAMENTFUNC_H
#define FUNDAMENTFUNC_H

#include "foundation.h"

void WatchAssembly(TRec* assembly, unsigned number);
void EditAssembly(TRec* assembly, unsigned count);
void AddAssembly(TRec* assembly, unsigned* count);
void DelAssembly(TRec* assembly, unsigned* count);
void SortAssembly(TRec* assembly, unsigned count, int ML);
void SearchAssembly(TRec* assembly, unsigned count, const char* name);
void PriceProcAssembly(TRec* assembly, unsigned count);

#endif