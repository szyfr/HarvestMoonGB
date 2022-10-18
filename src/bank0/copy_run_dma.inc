
SECTION "copy_run_dma", ROM0[$214E]

;;= copy_run_dma()
;;=
;;=  Copies run_dma to $FF80
copy_run_dma:
	; Sets target in HRAM and length of function
	ld  c,$80
	ld  b,$0A
	ld  hl,run_dma_origin

.loop:
	; Copies
	ld  a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr  nz,.loop
	ret


; Starts DMA transfer, then waits for completion
run_dma_origin:
	ld  a,$C0
	ldh  [rDMA],a
	ld  a,40
.loop:
	dec a
	jr  nz,.loop
	ret