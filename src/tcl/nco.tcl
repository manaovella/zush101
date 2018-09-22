create_project nco nco -part xc7z010clg225-1
create_bd_design "nco_1"
update_compile_order -fileset sources_1

startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_0
set_property -dict [list     \
    CONFIG.PCW_DDR_RAM_HIGHADDR {0x1FFFFFFF}  \
    CONFIG.PCW_FCLK_CLK1_BUF {FALSE}  \
    CONFIG.PCW_FCLK_CLK2_BUF {FALSE}  \
    CONFIG.PCW_FCLK_CLK3_BUF {TRUE}  \
    CONFIG.PCW_UIPARAM_DDR_ROW_ADDR_COUNT {15}  \
    CONFIG.PCW_UIPARAM_DDR_T_RC {48.91}  \
    CONFIG.PCW_UIPARAM_DDR_T_FAW {40.0}  \
    CONFIG.PCW_UIPARAM_DDR_DQS_0_PACKAGE_LENGTH {81.244}  \
    CONFIG.PCW_UIPARAM_DDR_DQS_1_PACKAGE_LENGTH {57.044}  \
    CONFIG.PCW_UIPARAM_DDR_DQS_2_PACKAGE_LENGTH {520}  \
    CONFIG.PCW_UIPARAM_DDR_DQS_3_PACKAGE_LENGTH {700}  \
    CONFIG.PCW_UIPARAM_DDR_DQ_0_PACKAGE_LENGTH {77.166}  \
    CONFIG.PCW_UIPARAM_DDR_DQ_1_PACKAGE_LENGTH {53.995}  \
    CONFIG.PCW_UIPARAM_DDR_DQ_2_PACKAGE_LENGTH {550}  \
    CONFIG.PCW_UIPARAM_DDR_DQ_3_PACKAGE_LENGTH {780}  \
    CONFIG.PCW_UIPARAM_DDR_CLOCK_0_PACKAGE_LENGTH {86.1835}  \
    CONFIG.PCW_UIPARAM_DDR_CLOCK_1_PACKAGE_LENGTH {86.1835}  \
    CONFIG.PCW_UIPARAM_DDR_CLOCK_2_PACKAGE_LENGTH {86.1835}  \
    CONFIG.PCW_UIPARAM_DDR_CLOCK_3_PACKAGE_LENGTH {86.1835}  \
    CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_0 {0.005}  \
    CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_1 {0.029}  \
    CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_2 {-0.434}  \
    CONFIG.PCW_PACKAGE_DDR_DQS_TO_CLK_DELAY_3 {-0.614}  \
    CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY0 {0.082}  \
    CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY1 {0.070}  \
    CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY2 {0.318}  \
    CONFIG.PCW_PACKAGE_DDR_BOARD_DELAY3 {0.433}  \
    CONFIG.PCW_CPU_CPU_6X4X_MAX_RANGE {667}  \
    CONFIG.PCW_I2C_PERIPHERAL_FREQMHZ {111.111115}  \
    CONFIG.PCW_FPGA0_PERIPHERAL_FREQMHZ {100}  \
    CONFIG.PCW_FPGA1_PERIPHERAL_FREQMHZ {100}  \
    CONFIG.PCW_FPGA2_PERIPHERAL_FREQMHZ {200}  \
    CONFIG.PCW_FPGA3_PERIPHERAL_FREQMHZ {12.288}  \
    CONFIG.PCW_ACT_QSPI_PERIPHERAL_FREQMHZ {200.000000}  \
    CONFIG.PCW_ACT_ENET0_PERIPHERAL_FREQMHZ {125.000000}  \
    CONFIG.PCW_ACT_SDIO_PERIPHERAL_FREQMHZ {100.000000}  \
    CONFIG.PCW_ACT_UART_PERIPHERAL_FREQMHZ {100.000000}  \
    CONFIG.PCW_ACT_FPGA0_PERIPHERAL_FREQMHZ {100.000000}  \
    CONFIG.PCW_ACT_FPGA1_PERIPHERAL_FREQMHZ {10.000000}  \
    CONFIG.PCW_ACT_FPGA2_PERIPHERAL_FREQMHZ {10.000000}  \
    CONFIG.PCW_ACT_FPGA3_PERIPHERAL_FREQMHZ {12.280701}  \
    CONFIG.PCW_CLK0_FREQ {100000000}  \
    CONFIG.PCW_CLK1_FREQ {10000000}  \
    CONFIG.PCW_CLK2_FREQ {10000000}  \
    CONFIG.PCW_CLK3_FREQ {12280701}  \
    CONFIG.PCW_QSPI_PERIPHERAL_DIVISOR0 {7}  \
    CONFIG.PCW_SDIO_PERIPHERAL_DIVISOR0 {14}  \
    CONFIG.PCW_UART_PERIPHERAL_DIVISOR0 {14}  \
    CONFIG.PCW_SPI_PERIPHERAL_DIVISOR0 {1}  \
    CONFIG.PCW_FCLK0_PERIPHERAL_DIVISOR0 {7}  \
    CONFIG.PCW_FCLK1_PERIPHERAL_DIVISOR0 {1}  \
    CONFIG.PCW_FCLK2_PERIPHERAL_DIVISOR0 {1}  \
    CONFIG.PCW_FCLK3_PERIPHERAL_DIVISOR0 {19}  \
    CONFIG.PCW_FCLK0_PERIPHERAL_DIVISOR1 {2}  \
    CONFIG.PCW_FCLK3_PERIPHERAL_DIVISOR1 {6}  \
    CONFIG.PCW_DCI_PERIPHERAL_DIVISOR0 {15}  \
    CONFIG.PCW_DCI_PERIPHERAL_DIVISOR1 {7}  \
    CONFIG.PCW_PCAP_PERIPHERAL_DIVISOR0 {7}  \
    CONFIG.PCW_IOPLL_CTRL_FBDIV {42}  \
    CONFIG.PCW_IO_IO_PLL_FREQMHZ {1400.000}  \
    CONFIG.PCW_SDIO_PERIPHERAL_VALID {1}  \
    CONFIG.PCW_SPI_PERIPHERAL_VALID {0}  \
    CONFIG.PCW_UART_PERIPHERAL_VALID {1}  \
    CONFIG.PCW_EN_EMIO_GPIO {1}  \
    CONFIG.PCW_EN_EMIO_I2C0 {1}  \
    CONFIG.PCW_EN_EMIO_PJTAG {0}  \
    CONFIG.PCW_EN_EMIO_SDIO0 {0}  \
    CONFIG.PCW_EN_EMIO_CD_SDIO0 {0}  \
    CONFIG.PCW_EN_EMIO_WP_SDIO0 {0}  \
    CONFIG.PCW_EN_EMIO_SPI0 {0}  \
    CONFIG.PCW_EN_EMIO_SPI1 {0}  \
    CONFIG.PCW_EN_EMIO_UART0 {0}  \
    CONFIG.PCW_EN_EMIO_TTC0 {1}  \
    CONFIG.PCW_EN_EMIO_TTC1 {0}  \
    CONFIG.PCW_USE_M_AXI_GP0 {1}  \
    CONFIG.PCW_USE_M_AXI_GP1 {0}  \
    CONFIG.PCW_USE_S_AXI_HP0 {0}  \
    CONFIG.PCW_USE_S_AXI_HP1 {0}  \
    CONFIG.PCW_USE_DMA0 {0}  \
    CONFIG.PCW_USE_DMA1 {0}  \
    CONFIG.PCW_FTM_CTI_IN0 {<Select>}  \
    CONFIG.PCW_FTM_CTI_IN1 {<Select>}  \
    CONFIG.PCW_FTM_CTI_IN2 {<Select>}  \
    CONFIG.PCW_FTM_CTI_IN3 {<Select>}  \
    CONFIG.PCW_FTM_CTI_OUT0 {<Select>}  \
    CONFIG.PCW_FTM_CTI_OUT1 {<Select>}  \
    CONFIG.PCW_FTM_CTI_OUT2 {<Select>}  \
    CONFIG.PCW_FTM_CTI_OUT3 {<Select>}  \
    CONFIG.PCW_USE_FABRIC_INTERRUPT {1}  \
    CONFIG.PCW_GPIO_EMIO_GPIO_WIDTH {24}  \
    CONFIG.PCW_S_AXI_HP0_DATA_WIDTH {32}  \
    CONFIG.PCW_EN_QSPI {1}  \
    CONFIG.PCW_EN_GPIO {1}  \
    CONFIG.PCW_EN_I2C0 {1}  \
    CONFIG.PCW_EN_I2C1 {1}  \
    CONFIG.PCW_EN_SDIO0 {0}  \
    CONFIG.PCW_EN_SDIO1 {1}  \
    CONFIG.PCW_EN_SPI0 {0}  \
    CONFIG.PCW_EN_SPI1 {0}  \
    CONFIG.PCW_EN_UART0 {0}  \
    CONFIG.PCW_EN_UART1 {1}  \
    CONFIG.PCW_EN_TTC0 {1}  \
    CONFIG.PCW_EN_TTC1 {0}  \
    CONFIG.PCW_EN_USB0 {1}  \
    CONFIG.PCW_DQ_WIDTH {16}  \
    CONFIG.PCW_DQS_WIDTH {2}  \
    CONFIG.PCW_DM_WIDTH {2}  \
    CONFIG.PCW_MIO_PRIMITIVE {32}  \
    CONFIG.PCW_EN_CLK1_PORT {0}  \
    CONFIG.PCW_EN_CLK2_PORT {0}  \
    CONFIG.PCW_EN_CLK3_PORT {1}  \
    CONFIG.PCW_IRQ_F2P_INTR {1}  \
    CONFIG.PCW_PERIPHERAL_BOARD_PRESET {part0}  \
    CONFIG.PCW_UIPARAM_DDR_MEMORY_TYPE {DDR 3 (Low Voltage)}  \
    CONFIG.PCW_UIPARAM_DDR_BUS_WIDTH {16 Bit}  \
    CONFIG.PCW_UIPARAM_DDR_PARTNO {MT41J256M16 RE-125}  \
    CONFIG.PCW_UIPARAM_DDR_DRAM_WIDTH {16 Bits}  \
    CONFIG.PCW_UIPARAM_DDR_DEVICE_CAPACITY {4096 MBits}  \
    CONFIG.PCW_QSPI_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_QSPI_QSPI_IO {MIO 1 .. 6}  \
    CONFIG.PCW_QSPI_GRP_SINGLE_SS_ENABLE {1}  \
    CONFIG.PCW_QSPI_GRP_SINGLE_SS_IO {MIO 1 .. 6}  \
    CONFIG.PCW_QSPI_GRP_SS1_ENABLE {0}  \
    CONFIG.PCW_SD0_SD0_IO {<Select>}  \
    CONFIG.PCW_SD0_GRP_CD_ENABLE {0}  \
    CONFIG.PCW_SD0_GRP_CD_IO {<Select>}  \
    CONFIG.PCW_SD0_GRP_WP_ENABLE {0}  \
    CONFIG.PCW_SD0_GRP_WP_IO {<Select>}  \
    CONFIG.PCW_SD1_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_SD1_SD1_IO {MIO 10 .. 15}  \
    CONFIG.PCW_SD1_GRP_CD_ENABLE {1}  \
    CONFIG.PCW_SD1_GRP_CD_IO {MIO 0}  \
    CONFIG.PCW_UART0_PERIPHERAL_ENABLE {0}  \
    CONFIG.PCW_UART0_UART0_IO {<Select>}  \
    CONFIG.PCW_UART0_GRP_FULL_ENABLE {0}  \
    CONFIG.PCW_UART1_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_UART1_UART1_IO {MIO 8 .. 9}  \
    CONFIG.PCW_UART1_GRP_FULL_ENABLE {0}  \
    CONFIG.PCW_SPI0_SPI0_IO {<Select>}  \
    CONFIG.PCW_SPI0_GRP_SS0_ENABLE {0}  \
    CONFIG.PCW_SPI0_GRP_SS0_IO {<Select>}  \
    CONFIG.PCW_SPI0_GRP_SS1_ENABLE {0}  \
    CONFIG.PCW_SPI0_GRP_SS1_IO {<Select>}  \
    CONFIG.PCW_SPI0_GRP_SS2_ENABLE {0}  \
    CONFIG.PCW_SPI0_GRP_SS2_IO {<Select>}  \
    CONFIG.PCW_SPI1_SPI1_IO {<Select>}  \
    CONFIG.PCW_SPI1_GRP_SS0_ENABLE {0}  \
    CONFIG.PCW_SPI1_GRP_SS0_IO {<Select>}  \
    CONFIG.PCW_SPI1_GRP_SS1_ENABLE {0}  \
    CONFIG.PCW_SPI1_GRP_SS1_IO {<Select>}  \
    CONFIG.PCW_SPI1_GRP_SS2_ENABLE {0}  \
    CONFIG.PCW_SPI1_GRP_SS2_IO {<Select>}  \
    CONFIG.PCW_TTC0_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_TTC0_TTC0_IO {EMIO}  \
    CONFIG.PCW_TTC1_TTC1_IO {<Select>}  \
    CONFIG.PCW_USB0_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_USB0_USB0_IO {MIO 28 .. 39}  \
    CONFIG.PCW_USB_RESET_ENABLE {1}  \
    CONFIG.PCW_USB_RESET_SELECT {Share reset pin}  \
    CONFIG.PCW_USB0_RESET_ENABLE {1}  \
    CONFIG.PCW_USB0_RESET_IO {MIO 7}  \
    CONFIG.PCW_I2C0_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_I2C0_I2C0_IO {EMIO}  \
    CONFIG.PCW_I2C0_GRP_INT_ENABLE {1}  \
    CONFIG.PCW_I2C0_GRP_INT_IO {EMIO}  \
    CONFIG.PCW_I2C1_PERIPHERAL_ENABLE {1}  \
    CONFIG.PCW_I2C1_I2C1_IO {MIO 48 .. 49}  \
    CONFIG.PCW_I2C1_GRP_INT_ENABLE {1}  \
    CONFIG.PCW_I2C1_GRP_INT_IO {EMIO}  \
    CONFIG.PCW_I2C_RESET_ENABLE {0}  \
    CONFIG.PCW_I2C_RESET_SELECT {<Select>}  \
    CONFIG.PCW_GPIO_MIO_GPIO_ENABLE {1}  \
    CONFIG.PCW_GPIO_MIO_GPIO_IO {MIO}  \
    CONFIG.PCW_GPIO_EMIO_GPIO_ENABLE {1}  \
    CONFIG.PCW_GPIO_EMIO_GPIO_IO {24}  \
    CONFIG.PCW_QSPI_PERIPHERAL_CLKSRC {IO PLL}  \
    CONFIG.PCW_SDIO_PERIPHERAL_CLKSRC {IO PLL}  \
    CONFIG.PCW_FCLK0_PERIPHERAL_CLKSRC {IO PLL}  \
    CONFIG.PCW_FCLK1_PERIPHERAL_CLKSRC {IO PLL}  \
    CONFIG.PCW_FCLK2_PERIPHERAL_CLKSRC {IO PLL}  \
    CONFIG.PCW_ENET0_PERIPHERAL_CLKSRC {External}  \
    CONFIG.PCW_MIO_0_PULLUP {enabled}  \
    CONFIG.PCW_MIO_0_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_0_DIRECTION {in}  \
    CONFIG.PCW_MIO_0_SLEW {slow}  \
    CONFIG.PCW_MIO_1_PULLUP {enabled}  \
    CONFIG.PCW_MIO_1_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_1_DIRECTION {out}  \
    CONFIG.PCW_MIO_1_SLEW {slow}  \
    CONFIG.PCW_MIO_2_PULLUP {disabled}  \
    CONFIG.PCW_MIO_2_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_2_DIRECTION {inout}  \
    CONFIG.PCW_MIO_2_SLEW {slow}  \
    CONFIG.PCW_MIO_3_PULLUP {disabled}  \
    CONFIG.PCW_MIO_3_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_3_DIRECTION {inout}  \
    CONFIG.PCW_MIO_3_SLEW {slow}  \
    CONFIG.PCW_MIO_4_PULLUP {disabled}  \
    CONFIG.PCW_MIO_4_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_4_DIRECTION {inout}  \
    CONFIG.PCW_MIO_4_SLEW {slow}  \
    CONFIG.PCW_MIO_5_PULLUP {disabled}  \
    CONFIG.PCW_MIO_5_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_5_DIRECTION {inout}  \
    CONFIG.PCW_MIO_5_SLEW {slow}  \
    CONFIG.PCW_MIO_6_PULLUP {disabled}  \
    CONFIG.PCW_MIO_6_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_6_DIRECTION {out}  \
    CONFIG.PCW_MIO_6_SLEW {slow}  \
    CONFIG.PCW_MIO_7_PULLUP {disabled}  \
    CONFIG.PCW_MIO_7_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_7_DIRECTION {out}  \
    CONFIG.PCW_MIO_7_SLEW {slow}  \
    CONFIG.PCW_MIO_8_PULLUP {disabled}  \
    CONFIG.PCW_MIO_8_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_8_DIRECTION {out}  \
    CONFIG.PCW_MIO_8_SLEW {slow}  \
    CONFIG.PCW_MIO_9_PULLUP {enabled}  \
    CONFIG.PCW_MIO_9_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_9_DIRECTION {in}  \
    CONFIG.PCW_MIO_9_SLEW {slow}  \
    CONFIG.PCW_MIO_10_PULLUP {disabled}  \
    CONFIG.PCW_MIO_10_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_10_DIRECTION {inout}  \
    CONFIG.PCW_MIO_10_SLEW {slow}  \
    CONFIG.PCW_MIO_11_PULLUP {disabled}  \
    CONFIG.PCW_MIO_11_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_11_DIRECTION {inout}  \
    CONFIG.PCW_MIO_11_SLEW {slow}  \
    CONFIG.PCW_MIO_12_PULLUP {disabled}  \
    CONFIG.PCW_MIO_12_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_12_DIRECTION {inout}  \
    CONFIG.PCW_MIO_12_SLEW {slow}  \
    CONFIG.PCW_MIO_13_PULLUP {disabled}  \
    CONFIG.PCW_MIO_13_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_13_DIRECTION {inout}  \
    CONFIG.PCW_MIO_13_SLEW {slow}  \
    CONFIG.PCW_MIO_14_PULLUP {disabled}  \
    CONFIG.PCW_MIO_14_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_14_DIRECTION {inout}  \
    CONFIG.PCW_MIO_14_SLEW {slow}  \
    CONFIG.PCW_MIO_15_PULLUP {disabled}  \
    CONFIG.PCW_MIO_15_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_15_DIRECTION {inout}  \
    CONFIG.PCW_MIO_15_SLEW {slow}  \
    CONFIG.PCW_MIO_28_PULLUP {enabled}  \
    CONFIG.PCW_MIO_28_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_28_DIRECTION {inout}  \
    CONFIG.PCW_MIO_28_SLEW {slow}  \
    CONFIG.PCW_MIO_29_PULLUP {enabled}  \
    CONFIG.PCW_MIO_29_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_29_DIRECTION {in}  \
    CONFIG.PCW_MIO_29_SLEW {slow}  \
    CONFIG.PCW_MIO_30_PULLUP {enabled}  \
    CONFIG.PCW_MIO_30_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_30_DIRECTION {out}  \
    CONFIG.PCW_MIO_30_SLEW {slow}  \
    CONFIG.PCW_MIO_31_PULLUP {enabled}  \
    CONFIG.PCW_MIO_31_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_31_DIRECTION {in}  \
    CONFIG.PCW_MIO_31_SLEW {slow}  \
    CONFIG.PCW_MIO_32_PULLUP {enabled}  \
    CONFIG.PCW_MIO_32_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_32_DIRECTION {inout}  \
    CONFIG.PCW_MIO_32_SLEW {slow}  \
    CONFIG.PCW_MIO_33_PULLUP {enabled}  \
    CONFIG.PCW_MIO_33_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_33_DIRECTION {inout}  \
    CONFIG.PCW_MIO_33_SLEW {slow}  \
    CONFIG.PCW_MIO_34_PULLUP {enabled}  \
    CONFIG.PCW_MIO_34_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_34_DIRECTION {inout}  \
    CONFIG.PCW_MIO_34_SLEW {slow}  \
    CONFIG.PCW_MIO_35_PULLUP {enabled}  \
    CONFIG.PCW_MIO_35_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_35_DIRECTION {inout}  \
    CONFIG.PCW_MIO_35_SLEW {slow}  \
    CONFIG.PCW_MIO_36_PULLUP {enabled}  \
    CONFIG.PCW_MIO_36_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_36_DIRECTION {in}  \
    CONFIG.PCW_MIO_36_SLEW {slow}  \
    CONFIG.PCW_MIO_37_PULLUP {enabled}  \
    CONFIG.PCW_MIO_37_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_37_DIRECTION {inout}  \
    CONFIG.PCW_MIO_37_SLEW {slow}  \
    CONFIG.PCW_MIO_38_PULLUP {enabled}  \
    CONFIG.PCW_MIO_38_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_38_DIRECTION {inout}  \
    CONFIG.PCW_MIO_38_SLEW {slow}  \
    CONFIG.PCW_MIO_39_PULLUP {enabled}  \
    CONFIG.PCW_MIO_39_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_39_DIRECTION {inout}  \
    CONFIG.PCW_MIO_39_SLEW {slow}  \
    CONFIG.PCW_MIO_48_PULLUP {enabled}  \
    CONFIG.PCW_MIO_48_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_48_DIRECTION {inout}  \
    CONFIG.PCW_MIO_48_SLEW {slow}  \
    CONFIG.PCW_MIO_49_PULLUP {enabled}  \
    CONFIG.PCW_MIO_49_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_49_DIRECTION {inout}  \
    CONFIG.PCW_MIO_49_SLEW {slow}  \
    CONFIG.PCW_MIO_52_PULLUP {enabled}  \
    CONFIG.PCW_MIO_52_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_52_DIRECTION {inout}  \
    CONFIG.PCW_MIO_52_SLEW {slow}  \
    CONFIG.PCW_MIO_53_PULLUP {enabled}  \
    CONFIG.PCW_MIO_53_IOTYPE {LVCMOS 3.3V}  \
    CONFIG.PCW_MIO_53_DIRECTION {inout}  \
    CONFIG.PCW_MIO_53_SLEW {slow}  \
    CONFIG.PCW_UIPARAM_GENERATE_SUMMARY {NONE}  \
    CONFIG.PCW_MIO_TREE_PERIPHERALS {SD 1#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#Quad SPI Flash#USB Reset#UART 1#UART 1#SD 1#SD 1#SD 1#SD 1#SD 1#SD 1#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#USB 0#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#I2C 1#I2C 1#Unbonded#Unbonded#GPIO#GPIO}  \
    CONFIG.PCW_MIO_TREE_SIGNALS {cd#qspi0_ss_b#qspi0_io[0]#qspi0_io[1]#qspi0_io[2]#qspi0_io[3]#qspi0_sclk#reset#tx#rx#data[0]#cmd#clk#data[1]#data[2]#data[3]#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#data[4]#dir#stp#nxt#data[0]#data[1]#data[2]#data[3]#clk#data[5]#data[6]#data[7]#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#Unbonded#scl#sda#Unbonded#Unbonded#gpio[52]#gpio[53]}  \
    CONFIG.PCW_FPGA_FCLK1_ENABLE {0}  \
    CONFIG.PCW_FPGA_FCLK2_ENABLE {0}  \
    CONFIG.PCW_FPGA_FCLK3_ENABLE {0}  \
    CONFIG.PCW_PACKAGE_NAME {clg225}  \
  ] [get_bd_cells processing_system7_0]
endgroup

startgroup
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" Master "Disable" Slave "Disable" }  [get_bd_cells processing_system7_0]
endgroup

# BRAM 0
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_0
set_property -dict [list CONFIG.SINGLE_PORT_BRAM {1}] [get_bd_cells axi_bram_ctrl_0]
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "New Blk_Mem_Gen" }  [get_bd_intf_pins axi_bram_ctrl_0/BRAM_PORTA]
set_property -dict [list CONFIG.Memory_Type {True_Dual_Port_RAM} \
CONFIG.Enable_B {Use_ENB_Pin} \
CONFIG.Use_RSTB_Pin {true} \
CONFIG.Port_B_Clock {100} \
CONFIG.Port_B_Write_Rate {50} \
CONFIG.Port_B_Enable_Rate {100}] [get_bd_cells axi_bram_ctrl_0_bram]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" \
intc_ip "Auto" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins axi_bram_ctrl_0/S_AXI]
set_property range 4K [get_bd_addr_segs {processing_system7_0/Data/SEG_axi_bram_ctrl_0_Mem0}]
set_property -dict [list CONFIG.PROTOCOL {AXI4LITE} CONFIG.SINGLE_PORT_BRAM {1} CONFIG.ECC_TYPE {0}] [get_bd_cells axi_bram_ctrl_0]
set_property -dict [list CONFIG.Assume_Synchronous_Clk {true}] [get_bd_cells axi_bram_ctrl_0_bram]
endgroup

# BRAM 1
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_1
set_property -dict [list CONFIG.SINGLE_PORT_BRAM {1}] [get_bd_cells axi_bram_ctrl_1]
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "New Blk_Mem_Gen" }  [get_bd_intf_pins axi_bram_ctrl_1/BRAM_PORTA]
set_property -dict [list CONFIG.Memory_Type {True_Dual_Port_RAM} \
CONFIG.Enable_B {Use_ENB_Pin} \
CONFIG.Use_RSTB_Pin {true} \
CONFIG.Port_B_Clock {100} \
CONFIG.Port_B_Write_Rate {50} \
CONFIG.Port_B_Enable_Rate {100}] [get_bd_cells axi_bram_ctrl_1_bram]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" \
intc_ip "Auto" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins axi_bram_ctrl_1/S_AXI]
set_property range 4K [get_bd_addr_segs {processing_system7_0/Data/SEG_axi_bram_ctrl_1_Mem0}]
set_property -dict [list CONFIG.PROTOCOL {AXI4LITE} CONFIG.SINGLE_PORT_BRAM {1} CONFIG.ECC_TYPE {0}] [get_bd_cells axi_bram_ctrl_1]
set_property -dict [list CONFIG.Assume_Synchronous_Clk {true}] [get_bd_cells axi_bram_ctrl_1_bram]
endgroup

# BRAM 2
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_2
set_property -dict [list CONFIG.SINGLE_PORT_BRAM {1}] [get_bd_cells axi_bram_ctrl_2]
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "New Blk_Mem_Gen" }  [get_bd_intf_pins axi_bram_ctrl_2/BRAM_PORTA]
set_property -dict [list CONFIG.Memory_Type {True_Dual_Port_RAM} \
CONFIG.Enable_B {Use_ENB_Pin} \
CONFIG.Use_RSTB_Pin {true} \
CONFIG.Port_B_Clock {100} \
CONFIG.Port_B_Write_Rate {50} \
CONFIG.Port_B_Enable_Rate {100}] [get_bd_cells axi_bram_ctrl_2_bram]
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Master "/processing_system7_0/M_AXI_GP0" \
intc_ip "/axi_smc" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins axi_bram_ctrl_2/S_AXI]
set_property range 4K [get_bd_addr_segs {processing_system7_0/Data/SEG_axi_bram_ctrl_2_Mem0}]
set_property -dict [list CONFIG.PROTOCOL {AXI4LITE} CONFIG.SINGLE_PORT_BRAM {1} CONFIG.ECC_TYPE {0}] [get_bd_cells axi_bram_ctrl_2]
set_property -dict [list CONFIG.Assume_Synchronous_Clk {true}] [get_bd_cells axi_bram_ctrl_2_bram]

endgroup

#
startgroup
create_bd_cell -type ip -vlnv xilinx.com:ip:jtag_axi:1.2 jtag_axi_0
apply_bd_automation -rule xilinx.com:bd_rule:axi4 -config {Slave "/axi_bram_ctrl_0/S_AXI" intc_ip "/axi_smc" Clk_xbar "Auto" Clk_master "Auto" Clk_slave "Auto" }  [get_bd_intf_pins jtag_axi_0/M_AXI]
endgroup

set_property  ip_repo_paths  {../../../../iplib/} [current_project]
update_ip_catalog
create_bd_cell -type ip -vlnv xilinx.com:hls:phasegen:1.0 phasegen_0
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "/axi_bram_ctrl_0_bram" }  [get_bd_intf_pins phasegen_0/params_V_PORTA]

create_bd_cell -type ip -vlnv xilinx.com:hls:nco:1.0 nco_0
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "/axi_bram_ctrl_1_bram" }  [get_bd_intf_pins nco_0/params_V_PORTA]

create_bd_cell -type ip -vlnv xilinx.com:hls:datadevnull:1.0 datadevnull_0
apply_bd_automation -rule xilinx.com:bd_rule:bram_cntlr -config {BRAM "/axi_bram_ctrl_2_bram" }  [get_bd_intf_pins datadevnull_0/params_V_PORTA]

connect_bd_net [get_bd_pins processing_system7_0/FCLK_CLK0] [get_bd_pins phasegen_0/ap_clk]
connect_bd_net [get_bd_pins rst_ps7_0_100M/peripheral_aresetn] [get_bd_pins phasegen_0/ap_rst_n]

connect_bd_net [get_bd_pins processing_system7_0/FCLK_CLK0] [get_bd_pins datadevnull_0/ap_clk]
connect_bd_net [get_bd_pins rst_ps7_0_100M/peripheral_aresetn] [get_bd_pins datadevnull_0/ap_rst_n]

connect_bd_net [get_bd_pins processing_system7_0/FCLK_CLK0] [get_bd_pins nco_0/ap_clk]
connect_bd_net [get_bd_pins rst_ps7_0_100M/peripheral_aresetn] [get_bd_pins nco_0/ap_rst_n]

connect_bd_intf_net [get_bd_intf_pins phasegen_0/outval_V] [get_bd_intf_pins nco_0/phasein_V]
connect_bd_intf_net [get_bd_intf_pins nco_0/dataout_V] [get_bd_intf_pins datadevnull_0/inv_V]

regenerate_bd_layout
regenerate_bd_layout -routing

make_wrapper -files [get_files ./nco/nco.srcs/sources_1/bd/nco_1/nco_1.bd] -top
add_files -norecurse ./nco/nco.srcs/sources_1/bd/nco_1/hdl/nco_1_wrapper.v

# start synthesis
launch_runs synth_1 -jobs 4
wait_on_run -timeout 30 synth_1

# set debug probe
open_run synth_1 -name synth_1

set_property mark_debug true [get_nets [list {nco_1_i/phasegen_0/outval_V_TDATA[4]} {nco_1_i/phasegen_0/outval_V_TDATA[0]} {nco_1_i/phasegen_0/outval_V_TDATA[11]} {nco_1_i/phasegen_0/outval_V_TDATA[13]} {nco_1_i/phasegen_0/outval_V_TDATA[15]} {nco_1_i/phasegen_0/outval_V_TDATA[17]} {nco_1_i/phasegen_0/outval_V_TDATA[18]} {nco_1_i/phasegen_0/outval_V_TDATA[16]} {nco_1_i/phasegen_0/outval_V_TDATA[14]} {nco_1_i/phasegen_0/outval_V_TDATA[12]} {nco_1_i/phasegen_0/outval_V_TDATA[1]} {nco_1_i/phasegen_0/outval_V_TDATA[2]} nco_1_i/phasegen_0/outval_V_TREADY nco_1_i/phasegen_0/outval_V_TVALID {nco_1_i/phasegen_0/outval_V_TDATA[3]} {nco_1_i/phasegen_0/outval_V_TDATA[5]} {nco_1_i/phasegen_0/outval_V_TDATA[6]} {nco_1_i/phasegen_0/outval_V_TDATA[7]} {nco_1_i/phasegen_0/outval_V_TDATA[8]} {nco_1_i/phasegen_0/outval_V_TDATA[27]} {nco_1_i/phasegen_0/outval_V_TDATA[29]} {nco_1_i/phasegen_0/outval_V_TDATA[31]} {nco_1_i/phasegen_0/outval_V_TDATA[30]} {nco_1_i/phasegen_0/outval_V_TDATA[28]} {nco_1_i/phasegen_0/outval_V_TDATA[19]} {nco_1_i/phasegen_0/outval_V_TDATA[21]} {nco_1_i/phasegen_0/outval_V_TDATA[23]} {nco_1_i/phasegen_0/outval_V_TDATA[25]} {nco_1_i/phasegen_0/outval_V_TDATA[26]} {nco_1_i/phasegen_0/outval_V_TDATA[24]} {nco_1_i/phasegen_0/outval_V_TDATA[22]} {nco_1_i/phasegen_0/outval_V_TDATA[20]} {nco_1_i/phasegen_0/outval_V_TDATA[9]} {nco_1_i/phasegen_0/outval_V_TDATA[10]}]]
set_property mark_debug true [get_nets [list {nco_1_i/nco_0/dataout_V_TDATA[2]} {nco_1_i/nco_0/dataout_V_TDATA[0]} nco_1_i/nco_0/dataout_V_TVALID {nco_1_i/nco_0/dataout_V_TDATA[1]} {nco_1_i/nco_0/dataout_V_TDATA[3]} {nco_1_i/nco_0/dataout_V_TDATA[16]} {nco_1_i/nco_0/dataout_V_TDATA[17]} {nco_1_i/nco_0/dataout_V_TDATA[14]} {nco_1_i/nco_0/dataout_V_TDATA[15]} {nco_1_i/nco_0/dataout_V_TDATA[12]} {nco_1_i/nco_0/dataout_V_TDATA[13]} {nco_1_i/nco_0/dataout_V_TDATA[4]} {nco_1_i/nco_0/dataout_V_TDATA[5]} {nco_1_i/nco_0/dataout_V_TDATA[6]} {nco_1_i/nco_0/dataout_V_TDATA[7]} {nco_1_i/nco_0/dataout_V_TDATA[26]} {nco_1_i/nco_0/dataout_V_TDATA[28]} {nco_1_i/nco_0/dataout_V_TDATA[30]} {nco_1_i/nco_0/dataout_V_TDATA[31]} {nco_1_i/nco_0/dataout_V_TDATA[29]} {nco_1_i/nco_0/dataout_V_TDATA[27]} {nco_1_i/nco_0/dataout_V_TDATA[18]} {nco_1_i/nco_0/dataout_V_TDATA[20]} {nco_1_i/nco_0/dataout_V_TDATA[22]} {nco_1_i/nco_0/dataout_V_TDATA[24]} {nco_1_i/nco_0/dataout_V_TDATA[25]} {nco_1_i/nco_0/dataout_V_TDATA[23]} {nco_1_i/nco_0/dataout_V_TDATA[21]} {nco_1_i/nco_0/dataout_V_TDATA[19]} {nco_1_i/nco_0/dataout_V_TDATA[8]} {nco_1_i/nco_0/dataout_V_TDATA[9]} {nco_1_i/nco_0/dataout_V_TDATA[10]} {nco_1_i/nco_0/dataout_V_TDATA[11]} nco_1_i/nco_0/dataout_V_TREADY]]

create_debug_core u_ila_0 ila
set_property C_DATA_DEPTH 2048 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
set_property port_width 1 [get_debug_ports u_ila_0/clk]
connect_debug_port u_ila_0/clk [get_nets [list nco_1_i/processing_system7_0/inst/FCLK_CLK0 ]]
set_property port_width 32 [get_debug_ports u_ila_0/probe0]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list {nco_1_i/phasegen_0/outval_V_TDATA[0]} {nco_1_i/phasegen_0/outval_V_TDATA[1]} {nco_1_i/phasegen_0/outval_V_TDATA[2]} {nco_1_i/phasegen_0/outval_V_TDATA[3]} {nco_1_i/phasegen_0/outval_V_TDATA[4]} {nco_1_i/phasegen_0/outval_V_TDATA[5]} {nco_1_i/phasegen_0/outval_V_TDATA[6]} {nco_1_i/phasegen_0/outval_V_TDATA[7]} {nco_1_i/phasegen_0/outval_V_TDATA[8]} {nco_1_i/phasegen_0/outval_V_TDATA[9]} {nco_1_i/phasegen_0/outval_V_TDATA[10]} {nco_1_i/phasegen_0/outval_V_TDATA[11]} {nco_1_i/phasegen_0/outval_V_TDATA[12]} {nco_1_i/phasegen_0/outval_V_TDATA[13]} {nco_1_i/phasegen_0/outval_V_TDATA[14]} {nco_1_i/phasegen_0/outval_V_TDATA[15]} {nco_1_i/phasegen_0/outval_V_TDATA[16]} {nco_1_i/phasegen_0/outval_V_TDATA[17]} {nco_1_i/phasegen_0/outval_V_TDATA[18]} {nco_1_i/phasegen_0/outval_V_TDATA[19]} {nco_1_i/phasegen_0/outval_V_TDATA[20]} {nco_1_i/phasegen_0/outval_V_TDATA[21]} {nco_1_i/phasegen_0/outval_V_TDATA[22]} {nco_1_i/phasegen_0/outval_V_TDATA[23]} {nco_1_i/phasegen_0/outval_V_TDATA[24]} {nco_1_i/phasegen_0/outval_V_TDATA[25]} {nco_1_i/phasegen_0/outval_V_TDATA[26]} {nco_1_i/phasegen_0/outval_V_TDATA[27]} {nco_1_i/phasegen_0/outval_V_TDATA[28]} {nco_1_i/phasegen_0/outval_V_TDATA[29]} {nco_1_i/phasegen_0/outval_V_TDATA[30]} {nco_1_i/phasegen_0/outval_V_TDATA[31]} ]]
create_debug_port u_ila_0 probe
set_property port_width 32 [get_debug_ports u_ila_0/probe1]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list {nco_1_i/nco_0/dataout_V_TDATA[0]} {nco_1_i/nco_0/dataout_V_TDATA[1]} {nco_1_i/nco_0/dataout_V_TDATA[2]} {nco_1_i/nco_0/dataout_V_TDATA[3]} {nco_1_i/nco_0/dataout_V_TDATA[4]} {nco_1_i/nco_0/dataout_V_TDATA[5]} {nco_1_i/nco_0/dataout_V_TDATA[6]} {nco_1_i/nco_0/dataout_V_TDATA[7]} {nco_1_i/nco_0/dataout_V_TDATA[8]} {nco_1_i/nco_0/dataout_V_TDATA[9]} {nco_1_i/nco_0/dataout_V_TDATA[10]} {nco_1_i/nco_0/dataout_V_TDATA[11]} {nco_1_i/nco_0/dataout_V_TDATA[12]} {nco_1_i/nco_0/dataout_V_TDATA[13]} {nco_1_i/nco_0/dataout_V_TDATA[14]} {nco_1_i/nco_0/dataout_V_TDATA[15]} {nco_1_i/nco_0/dataout_V_TDATA[16]} {nco_1_i/nco_0/dataout_V_TDATA[17]} {nco_1_i/nco_0/dataout_V_TDATA[18]} {nco_1_i/nco_0/dataout_V_TDATA[19]} {nco_1_i/nco_0/dataout_V_TDATA[20]} {nco_1_i/nco_0/dataout_V_TDATA[21]} {nco_1_i/nco_0/dataout_V_TDATA[22]} {nco_1_i/nco_0/dataout_V_TDATA[23]} {nco_1_i/nco_0/dataout_V_TDATA[24]} {nco_1_i/nco_0/dataout_V_TDATA[25]} {nco_1_i/nco_0/dataout_V_TDATA[26]} {nco_1_i/nco_0/dataout_V_TDATA[27]} {nco_1_i/nco_0/dataout_V_TDATA[28]} {nco_1_i/nco_0/dataout_V_TDATA[29]} {nco_1_i/nco_0/dataout_V_TDATA[30]} {nco_1_i/nco_0/dataout_V_TDATA[31]} ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe2]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list nco_1_i/nco_0/dataout_V_TREADY ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe3]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list nco_1_i/nco_0/dataout_V_TVALID ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe4]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe4]
connect_debug_port u_ila_0/probe4 [get_nets [list nco_1_i/phasegen_0/outval_V_TREADY ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe5]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe5]
connect_debug_port u_ila_0/probe5 [get_nets [list nco_1_i/phasegen_0/outval_V_TVALID ]]

# save constraints
file mkdir ./nco/nco.srcs/constrs_1/
close [ open ./nco/nco.srcs/constrs_1/constraint_1.xdc w ]
add_files -fileset constrs_1 ./nco/nco.srcs/constrs_1/constraint_1.xdc
set_property target_constrs_file ./nco/nco.srcs/constrs_1/constraint_1.xdc [current_fileset -constrset]
save_constraints -force

# implementation
reset_run synth_1
set_property strategy Performance_Explore [get_runs impl_1]
launch_runs synth_1 -jobs 4
wait_on_run -timeout 30 synth_1
# launch_runs impl_1 -jobs 4
# wait_on_run -timeout 30 impl_1

# bitstream
launch_runs impl_1 -to_step write_bitstream -jobs 4
wait_on_run -timeout 30 impl_1

file mkdir ./nco/nco.sdk
file copy -force ./nco/nco.runs/impl_1/nco_1_wrapper.sysdef ./nco/nco.sdk/nco_1_wrapper.hdf

close_project
exit
