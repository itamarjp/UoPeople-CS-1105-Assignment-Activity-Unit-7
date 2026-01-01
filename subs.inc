section .data

    EOL db 10                       ; Caractere de quebra de linha.
    INTMAX equ 18446744073709551615 ; Inteiro máximo com 64 bits.

section .text

; -----------------------------------------------------------------------------
; Converte o inteiro (em rax) para uma string e a imprime
; -----------------------------------------------------------------------------
; Uso: mov rax, IMM
;      call print_int
; -----------------------------------------------------------------------------
print_int:
        xor rcx, rcx        ; Zera contador (rcx).
    .loop:
        inc rcx             ; Incrementa o contador.
        xor rdx, rdx        ; Zera rdx (restos).
        mov rbx, 10         ; Copia o divisor para rbx.
        div rbx             ; Divide rax por rbx.
        add dl, '0'         ; Soma 0x30 ao resto no último byte de rdx.
        push rdx            ; Salva rdx na pilha.
        cmp rax, 0          ; Compara o quociente (rax) com zero.
        jnz .loop           ; Se não for zero, repete o loop.        
        mov rbx, rcx        ; Copia o contador (rcx) para rbx.
    .write:
        mov rax, 1          
        mov rdi, 1
        mov rsi, rsp        ; Usa o endereço do topo da pilha.
        mov rdx, 1          ; Imprimir apenas 1 byte.
        syscall
        pop rax             ; Remove o elemento no topo da pilha.
        dec rbx             ; Decrementa o contador (rbx).
        jnz .write          ; Enquanto não for zero, repete.
    ret

; -----------------------------------------------------------------------------
; Escreve escreve os caracteres de uma string (em rax) na saída padrão.
; -----------------------------------------------------------------------------
; Uso: mov rax, MEM (ponteiro para a string)
;      call print_str
; -----------------------------------------------------------------------------
print_str:
    .loop:
        push rax            ; Salva endereço em rax na pilha.
        mov rcx, [rax]      ; Copia o valor apontado por rax em rcx.
        cmp cl, 0           ; Compara o byte em cl com zero (\0).
        jz .endsub          ; Se igual, sai da sub-rotina...
        mov rbx, rax        ; Copia o endereço em rax para rbx.
        call write_char     ; Imprime primeiro byte em rbx.
        pop rax             ; Recupera o endereço da mensagem em rax
        inc rax             ; Incrementa o endereço da mensagem em rax
        jmp .loop           ; Repete até encontar o byte 0x0...
    .endsub:
        pop rax             ; Restaura o estado inicial da pilha.
    ret

; -----------------------------------------------------------------------------
; Escreve o caractere no endereço em rbx na saída padrão.
; -----------------------------------------------------------------------------
; Uso: mov rbx, MEM (ponteiro para o caractere)
;      call write char
; -----------------------------------------------------------------------------
write_char:
        mov rax, 1
        mov rdi, rax
        mov rsi, rbx
        mov rdx, 1
        syscall
    ret

; -----------------------------------------------------------------------------
; Imprime quebra de linha.
; -----------------------------------------------------------------------------
; Uso: call print_lf
; -----------------------------------------------------------------------------
print_lf:
        mov rax, 1
        mov rdi, rax
        mov rsi, EOL
        mov rdx, 1
        syscall
    ret


; vim: ft=asm
