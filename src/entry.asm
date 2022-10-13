
;;= Definitions
include "src/include/hardware.inc"

include "src/todo.inc"


;;= Code
include "src/reset_vectors/reset_vectors.inc"          ;; ROM0[$0000]
include "src/reset_vectors/hardware_interrupts.inc"    ;; ROM0[$0040]
include "src/reset_vectors/FUN_0061.inc"               ;; ROM0[$0061]


SECTION "header", ROM0[$0100]

EntryPoint:
	nop
	jp  start


ds $0150 - @, 0


start:
	nop
	nop
	di

	; Sets RAM bank to 0 and ROM bank to 1
	xor a
	ld  [rRAMB],a
	ld  a,1
	ld  [rROMB0],a

	; Set default stack
	ld  sp,$DFEF

	; Clears memory from $FF80->$FFFE
	ld  hl,$FF80
	ld  bc,$007F
	call clear_memory

	; Clears memory from $DD00->$DDFE
	ld  hl,$DD00
	ld  bc,$00FF
	call clear_memory

	; Call copy_run_dma
	call copy_run_dma

	; Clears BG pallette and OBJ color data
	xor a
	ldh [rBGP],a
	xor a
	ldh [rOBP0],a
	xor a
	ldh [rOBP1],a

	; Call FUN_2426
	call FUN_2426

	; Store variable
	ld  a,2
	ldh [$8D],a ; TODO

	; Call lcd_disable
	call lcd_disable

	xor a
	ldh [rSCY],a
	ldh [rSCX],a

	; Set RAM bank to 10
	ld  a,$0A
	ld  [rRAMG],a

	; Selects advanced banking mode
	ld  a,1
	ld  [rBANKS],a

	; Sets a variable to 0 and calls FUN_232F, jumps if carry
	xor a
	ld  [$DD00],a
	call FUN_232F ; TODO
	jr  nc,.LAB_01AC

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	ld  l,$A7
	ld  h,$77
	ld  a,7
	call FUN_208B ; TODO

	pop af
	pop hl

.LAB_01AC:
	di
.LAB_01AD:
	di

	; Clears IE, resets sp, then calls clear_memory
	xor a
	ldh [rIE],a
	ld  sp,$DFEF
	ld  hl,$FF80
	ld  bc,$007F
	call clear_memory

	; Store a variable to 2
	ld  a,2
	ldh [$8D],a

	; Calls lcd_disable
	call lcd_disable

	; Clears SCY+X
	xor a
	ldh [rSCY],a
	ldh [rSCX],a

	; Calls clear_memory
	ld  hl,$8000
	ld  bc,$1FFF
	call clear_memory
	
	; Calls clear_memory
	ld  hl,$C000
	ld  bc,$1CFF
	call clear_memory
	
	; Calls copy_run_dma
	call copy_run_dma

	; Sets RAM bank to 0
	xor a
	ld  [rRAMB],a

	; Sets a variable to $20
	ld  a,$20
	ld  [$C0A7],a

	; Calls lcd_disable
	call lcd_disable

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B ; TODO

	pop af
	pop hl

.LAB_01F7:
	di

	; Calls lcd_disable
	call lcd_disable

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B ; TODO

	pop af
	pop hl

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	ld  l,$16
	ld  h,$78
	ld  a,7
	call FUN_208B ; TODO

	pop af
	pop hl

	; Clears a HRAM value
	xor a
	ldh [$97],a

	; Calls FUN_0258
	call FUN_0258 ; TODO

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	; Calls FUN_208B
	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B ; TODO

	pop af
	pop hl

	; 
	xor a
	ld  [$C0A6],a ; TODO
	xor a
	ldh [$8D],a ; TODO
	xor a
	ldh [$9A],a ; TODO
	xor a
	ld  [$C500],a ; TODO
	xor a
	ldh [$97],a ; TODO

	; Saves hl=af and then calls FUN_208B
	push hl
	push af

	ld  l,$49
	ld  h,$79
	ld  a,7
	call FUN_208B ; TODO

	pop af
	pop hl

	; Calls FUN_0061
	call FUN_0061 ; TODO

	; Calls FUN_217F
	call FUN_217F ; TODO

	ei
.LAB_024D:
	; if [$C0A6] == 0, loop
	ld  a,[$C0A6] ; TODO
	or  a
	or  a
	jp  z,.LAB_024D

	jp  .LAB_01F7



include "src/bank0/FUN_0258.inc"     ; b0,$0258

include "src/bank0/FUN_206C.inc"     ; b0,$206C
include "src/bank0/FUN_2078.inc"     ; b0,$2078

include "src/bank0/copy_run_dma.inc" ; b0,$214E
include "src/bank0/lcd_disable.inc"  ; b0,$2166

include "src/bank0/clear_memory.inc" ; b0,$218E

include "src/bank0/FUN_22E8.inc"     ; b0,$22E8
db $FA,$00,$DD,$B7,$C8
include "src/bank0/wait_7000.inc"    ; b0,$2323
include "src/bank0/FUN_232F.inc"     ; b0,$232F

include "src/bank0/FUN_2426.inc"     ; b0,$2426
; Probable functions. Haven't been called yet.
db $AF,$EA,$A3,$D3,$FA,$A4,$D3,$EA,$97,$D3,$C9
db $3E,$04,$EA,$A3,$D3,$AF,$EA,$97,$D3,$C9
include "src/bank0/FUN_2468.inc"     ; b0,$2468


SECTION "End", ROMX[$7FFF], BANK[31]


; RAM variables
include "src/ram/hram.inc"