	.text
	.file	"get_name.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	leaq	-24(%rbp), %rdi
	movl	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	movl	%eax, -28(%rbp)         # 4-byte Spill
	callq	get_string
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	print_name
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
.Ltmp3:
	.size	main, .Ltmp3-main
	.cfi_endproc

	.globl	print_name
	.align	16, 0x90
	.type	print_name,@function
print_name:                             # @print_name
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp4:
	.cfi_def_cfa_offset 16
.Ltmp5:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp6:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$.L.str1, %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movq	%rax, %rdi
	movb	$0, %al
	callq	printf
	movl	%eax, -12(%rbp)         # 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
.Ltmp7:
	.size	print_name, .Ltmp7-print_name
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Name: "
	.size	.L.str, 7

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"hello, %s\n"
	.size	.L.str1, 11


	.ident	"Ubuntu clang version 3.6.0-2ubuntu1~trusty1 (tags/RELEASE_360/final) (based on LLVM 3.6.0)"
	.section	".note.GNU-stack","",@progbits
