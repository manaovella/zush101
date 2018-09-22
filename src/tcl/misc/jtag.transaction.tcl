# reset jtag-axi debug core
reset_hw_axi [get_hw_axis hw_axi_1]

# AXI4 Example ------
# Create a write AXI burst transaction with eight 32-bit data:
create_hw_axi_txn wr_txn [get_hw_axis hw_axi_1] -address 00000000 -data {11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888} -len 8 -size 32 -type write

# Create a read AXI burst transaction with eight 32-bit data:
create_hw_axi_txn rd_txn [get_hw_axis hw_axi_1] -address 00000000 -len 8 -size 32 -type read

# Create a write AXI burst transaction with eight 32-bit data and 64 bit address:
create_hw_axi_txn wr_txn64 [get_hw_axis hw_axi_1] -address 0000000000000000 -data {11111111_22222222_33333333_44444444_55555555_66666666_77777777_88888888} -len 8 -size 32 -type write

# Create a read AXI burst transaction with eight 32-bit data and 64 bit address:
create_hw_axi_txn rd_txn64 [get_hw_axis hw_axi_1] -address 0000000000000000 -len 8 -size 32-type read

# AXI4-Lite Example ------
# Create a write AXI burst transaction with eight 32-bit data:
create_hw_axi_txn wr_txn_lite [get_hw_axis hw_axi_1] -address 00000000 -data 12345678 -type write

# Create a read AXI burst transaction with eight 32-bit data:
create_hw_axi_txn rd_txn_lite [get_hw_axis hw_axi_1] -address 00000000 -type read

# execute transaction
run_hw_axi txn_1 txn_2 txn_3 txn_4 -queue

# syntax:
# Create a hardware AXI transaction object where:
#  create_hw_axi_txn  [-address <arg>] [-data <arg>] [-size <arg>] -type <arg>
#                     [-len <arg>] [-burst <arg>] [-cache <arg>] [-id <arg>]
#                     [-quiet] [-verbose] <name> <hw_axi>
#
#  run_hw_axi  [-queue] [-quiet] [-verbose] <hw_axi_txns>...

#
report_hw_axi_txn [get_hw_axi_txns read_txn]

#
report_property [get_hw_axi_txns read_txn]



#####
reset_hw_axi [get_hw_axis hw_axi_1]
create_hw_axi_txn wr_txn_lite1 [get_hw_axis hw_axi_1] -address 40000000 -data 0000FFFF -type write -force
create_hw_axi_txn wr_txn_lite2 [get_hw_axis hw_axi_1] -address 42000000 -data 0000FFFF -type write -force
create_hw_axi_txn rd_txn_lite [get_hw_axis hw_axi_1] -address 00000000 -type read
run_hw_axi txn_1 txn_2 txn_3 txn_4 -queue
run_hw_axi wr_txn_lite

#
create_hw_axi_txn wr_txn_litea [get_hw_axis hw_axi_1] -address 00000000 -data 0000FFFF -type write -force
create_hw_axi_txn wr_txn_liteb [get_hw_axis hw_axi_1] -address 00000001 -data 0000FFFF -type write -force
create_hw_axi_txn wr_txn_litec [get_hw_axis hw_axi_1] -address 00000002 -data 0000FFFF -type write -force
create_hw_axi_txn wr_txn_lited [get_hw_axis hw_axi_1] -address 00000003 -data 0000FFFF -type write -force
create_hw_axi_txn wr_txn_litee [get_hw_axis hw_axi_1] -address 00000004 -data 0000FFFF -type write -force

# example
reset_hw_axi [get_hw_axis hw_axi_1]
create_hw_axi_txn wr_txn_lite [get_hw_axis hw_axi_1] -address 42000000 -data 0000FFFF -type write -force
run_hw_axi wr_txn_lite