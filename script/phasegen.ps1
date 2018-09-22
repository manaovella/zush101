del *.log
Remove-Item -recurse -Force .\.build\testphasegen\
mkdir .\.build
mkdir .\.build\testphasegen
cd .\.build\testphasegen
C:\Xilinx\Vivado\2017.2\bin\vivado.bat -mode tcl -source ../../phasegen.tcl