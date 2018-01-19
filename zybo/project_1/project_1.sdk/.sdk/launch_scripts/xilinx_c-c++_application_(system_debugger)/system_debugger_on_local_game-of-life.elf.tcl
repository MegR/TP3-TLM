connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Zybo 210279573046A"} -index 1
loadhw /user/5/.base/ruffiotm/home/Documents/3A/TLM/cours-tlm/TPs/squelette/tp3/zybo/project_1/project_1.sdk/design_1_wrapper_hw_platform_0/system.hdf
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Zybo 210279573046A"} -index 1
rst -processor
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Zybo 210279573046A"} -index 1
dow /user/5/.base/ruffiotm/home/Documents/3A/TLM/cours-tlm/TPs/squelette/tp3/zybo/project_1/project_1.sdk/game-of-life/Debug/game-of-life.elf
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Zybo 210279573046A"} -index 1
con
