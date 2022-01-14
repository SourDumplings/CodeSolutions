	.file	"main.cpp"
	.section	.rodata
.LC0:
	.string	"sizeof(a) = %d, &a = %p\n"
.LC1:
	.string	"sizeof(b) = %d, &b = %p\n"
.LC2:
	.string	"sizeof(c) = %d, &c = %p\n"
.LC3:
	.string	"sizeof(d) = %d, &d = %p\n"
.LC4:
	.string	"sizeof(e) = %d, &e = %p\n"
.LC5:
	.string	"sizeof(f) = %d, &f = %p\n"
.LC6:
	.string	"sizeof(g) = %d, &g = %p\n"
.LC7:
	.string	"sizeof(h) = %d, &h = %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdx
	movl	$8, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdx
	movl	$4, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$12, %rax
	movq	%rax, %rdx
	movl	$1, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$14, %rax
	movq	%rax, %rdx
	movl	$2, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdx
	movl	$8, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rdx
	movl	$8, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdx
	movl	$4, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$40, %rax
	movq	%rax, %rdx
	movl	$8, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
