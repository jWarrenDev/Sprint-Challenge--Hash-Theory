#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"
#include <time.h>

// very similar to the two sum problem. Interesting
// brute force attempt with 2 for loops.

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for (int index = 0; index < length; index++) {

    int weight = weights[index];
    int key = limit - weight;

    if (hash_table_retrieve(ht, weight) > -1) {
      Answer *hashOutput = malloc(sizeof(Answer *));
      hashOutput -> index_1 = index;
      hashOutput -> index_2 = hash_table_retrieve(ht, weight);

      return hashOutput;
    }

    hash_table_insert(ht, key, index);
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
     clock_t start, end;
     double cpu_time_used;
     
     start = clock();

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
  
}

#endif
