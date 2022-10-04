#include <stdio.h>
#include <stdlib.h>

/*
 * This program reads in a series of integers and sorts them using a bubble 
 * sort.  It is written using goto and if() goto instead of sane looping
 * constructs.  
 *
 * Do not try this at home.
 *
 * I hope it is not a mystery why we don't use goto anymore.
 */

#define SIZE 100

main()
{
	int nums[SIZE];	// Numbers.
	int count;	// How many
	int limit;	// Pair scan limit.
	int tmp;	// Exchange tmp.

	// Read in some integers.
	int i = 0;
 reader:
	if(i >= SIZE) goto toobig;
	if(scanf("%d", &nums[i]) != 1) goto read_done;
	i++;
	goto reader;
 read_done:
	count = i;

	// Most of this stuff breaks with size zero.
	if(count <= 0) goto nothing;

	// Sort won't work properly with one value.  And isn't needed.
	if(count <= 1) goto doprint;

	limit = count - 2;

	// Scan for out-of-order pairs.
 pairscan:
	i = 0;

	// See if the pair at [i] and [i+1] is in order, and swap them
	// if not.
 pairswap:
	if(nums[i] <= nums[i+1]) goto keep;
	tmp = nums[i];
	nums[i] = nums[i+1];
	nums[i+1] = tmp;
 keep:
	// Increment pair scan, and repeat the pair swap if needed.
	if(++i <= limit) goto pairswap;

	// Reduce the pair scan limit, and perform the next one
	// if needed.
	if(--limit >= 0) goto pairscan;

 doprint:
	// Print the sorted list.
	i = 0;
 printloop:
	printf("%d ", nums[i]);
	if(++i < count) goto printloop;
	printf("\n");
 nothing:
	exit(0);

 toobig:
	printf("More than %d input values.\n", SIZE);
	exit(1);
}
