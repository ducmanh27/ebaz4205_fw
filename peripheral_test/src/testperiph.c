/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */

#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "scugic_header.h"
#include "xemaclite.h"
#include "xemaclite_example.h"
#include "emaclite_header.h"
#include "emaclite_intr_header.h"
#include "iic_header.h"
#include "xspi.h"
#include "spi_header.h"
#include "spi_intr_header.h"
#include "xuartns550_l.h"
#include "uartns550_header.h"
#include "xuartns550.h"
#include "uartns550_intr_header.h"
#include "xdevcfg.h"
#include "devcfg_header.h"
#include "xdmaps.h"
#include "dmaps_header.h"
#include "xqspips.h"
#include "qspips_header.h"
#include "xscutimer.h"
#include "scutimer_header.h"
#include "xscuwdt.h"
#include "scuwdt_header.h"
int main () 
{
   static XScuGic intc;
   static XEmacLite axi_ethernetlite_0_EmacLite;
   static XSpi axi_quad_spi_0_Spi;
   static XUartNs550 axi_uart16550_0_UartNs550;
   static XScuTimer ps7_scutimer_0;
   static XScuWdt ps7_scuwdt_0;
   Xil_ICacheEnable();
   Xil_DCacheEnable();
   print("---Entering main---\n\r");


	   {
	      int Status;

	      print("\r\n Running ScuGicSelfTestExample() for ps7_scugic...\r\n");

	      Status = ScuGicSelfTestExample(XPAR_PS7_SCUGIC_0_DEVICE_ID);

	      if (Status == 0) {
	         print("ScuGicSelfTestExample PASSED\r\n");
	      }
	      else {
	         print("ScuGicSelfTestExample FAILED\r\n");
	      }
	   }

	   {
	       int Status;

	       Status = ScuGicInterruptSetup(&intc, XPAR_PS7_SCUGIC_0_DEVICE_ID);
	       if (Status == 0) {
	          print("ScuGic Interrupt Setup PASSED\r\n");
	       }
	       else {
	         print("ScuGic Interrupt Setup FAILED\r\n");
	      }
	   }



   {
      int status;

      print("\r\nRunning EmacLitePolledExample() for axi_ethernetlite_0...\r\n");
      status = EmacLitePolledExample(XPAR_AXI_ETHERNETLITE_0_DEVICE_ID);
      if (status == 0) {
         print("EmacLite Polled Example PASSED\r\n");
      }
      else {
         print("EmacLite Polled Example FAILED\r\n");
      }
   }
   {
      int Status;

      print("\r\n Running Interrupt Test  for axi_ethernetlite_0...\r\n");

      Status = EmacLiteIntrExample(&intc, &axi_ethernetlite_0_EmacLite, \
                               XPAR_AXI_ETHERNETLITE_0_DEVICE_ID, \
                               XPAR_FABRIC_AXI_ETHERNETLITE_0_IP2INTC_IRPT_INTR);

      if (Status == 0) {
         print("EmacLite Interrupt Test PASSED\r\n");
      }
      else {
         print("EmacLite Interrupt Test FAILED\r\n");
      }

   }



   {
      int status;


      print("\r\n Running IicSelfTestExample() for axi_iic_0...\r\n");

      status = IicSelfTestExample(XPAR_AXI_IIC_0_DEVICE_ID);

      if (status == 0) {
         print("IicSelfTestExample PASSED\r\n");
      }
      else {
         print("IicSelfTestExample FAILED\r\n");
      }
   }



   {
      XStatus status;
      
      print("\r\n Running SpiSelfTestExample() for axi_quad_spi_0...\r\n");
      
      status = SpiSelfTestExample(XPAR_AXI_QUAD_SPI_0_DEVICE_ID);
      
      if (status == 0) {
         print("SpiSelfTestExample PASSED\r\n");
      }
      else {
         print("SpiSelfTestExample FAILED\r\n");
      }
   }
    {
       XStatus Status;

       print("\r\n Running Interrupt Test for axi_quad_spi_0...\r\n");

       Status = SpiIntrExample(&intc, &axi_quad_spi_0_Spi, \
                                XPAR_AXI_QUAD_SPI_0_DEVICE_ID, \
                                XPAR_FABRIC_AXI_QUAD_SPI_0_IP2INTC_IRPT_INTR);
      if (Status == 0) {
         print("Spi Interrupt Test PASSED\r\n");
      } 
      else {
         print("Spi Interrupt Test FAILED\r\n");
      }

    }



   {
      XStatus status;

      print("\r\nRunning UartNs550SelfTestExample() for axi_uart16550_0...\r\n");
      status = UartNs550SelfTestExample(XPAR_AXI_UART16550_0_DEVICE_ID);
      if (status == 0) {
         print("UartNs550SelfTestExample PASSED\r\n");
      }
      else {
         print("UartNs550SelfTestExample FAILED\r\n");
      }
   }
   {
      XStatus Status;

      print("\r\n Running Interrupt Test for axi_uart16550_0...\r\n");

      Status = UartNs550IntrExample(&intc, &axi_uart16550_0_UartNs550, \
                                  XPAR_AXI_UART16550_0_DEVICE_ID, \
                                  XPAR_FABRIC_AXI_UART16550_0_IP2INTC_IRPT_INTR);

      if (Status == 0) {
         print("UartNs550 Interrupt Test PASSED\r\n");
      }
      else {
         print("UartNs550 Interrupt Test FAILED\r\n");
      }

   }



   {
      int Status;

      print("\r\n Running DcfgSelfTestExample() for ps7_dev_cfg_0...\r\n");

      Status = DcfgSelfTestExample(XPAR_PS7_DEV_CFG_0_DEVICE_ID);

      if (Status == 0) {
         print("DcfgSelfTestExample PASSED\r\n");
      }
      else {
         print("DcfgSelfTestExample FAILED\r\n");
      }
   }



   {
      int Status;
      
      print("\r\n Running XDmaPs_Example_W_Intr() for ps7_dma_s...\r\n");
      
      Status = XDmaPs_Example_W_Intr(&intc,XPAR_PS7_DMA_S_DEVICE_ID);
      
      if (Status == 0) {
         print("XDmaPs_Example_W_Intr PASSED\r\n");
      }
      else {
         print("XDmaPs_Example_W_Intr FAILED\r\n");
      }
   }



   {
      int Status;

      print("\r\n Running QspiSelfTestExample() for ps7_qspi_0...\r\n");

      Status = QspiPsSelfTestExample(XPAR_PS7_QSPI_0_DEVICE_ID);

      if (Status == 0) {
         print("QspiPsSelfTestExample PASSED\r\n");
      }
      else {
         print("QspiPsSelfTestExample FAILED\r\n");
      }
   }



   {
      int Status;

      print("\r\n Running ScuTimerPolledExample() for ps7_scutimer_0...\r\n");

      Status = ScuTimerPolledExample(XPAR_PS7_SCUTIMER_0_DEVICE_ID);

      if (Status == 0) {
         print("ScuTimerPolledExample PASSED\r\n");
      }
      else {
         print("ScuTimerPolledExample FAILED\r\n");
      }
   }
   {
      int Status;

      print("\r\n Running Interrupt Test  for ps7_scutimer_0...\r\n");

      Status = ScuTimerIntrExample(&intc, &ps7_scutimer_0, \
                                 XPAR_PS7_SCUTIMER_0_DEVICE_ID, \
                                 XPAR_PS7_SCUTIMER_0_INTR);

      if (Status == 0) {
         print("ScuTimerIntrExample PASSED\r\n");
      }
      else {
         print("ScuTimerIntrExample FAILED\r\n");
      }

   }


   {
      int Status;

      print("\r\n Running Interrupt Test  for ps7_scuwdt_0...\r\n");

      Status = ScuWdtIntrExample(&intc, &ps7_scuwdt_0, \
                                 XPAR_PS7_SCUWDT_0_DEVICE_ID, \
                                 XPAR_PS7_SCUWDT_0_INTR);

      if (Status == 0) {
         print("ScuWdtIntrExample PASSED\r\n");
      }
      else {
         print("ScuWdtIntrExample FAILED\r\n");
      }

   }


   /*
    * Peripheral Test will not be run for ps7_uart_1
    * because it has been selected as the STDOUT device
    */



   print("---Exiting main---\n\r");
   Xil_DCacheDisable();
   Xil_ICacheDisable();
   return 0;
}
