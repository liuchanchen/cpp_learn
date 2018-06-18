	.file	"basic_excpt.cpp"
	.section	.text._ZNSt9exceptionC2Ev,"axG",@progbits,_ZNSt9exceptionC5Ev,comdat
	.align 2
	.weak	_ZNSt9exceptionC2Ev
	.type	_ZNSt9exceptionC2Ev, @function
_ZNSt9exceptionC2Ev:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTVSt9exception+16, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZNSt9exceptionC2Ev, .-_ZNSt9exceptionC2Ev
	.weak	_ZNSt9exceptionC1Ev
	.set	_ZNSt9exceptionC1Ev,_ZNSt9exceptionC2Ev
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"entry my_excption"
	.text
	.align 2
	.globl	_ZN11my_excptionC2Ev
	.type	_ZN11my_excptionC2Ev, @function
_ZN11my_excptionC2Ev:
.LFB972:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA972
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9exceptionC2Ev
	movq	-24(%rbp), %rax
	movq	$_ZTV11my_excption+16, (%rax)
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	jmp	.L5
.L4:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9exceptionD2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L5:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE972:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA972:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE972-.LLSDACSB972
.LLSDACSB972:
	.uleb128 .LEHB0-.LFB972
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L4-.LFB972
	.uleb128 0
	.uleb128 .LEHB1-.LFB972
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE972:
	.text
	.size	_ZN11my_excptionC2Ev, .-_ZN11my_excptionC2Ev
	.globl	_ZN11my_excptionC1Ev
	.set	_ZN11my_excptionC1Ev,_ZN11my_excptionC2Ev
	.align 2
	.globl	_ZN11my_excptionD2Ev
	.type	_ZN11my_excptionD2Ev, @function
_ZN11my_excptionD2Ev:
.LFB975:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTV11my_excption+16, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9exceptionD2Ev
	movl	$0, %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L6
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE975:
	.size	_ZN11my_excptionD2Ev, .-_ZN11my_excptionD2Ev
	.globl	_ZN11my_excptionD1Ev
	.set	_ZN11my_excptionD1Ev,_ZN11my_excptionD2Ev
	.align 2
	.globl	_ZN11my_excptionD0Ev
	.type	_ZN11my_excptionD0Ev, @function
_ZN11my_excptionD0Ev:
.LFB977:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN11my_excptionD1Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE977:
	.size	_ZN11my_excptionD0Ev, .-_ZN11my_excptionD0Ev
	.section	.rodata
.LC1:
	.string	"my_excption caught"
	.text
	.align 2
	.globl	_ZN11my_excption4whatEv
	.type	_ZN11my_excption4whatEv, @function
_ZN11my_excption4whatEv:
.LFB978:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	$.LC1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE978:
	.size	_ZN11my_excption4whatEv, .-_ZN11my_excption4whatEv
	.align 2
	.globl	_ZN11my_excption14test_no_exceptEi
	.type	_ZN11my_excption14test_no_exceptEi, @function
_ZN11my_excption14test_no_exceptEi:
.LFB979:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE979:
	.size	_ZN11my_excption14test_no_exceptEi, .-_ZN11my_excption14test_no_exceptEi
	.section	.text._ZNSt9exceptionC2ERKS_,"axG",@progbits,_ZNSt9exceptionC5ERKS_,comdat
	.align 2
	.weak	_ZNSt9exceptionC2ERKS_
	.type	_ZNSt9exceptionC2ERKS_, @function
_ZNSt9exceptionC2ERKS_:
.LFB982:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTVSt9exception+16, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE982:
	.size	_ZNSt9exceptionC2ERKS_, .-_ZNSt9exceptionC2ERKS_
	.weak	_ZNSt9exceptionC1ERKS_
	.set	_ZNSt9exceptionC1ERKS_,_ZNSt9exceptionC2ERKS_
	.section	.rodata
.LC2:
	.string	"test_no_except"
	.text
	.align 2
	.globl	_ZN11my_excption14test_no_exceptEv
	.type	_ZN11my_excption14test_no_exceptEv, @function
_ZN11my_excption14test_no_exceptEv:
.LFB980:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA980
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9exceptionC1Ev
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
.LEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$8, %edi
	call	__cxa_allocate_exception
	movq	%rax, %rbx
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt9exceptionC1ERKS_
	movl	$_ZNSt9exceptionD1Ev, %edx
	movl	$_ZTISt9exception, %esi
	movq	%rbx, %rdi
	call	__cxa_throw
.LEHE2:
.L18:
	movq	%rax, %rbx
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt9exceptionD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
	.cfi_endproc
.LFE980:
	.section	.gcc_except_table
.LLSDA980:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE980-.LLSDACSB980
.LLSDACSB980:
	.uleb128 .LEHB2-.LFB980
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L18-.LFB980
	.uleb128 0
	.uleb128 .LEHB3-.LFB980
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE980:
	.text
	.size	_ZN11my_excption14test_no_exceptEv, .-_ZN11my_excption14test_no_exceptEv
	.weak	_ZTV11my_excption
	.section	.rodata._ZTV11my_excption,"aG",@progbits,_ZTV11my_excption,comdat
	.align 32
	.type	_ZTV11my_excption, @object
	.size	_ZTV11my_excption, 48
_ZTV11my_excption:
	.quad	0
	.quad	_ZTI11my_excption
	.quad	_ZN11my_excptionD1Ev
	.quad	_ZN11my_excptionD0Ev
	.quad	_ZNKSt9exception4whatEv
	.quad	_ZN11my_excption4whatEv
	.weak	_ZTI11my_excption
	.section	.rodata._ZTI11my_excption,"aG",@progbits,_ZTI11my_excption,comdat
	.align 16
	.type	_ZTI11my_excption, @object
	.size	_ZTI11my_excption, 24
_ZTI11my_excption:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS11my_excption
	.quad	_ZTISt9exception
	.weak	_ZTS11my_excption
	.section	.rodata._ZTS11my_excption,"aG",@progbits,_ZTS11my_excption,comdat
	.type	_ZTS11my_excption, @object
	.size	_ZTS11my_excption, 14
_ZTS11my_excption:
	.string	"11my_excption"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB992:
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
	jne	.L19
	cmpl	$65535, -8(%rbp)
	jne	.L19
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE992:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN11my_excptionC2Ev, @function
_GLOBAL__sub_I__ZN11my_excptionC2Ev:
.LFB993:
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
.LFE993:
	.size	_GLOBAL__sub_I__ZN11my_excptionC2Ev, .-_GLOBAL__sub_I__ZN11my_excptionC2Ev
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN11my_excptionC2Ev
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
