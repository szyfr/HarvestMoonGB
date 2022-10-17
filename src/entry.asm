
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
	call FUN_232F
	jr  nc,.LAB_01AC

	; FUN_208B(bank = 7, target = $77A7)
	push hl
	push af
	ld  l,$A7
	ld  h,$77
	ld  a,7
	call FUN_208B
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

	; FUN_208B(bank = 0, target = $2426)
	push hl
	push af
	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B
	pop af
	pop hl

.LAB_01F7:
	di

	; Calls lcd_disable
	call lcd_disable

	; FUN_208B(bank = 0, target = $2426)
	push hl
	push af
	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B
	pop af
	pop hl

	; FUN_208B(bank = 7, target = $7816)
	push hl
	push af
	ld  l,$16
	ld  h,$78
	ld  a,7
	call FUN_208B
	pop af
	pop hl

	; Clears a HRAM value
	xor a
	ldh [$97],a

	; Calls FUN_0258
	call FUN_0258

	; FUN_208B(bank = 0, target = $2426)
	push hl
	push af
	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B
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

	; FUN_208B(bank = 7, target = $7949)
	push hl
	push af
	ld  l,$49
	ld  h,$79
	ld  a,7
	call FUN_208B
	pop af
	pop hl

	; Calls FUN_0061
	call FUN_0061

	; Calls FUN_217F
	call FUN_217F

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
include "src/bank0/FUN_208B.inc"     ; b0,$208B
include "src/bank0/jump_hl.inc"     ; b0,$20A0

include "src/bank0/copy_run_dma.inc" ; b0,$214E
include "src/bank0/lcd_disable.inc"  ; b0,$2166
include "src/bank0/FUN_217F.inc"     ; b0,$217F
; Ends in $C9, might be function
db $AF,$E0,$0F,$FA,$A0,$C0,$E0,$FF,$C9
include "src/bank0/clear_memory.inc" ; b0,$218E

include "src/bank0/FUN_22E8.inc"     ; b0,$22E8
; Doesn't end in $C9, might be data
db $FA,$00,$DD,$B7,$C8
include "src/bank0/wait_7000.inc"    ; b0,$2323
include "src/bank0/FUN_232F.inc"     ; b0,$232F

include "src/bank0/FUN_2426.inc"     ; b0,$2426
; Probable functions. Haven't been called yet.
db $AF,$EA,$A3,$D3,$FA,$A4,$D3,$EA,$97,$D3,$C9
db $3E,$04,$EA,$A3,$D3,$AF,$EA,$97,$D3,$C9
include "src/bank0/FUN_2468.inc"     ; b0,$2468


include "src/bank7/FUN_77A7.inc"     ; b7,$77A7


SECTION "End", ROMX[$7FFF], BANK[31]


; RAM variables
include "src/ram/hram.inc"