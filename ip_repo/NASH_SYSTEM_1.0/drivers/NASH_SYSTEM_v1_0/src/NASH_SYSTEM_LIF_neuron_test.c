#include "platform.h"
#include "xbasic_types.h"
#include "xparameters.h"
#include <stdlib.h>

Xuint32 *baseaddr_p = (Xuint32 *)XPAR_NASH_SYSTEM_0_S00_AXI_BASEADDR;

int main()
{
init_platform();
srand(0);
int r;
int V;
xil_printf("NASH Test\n\r");

// Write multiplier inputs to register 0
*(baseaddr_p+0) = 0x00010000; // reset

for (int i=0; i < 10; i++) {
	for (int j=0; j < 10; j++) {
		r = rand()% 20;
		*(baseaddr_p+0) = (0x00020000  + (j << 25)+r); // input spike
		xil_printf("Wrote: 0x%08x \n\r", *(baseaddr_p+0));
		xil_printf("Input (weighted spike): %d \n\r", r);

		// Read multiplier output from register 1
		xil_printf("Read : 0x%08x \n\r", *(baseaddr_p+1));
		V = *(baseaddr_p+1) << 1;
		V = V/2;
		xil_printf("Output (membrane potential): %d \n\r", V);
		xil_printf("Output (spike): %d \n\r", *(baseaddr_p+1) >> 31);
	}
	*(baseaddr_p+0) = 0x00040000; //
	xil_printf("Wrote: 0x%08x \n\r", *(baseaddr_p+0));
	// Read multiplier output from register 1
	xil_printf("Read : 0x%08x \n\r", *(baseaddr_p+1));
	xil_printf("End of time-step\n\n\r");
}
xil_printf("End of test\n\n\r");

return 0;
}
