# phasegen
set currdir [pwd]
open_project phasegen
set_top phasegen
add_files $currdir/./typedef.h
add_files $currdir/./define.h
add_files $currdir/./phasegen.cpp
open_solution "zybe"
set_part {xczu3eg-sbva484-1-i}
create_clock -period 4 -name default
csynth_design
export_design -flow impl -rtl verilog -format ip_catalog
close_project
