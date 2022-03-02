<a href="https://miyo-reader.io/"><img align="right" src="https://raw.githubusercontent.com/miyo-reader/.github/main/logo/miyo-horizontal-1501x700.png" width="25%"></a>
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
make upload
```
