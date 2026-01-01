; stack.asm
; x86-64 Linux
; Reads numbers and stores them on the stack.
; When the user enters "0", all stored values are printed.
;
; Uses functions from subs.inc:
;   - print_str
;   - print_lf
%include "subs.inc"

section .data
    prompt      db "Enter a number (0 to print): ", 0
    label_num   db "Number: ", 0

section .bss
    buf         resb 64              ; temporary input buffer

section .text
global _start

_start:
    mov rbp, rsp                    ; save initial stack pointer as sentinel

; =========================
; Main input loop
; =========================
read_loop:
    mov rax, prompt
    call print_str                  ; print prompt

    ; read(0, buf, 64)
    xor rax, rax                    ; syscall number 0 = read
    xor rdi, rdi                    ; file descriptor 0 = stdin
    mov rsi, buf                    ; buffer address
    mov rdx, 64                     ; max bytes
    syscall                         ; rax = number of bytes read

    cmp rax, 0
    jle read_loop                   ; if nothing read, try again (Jump if Less or Equal)

    ; =========================
    ; Calculate string length
    ; =========================
    xor rcx, rcx                    ; rcx = length counter

len_loop:
    mov al, [buf + rcx]
    cmp al, 10                      ; newline '\n'
    je len_done
    cmp al, 13                      ; carriage return '\r'
    je len_done
    cmp al, 0
    je len_done
    inc rcx
    cmp rcx, 63
    jl len_loop

len_done:
    cmp rcx, 0
    je read_loop                   ; ignore empty line

    mov byte [buf + rcx], 0         ; null-terminate string

    ; =========================
    ; Check for termination input "0"
    ; =========================
    cmp rcx, 1
    jne store_text
    cmp byte [buf], '0'
    je print_all

; =========================
; Store text on the stack
; =========================
store_text:
    lea rdx, [rcx + 1]              ; real length including null terminator

    ; Align size to multiple of 8 bytes
    mov r8, rdx
    add r8, 7
    and r8, -8                      ; r8 = padded size

    sub rsp, r8                     ; reserve space on stack
    mov r12, rsp                    ; r12 = pointer to stored text

    ; Copy text into stack memory
    mov rdi, r12                    ; destination
    mov rsi, buf                    ; source
    mov r9, rdx                     ; byte counter

copy_loop:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    dec r9
    jnz copy_loop

    ; Push metadata
    push r8                         ; padded size
    push r12                        ; pointer to text

    jmp read_loop

; =========================
; Print all stored entries
; =========================
print_all:
print_loop:
    cmp rsp, rbp
    je exit_ok                     ; stop when stack is empty

    pop r12                        ; pointer to text
    pop r13                        ; padded size

    mov rax, label_num
    call print_str

    mov rax, r12
    call print_str
    call print_lf

    add rsp, r13                   ; release text memory
    jmp print_loop

; =========================
; Exit program
; =========================
exit_ok:
    mov rax, 60                    ; sys_exit
    xor rdi, rdi                   ; exit code 0
    syscall
