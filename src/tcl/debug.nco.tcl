set currwd [pwd]
open_project $currwd/nco/nco.xpr

# sdk
launch_sdk -workspace $currwd/nco/nco.sdk -hwspec $currwd/nco/nco.sdk/nco_1_wrapper.hdf

# hw manager
# start_gui
# open_hw
# connect_hw_server
