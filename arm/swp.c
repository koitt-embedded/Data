#include <stdio.h>
int main(void)
{
	int i;
	unsigned int test_arr[7] = {0};
	register unsigned int *r0 asm("r0") = 0;
	register unsigned int r5 asm("r5") = 0;
	register unsigned int r6 asm("r6") = 0;
	register unsigned int r7 asm("r7") = 0;
	register unsigned int r8 asm("r8") = 0;
	register unsigned int r9 asm("r9") = 0;
	register unsigned int r10 asm("r10") = 0;
	r0 = test_arr;
	asm volatile("mov r5, #0x3\n"
			"mov r6, r5, lsl #2\n"
			"mov r8, #0x2\n"
			"add r7, r5, r6, lsl r8\n"
			"stmia r0!, {r5, r6, r7}\n"
			"str r8, [r0]\n"
			"mov r9, #128\n"
			"mov r10, r9, lsr #3\n"
			"stmia r0, {r8, r9, r10}\n"
			"sub r0, r0, #12\n"
			"ldmia r0, {r8, r9, r10}\n"
			"swp r10, r7, [r0]");
	for(i = 0; i < 7; i++)
		printf("test_arr[%d] = %d\n", i, test_arr[i]);
	printf("r7 = %u, r8 = %u, r9 = %u, r10 = %u\n", r7, r8, r9, r10);
	return 0;
}
