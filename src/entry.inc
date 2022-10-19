

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

	; clear_memory(_HRAM, 127)
	ld  hl,_HRAM
	ld  bc,$007F
	call clear_memory

	; clear_memory($DD00, 255)
	ld  hl,$DD00
	ld  bc,$00FF
	call clear_memory

	; copy_run_dma()
	call copy_run_dma

	; Clears BG pallette and OBJ color data
	xor a
	ldh [rBGP],a
	xor a
	ldh [rOBP0],a
	xor a
	ldh [rOBP1],a

	; FUN_2426()
	call FUN_2426

	; Store variable to unk_4
	ld  a,%00000010
	ldh [unk_4],a

	; lcd_disable()
	call lcd_disable

	; Clear scrolling
	xor a
	ldh [rSCY],a
	ldh [rSCX],a

	; Enable SRAM
	ld  a,$0A
	ld  [rRAMG],a

	; Selects advanced banking mode
	ld  a,$01
	ld  [rBANKS],a

	; Sets a variable
	xor a
	ld  [wunk_6],a

	; FUN_232F()
	call FUN_232F
	jr  nc,.LAB_01AC

	; FUN_208B(7, $77A7)
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

	; Clears IE and resets sp
	xor a
	ldh [rIE],a
	ld  sp,$DFEF

	; clear_memory(_HRAM, 127)
	ld  hl,_HRAM
	ld  bc,$007F
	call clear_memory

	; Store a variable to unk_4
	ld  a,%00000010
	ldh [unk_4],a

	; lcd_disable()
	call lcd_disable

	; Clears Scrolls
	xor a
	ldh [rSCY],a
	ldh [rSCX],a

	; clear_memory(_VRAM, 8191)
	ld  hl,_VRAM
	ld  bc,$1FFF
	call clear_memory
	
	; clear_memory(_RAM, 7423)
	ld  hl,_RAM
	ld  bc,$1CFF
	call clear_memory
	
	; copy_run_dma()
	call copy_run_dma

	; Sets RAM bank to 0
	xor a
	ld  [rRAMB],a

	; Sets a variable to $20
	ld  a,%00100000
	ld  [wunk_7],a

	; lcd_disable()
	call lcd_disable

	; FUN_208B(0, $2426)
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

	; lcd_disable()
	call lcd_disable

	; FUN_208B(0, $2426)
	push hl
	push af
	ld  l,$26
	ld  h,$24
	ld  a,0
	call FUN_208B
	pop af
	pop hl

	; FUN_208B(7, $7816)
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
	ldh [unk_4],a
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
