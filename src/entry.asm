
;;= Definitions

;;= Code


SECTION "header", ROM0[$0100]

EntryPoint:
	nop
	jp  start


ds $0150 - @, 0


start:

	

SECTION "End", ROMX[$7FFF], BANK[31]