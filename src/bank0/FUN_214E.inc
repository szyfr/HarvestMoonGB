
SECTION "214E", ROM0[$214E]

;;= FUN_214E
;;=  
;;=  Input: 
FUN_214E:
	ld  c,$80
	ld  b,$0A
	ld  hl,load_dma

.loop:
	ld  a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr  nz,.loop
	ret

;I don't know what this is for?
load_dma:
	ld  a,$C0
	ldh  [rDMA],a
	ld  a,$28
.loop:
	dec a
	jr  nz,.loop
	ret