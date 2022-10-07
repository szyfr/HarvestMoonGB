
;;= Definitions
INCLUDE "src/todo.inc"


;;= Code
INCLUDE "src/reset_vectors/reset_vectors.inc"          ;; ROM0[$0000]
INCLUDE "src/reset_vectors/hardware_interrupts.inc"    ;; ROM0[$0040]
INCLUDE "src/reset_vectors/FUN_0061.inc"               ;; ROM0[$0061]


SECTION "header", ROM0[$0100]

EntryPoint:
	nop
	jp  start


ds $0150 - @, 0


start:

	

SECTION "End", ROMX[$7FFF], BANK[31]