#include <string.h>
#include <unistd.h>

#include "postgres.h"
#include "fmgr.h"
#include "utils/memutils.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(walker);


static void
memory_context_walker (MemoryContext context, int level) {
	AssertArg(MemoryContextIsValid(context));
	char buf[10240];
	int count = 0;

	/* log our current context, along with our size */
	for (; count < 10240 && count < level; count++) {
		/* add the spaces for prettier printing */
		buf[count] = ' ';
	}
	buf[count] = '\0';

	/* log name and size */
	MemoryContextCounters totals = { 0 };
	context->methods->stats(context, NULL, NULL, &totals);

	elog(NOTICE, "%s%s[%s] (%ld / %ld)", buf, context->name ? context->name : "(null)", context->ident ? context->ident : "(null)", totals.totalspace, totals.freespace);

	/* interate through the children and print the contexts */
	for (MemoryContext child = context->firstchild; child != NULL; child = child->nextchild) {
		memory_context_walker(child, level + 1);
	}
}


Datum walker (PG_FUNCTION_ARGS) {
	memory_context_walker(TopMemoryContext, 0);
	PG_RETURN_VOID();
}
