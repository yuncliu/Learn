.data


.global _start


.text
_start:
    movl $0,%ebx
    movl $1,%eax
    int  $0x80
