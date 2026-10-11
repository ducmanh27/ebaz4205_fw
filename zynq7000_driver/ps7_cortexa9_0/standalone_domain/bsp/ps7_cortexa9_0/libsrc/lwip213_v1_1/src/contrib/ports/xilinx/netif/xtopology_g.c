#include "netif/xtopology.h"
#include "xparameters.h"

struct xtopology_t xtopology[] = {
	{
		0x40E00000,
		xemac_type_xps_emaclite,
		0x0,
		XPAR_FABRIC_AXI_ETHERNETLITE_0_IP2INTC_IRPT_INTR,
		0xF8F00100,
		0x0,
	},
};

int xtopology_n_emacs = 1;
