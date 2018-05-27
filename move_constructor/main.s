	.file	"main.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_,"axG",@progbits,_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_,comdat
	.weak	_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_
	.type	_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_, @function
_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_:
.LFB1199:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1199:
	.size	_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_, .-_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_
	.section	.rodata
.LC0:
	.string	"origin.x: "
.LC1:
	.string	"copy.x: "
.LC2:
	.string	"move_obj.x: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1198:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1198
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZN10move_classC1Ev
	movl	-64(%rbp), %ebx
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	leaq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN10move_classC1ERS_
	movl	-48(%rbp), %ebx
	movl	$.LC1, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIR10move_classEONSt16remove_referenceIT_E4typeEOS3_
	movq	%rax, %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN10move_classC1EOS_
	movl	-32(%rbp), %ebx
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	movl	$0, %eax
	jmp	.L7
.L6:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L7:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1198:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1198:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1198-.LLSDACSB1198
.LLSDACSB1198:
	.uleb128 .LEHB0-.LFB1198
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L6-.LFB1198
	.uleb128 0
	.uleb128 .LEHB1-.LFB1198
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1198:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1354:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L8
	cmpl	$65535, -8(%rbp)
	jne	.L8
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1354:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1355:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1355:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
