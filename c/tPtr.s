	.file	"tPtr.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "&i = 0x%p\12\0"
.LC1:
	.ascii "0x%p\11"
	.ascii "0x%x\11"
	.ascii "0x%x\12\0"
.LC2:
	.ascii "0x%p\11"
	.ascii "0x%x\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$0, -20(%rbp)
	leaq	-20(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$170, (%rax)
	movl	-20(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	movq	$6422016, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$43707, (%rax)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %r8d
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
