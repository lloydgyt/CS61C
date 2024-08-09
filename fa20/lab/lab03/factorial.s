.globl factorial

.data
n: .word 7

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
# do I need to save register here?
# base case
# if (a0 == 0) return 1; 
# else return a0 * fact(a0 - 1);

# BEGIN PROLOGUE
addi sp, sp, -8 
sw s0, 0(sp)
sw ra, 4(sp)
# END PROLOGUE

beq a0, x0, finish

add s0, x0, a0 # store the value of `n` at s0
addi a0, a0, -1
jal factorial
mul a0, s0, a0 

# BEGIN EPILOGUE
lw s0, 0(sp)
lw ra, 4(sp)
addi sp, sp, 8
# END EPILOGUE

jr ra

finish:
addi a0, x0, 1
jr ra
