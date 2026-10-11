# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Workspace\zynq7000_driver\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Workspace\zynq7000_driver\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {zynq7000_driver}\
-hw {C:\Users\phanm\OneDrive\Documents\zynq7000\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {D:/Workspace}

platform write
platform generate -domains 
platform active {zynq7000_driver}
platform generate
catch {platform remove zynq7000}
bsp reload
bsp reload
bsp reload
bsp reload
domain active {zynq_fsbl}
bsp reload
bsp reload
domain active {standalone_domain}
bsp setlib -name lwip213 -ver 1.1
bsp setlib -name xilffs -ver 5.1
bsp write
bsp reload
catch {bsp regenerate}
platform generate
platform generate -domains standalone_domain 
platform active {zynq7000_driver}
bsp reload
bsp config use_mkfs "false"
bsp config use_lfn "1"
bsp config num_logical_vol "2"
bsp config read_only "true"
bsp write
bsp reload
catch {bsp regenerate}
platform generate
platform config -updatehw {C:/Users/phanm/OneDrive/Documents/zynq7000/design_1_wrapper.xsa}
platform generate
platform clean
platform generate
