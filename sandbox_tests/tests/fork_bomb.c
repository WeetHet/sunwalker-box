/*
description: Cannot start more processes than allowed
limits:
  processes: 100
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  for (int i = 0; i < 100; i++) {
    switch (fork()) {
    case 0:
      for (;;) {
        pause();
      }
    case -1:
      fprintf(stderr, "Failed to fork at process %d\n", i);
      return i < 80 ? 1 : 0;
    }
  }
  fprintf(stderr, "Did not fail to fork 100 times\n");
  return 1;
}
