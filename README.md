# MicroZed-with-Leaky-Integrated-Fire
A demo of Leaky Integrated and Fire neuron on FPGA (MicroZed).
The verilog code of LIF core can be found here: [NASH.v](./ip_repo/NASH_SYSTEM_1.0/src/NASH.v)

# Requirements
This project is designed for Vivado 2016.4 and MicroZed 7Z010

# How to run

1. Modify the path to Vivado 2016.4 in `build.bat` as your installation path.
2. Double click to `build.bat` (or execute it via command).
3. Check the file `vivado.log` to ensure the correctness of project.
4. Open the Project at `MicroZed_NASH_SYSTEM/MicroZed_NASH_SYSTEM.xpr`.
5. Generate bitstream and export to SDK.
6. Test C code is in  `src/NASH_SYSTEM_LIF_neuron_test.c`.
7. Implement the system to MicroZed.


# Output (UART)
![Image of UART](screenshot.png)
