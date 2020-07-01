/*  main.c  - main */

/* Basic Xinu app for quick start */

#include <xinu.h>


process example0(int nargs, char *args[])
{
	printf("\n  Starting %s process\n", proctab[currpid].prname);
	printf("  nargs = %d\n", nargs);
	printf("  args[0]: %d\n", args[0]);
	printf("  args[1]: %s\n", args[1]);
	printf("  %s process has completed.\n", proctab[currpid].prname);

	return OK;
}

process	main(void)
{
	printf("\nStarting %s process\n", proctab[currpid].prname);

	/* We create() a new process. Arguments:
	 *         process code: example0()
	 *         stack size: 128 bytes
	 *         priority: 50
	 * 	   name: "ex0"
	 *         arguments: 2
	 * 	   first argument: 3 (int)
	 * 	   second argument: "hello world"
	 */

	resume(create(example0, 128, 50, "ex_0", 2, 3, "hello world"));

	/* Wait for main to exit */

	receive();
	printf("\n%s process has completed.\n", proctab[currpid].prname);

	return OK;
}
