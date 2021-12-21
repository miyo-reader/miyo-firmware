:floppy_disk: `miyo-firmware`
=============================
[![Spell Check status](https://github.com/miyo-reader/miyo-firmware/actions/workflows/spell-check-task.yml/badge.svg)](https://github.com/miyo-reader/miyo-firmware/actions/workflows/spell-check-task.yml)

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
arm-none-eabi-gdb bin/miyo-reader-firmware 
(gdb) target remote localhost:3333
(gdb) monitor reset halt
(gdb) load
(gdb) continue
```
