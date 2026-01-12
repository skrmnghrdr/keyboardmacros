The C file in this folder is to be replaced on wherever that keymap.c lives, 
we also have delted the process_record_user() on keyboard.h or c, whichever to fix the error and let it compile

DO NOT FORGET TO ENABLE YOUR SELECT ALL MACROS ON THE VIA since control a is replaced.
This is similar to the macros found on 
https://github.com/skrmnghrdr/keyboardmacros/blob/main/Capslock%20as%20function.ahk

with some limitations to it

https://github.com/Enilenis/CIDOO-QK61

on this github repo above, 
https://github.com/Enilenis/CIDOO-QK61/tree/main/keyboards/cidoo/qk61/keymaps/via

here was the via folder located, overwrite the contents of that, and follow the compilation walkthrough on the repository. 

It should be good
hold esc and plug the keyboard to your computer
a directory (like a flash drive would appear)
drag and drop the .bin over there and it would install automatically

*profit?


Instructions from https://github.com/Enilenis/CIDOO-QK61/tree/main

pasted here for convenience:

CIDOO QK61
A customizable 61key keyboard.

Keyboard Maintainer: CIDOO
Hardware Supported: CIDOO QK61 PCB with es32fs026 (fs026) microcontroller
Make example for this keyboard (after setting up your build environment):

make cidoo/qk61:via
See the build environment setup and the make instructions for more information. Brand new to QMK? Start with our Complete Newbs Guide.

Firmware
To flash firmware, enter bootloader mode by holding the Esc key (matrix position 0,0) while plugging in the keyboard.
Place compiled .bin file onto the keyboard’s USB storage — the device will automatically reboot and apply the new firmware.
