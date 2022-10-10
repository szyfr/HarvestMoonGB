
SECTION "clear_memory", ROM0[$218E]

;;= clear_memory
;;=  Clears the input memory locations.
;;=  Input: HL - ptr, BC - counter
clear_memory:
	; Clear [hl] and increment
	xor a
	ld  [hl+],a

	; Dec bc and if zero repeat
	dec bc
	ld  a,c
	or  b
	jr  nz,clear_memory

	ret