#include "Memory.h"
#include "ArrayExt.h"

void array_release(Array ary) {
  int idx;
  for (idx = 0; idx < ary.count; idx++) {
    memory_free(ary.elements[idx].data);
  }
  memory_free(ary.elements);
}
