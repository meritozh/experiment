#include <stddef.h>
#include <printf.h>

#define container_of(ptr, type, member) \
  ((type *) ((char *)(ptr) - offsetof(type, member)))

typedef struct heap_node {
  char s;
  int d;
} heap_node;

typedef struct heap {
  heap_node *root;
  void *heap_node[3];
} heap;

int main() {
  printf("offset is: %ld\n", offsetof(heap_node, d));
  printf("offset is: %ld\n", offsetof(heap, heap_node));
}
