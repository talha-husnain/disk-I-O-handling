#ifndef IORB_H
#define IORB_H

// IORB structure definition
typedef struct iorb {
  int base_pri;      // Base priority of the I/O request block
  char filler[100];  // Description of the I/O request block
  struct iorb *link; // Pointer to the next I/O request block in the list
} IORB;

#endif
