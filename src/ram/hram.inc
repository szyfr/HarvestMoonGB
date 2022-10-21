section "HRAM", HRAM

run_dma :: ds 10 ; $FF80

; Unused
;
; TODO name
unk_1   :: db ; $FF90
unk_2   :: db ; $FF91
unk_3   :: db ; $FF92

; Used in entry
;
; TODO name
; might be flags?
; Not used so far
unk_4   :: db ; $FF93


hempty_1 :: ds $0025


; Used in 3036
;
; TODO name
unk_5   :: db ; $FFB8
unk_6   :: db ; $FFB9
unk_7   :: db ; $FFBA
unk_8   :: db ; $FFBB
unk_9   :: db ; $FFBC
unk_10  :: db ; $FFBD
unk_11  :: db ; $FFBE
