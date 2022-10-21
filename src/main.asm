
;;= Definitions
include "src/include/hardware.inc"

include "src/todo.inc"


;= Bank 0
include "src/reset_vectors/reset_vectors.inc"       ;; ROM0[$0000]
include "src/reset_vectors/hardware_interrupts.inc" ;; ROM0[$0040]
include "src/reset_vectors/jump_table_2.inc"        ;; ROM0[$0061]
ds 28, $FF
include "src/entry.inc"                             ;; ROM0[$0100]
include "src/bank0/jump_table_1.inc"                ;; ROM0[$0258]

include "src/bank0/FUN_206C.inc"                    ;; ROM0[$206C]
include "src/bank0/jumptable_bank_call.inc"                    ;; ROM0[$2078]
include "src/bank0/bank_call.inc"                   ;; ROM0[$208B]
include "src/bank0/jump_hl.inc"                     ;; ROM0[$20A0]

include "src/bank0/copy_run_dma.inc"                ;; ROM0[$214E]
include "src/bank0/lcd_disable.inc"                 ;; ROM0[$2166]
include "src/bank0/load_lcdc_value.inc"             ;; ROM0[$217F]
; Ends in $C9, might be function
db $AF,$E0,$0F,$FA,$A0,$C0,$E0,$FF,$C9
include "src/bank0/clear_memory.inc"                ;; ROM0[$218E]

include "src/bank0/FUN_22E8.inc"                    ;; ROM0[$22E8]
; Doesn't end in $C9, might be data
db $FA,$00,$DD,$B7,$C8
include "src/bank0/wait_7000.inc"                   ;; ROM0[$2323]
include "src/bank0/FUN_232F.inc"                    ;; ROM0[$232F]
db $89,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; FUN_22E8
db $89,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00 ; FUN_22E8
; Function? It isn't called
db $D5,$E5,$CD,$66,$21,$E1,$3E,$E4
db $E0,$47,$11,$00,$88,$CD,$0B,$22
db $AF,$E0,$42,$E0,$43,$21,$00,$98
db $11,$0C,$00,$3E,$80,$0E,$0D,$06
db $14,$22,$3C,$05,$20,$FB,$19,$0D
db $20,$F5,$3E,$81,$E0,$40,$CD,$23
db $23,$E1,$CD,$E8,$22,$CD,$23,$23,$C9
include "src/bank0/FUN_23E9.inc"                    ;; ROM0[$23E9]
db $C9
include "src/bank0/FUN_2426.inc"                    ;; ROM0[$2426]
; Probable functions. Haven't been called yet.
db $AF,$EA,$A3,$D3,$FA,$A4,$D3,$EA,$97,$D3,$C9
db $3E,$04,$EA,$A3,$D3,$AF,$EA,$97,$D3,$C9
include "src/bank0/FUN_2468.inc"                    ;; ROM0[$2468]

include "src/bank0/FUN_3036.inc"                    ;; ROM0[$3036]

ds 7, $FF

;= Bank 7
include "src/bank7/FUN_77A7.inc"                    ;; ROM7[$77A7]
include "src/bank7/FUN_7816.inc"                    ;; ROM7[$7816]


SECTION "End", ROMX[$7FFF], BANK[31]


; RAM variables
include "src/ram/wram.inc"
include "src/ram/hram.inc"