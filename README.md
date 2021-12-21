:floppy_disk: `miyo-firmware`
=============================

#### Build firmware with `cmake` and `make`
```bash
mkdir build && cd build
cmake ..
make -j8
```
#### Upload firmware with `OpenOCD`
```bash
openocd -f interface/stlink.cfg -c "transport select hla_swd" -f target/stm32l4x.cfg 
```
```bash
(gdb) quit
arm-none-eabi-gdb bin/miyo-reader-firmware 
(gdb) target remote localhost:3333
(gdb) monitor reset halt
(gdb) load
(gdb) continue
```
