#ifndef HT_H
#define HT_H

#include <crtdefs.h>

#include <stdbool.h>
#include <stddef.h>

typedef struct ht ht;

ht *ht_create(void);

void ht_destroy(ht *table);

void *ht_get(ht *table, const char *key);

const char *ht_set(ht *table, const char *key, void *val);

size_t ht_length(ht *table);

typedef struct {
	const char *key;
	void *value;

	ht *_table;
	size_t _index;
} hti;

hti ht_iterator(ht *table);

bool ht_next(hti* it);

#endif
