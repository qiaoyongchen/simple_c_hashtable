#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "ht.h"

int main() {
	ht *table = ht_create();
	int *numbers = (int *)malloc(20 * sizeof(int));
	char key[20];
	int *num_p = numbers;
	for (int i = 0; i < 20; i++) {
		*num_p = i;
		itoa(i, key, 10);
		ht_set(table, key, num_p);
		num_p++;
	}

	char *k = "2";
	int *pval = (int *)ht_get(table, k);
	printf("test: get key '%s', the value is %d \n\n", k, *pval);

	hti iter = ht_iterator(table);
	int i = 0;
	while (ht_next(&iter)) {
		printf("%2d iterator k: %s, v: %d \n", i++, iter.key, *((int *)iter.value));
	}

	ht_destroy(table); // free table && free key
	free(numbers); // free value

	return 0;
}
