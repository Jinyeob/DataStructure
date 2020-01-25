/* hash from libc
* see "man hsearch“ */

#include <stdio.h>
#include <search.h>
char *data[] = { "alpha", "bravo", "charlie", "delta",
"echo", "foxtrot", "golf", "hotel", "india",
"juliet", "kilo", "lima", "mike", "november",
"oscar", "papa", "quebec", "romeo", "sierra",
"tango", "uniform", "victor", "whisky", "x-ray",
"yankee", "zulu"
};
int main()
{
	ENTRY e, *ep;
	int i;

	/* start with small table, and let it grow */
	hcreate(28);
	for (i  = 0; i < 24; i++) {
		e.key  = data[i];