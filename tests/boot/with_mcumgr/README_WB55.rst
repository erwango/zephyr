MCUmgr use case with nucleo_wb55rg
##################################


# Install mcumgr:
$ go install github.com/apache/mynewt-mcumgr-cli/mcumgr@latest
$ export PATH=~/go/bin/:$PATH

# Build and flash sample:
$ west build -p always --sysbuild -b nucleo_wb55rg  tests/boot/with_mcumgr/ -DSB_CONFIG_BOOTLOADER_MCUBOOT=y
$ west flash

Target console output:
      *** Using Zephyr OS build v3.7.0-680-g9ff712620783 ***
      I: Starting bootloader
      I: Primary image: magic=good, swap_type=0x4, copy_done=0x1, image_ok=0x1
      I: Secondary image: magic=good, swap_type=0x2, copy_done=0x3, image_ok=0x3
      I: Boot source: none
      I: Image index: 0, Swap type: test
      I: Starting swap using move algorithm.
      I: Bootloader chainload address offset: 0xc000
      I: Jumping to the first image slot
      *** Booting Zephyr OS build v3.7.0-680-g9ff712620783 ***
      Launching primary slot application on nucleo_wb55rg
      Build time: Aug  8 2024 15:42:10

# Build a new application firmware (timestamping ensures a different fw is generated)
$ west build -p always --sysbuild -b nucleo_wb55rg  tests/boot/with_mcumgr/ -DSB_CONFIG_BOOTLOADER_MCUBOOT=y

# Sign the new fw
$ west sign -t imgtool -d build/with_mcumgr/  -- --key ../bootloader/mcuboot/root-rsa-2048.pem

# Upload application firmware using mcumgr
$ mcumgr --conntype serial --connstring "/dev/ttyACM0,baud=115200" image upload build/with_mcumgr/zephyr/zephyr.signed.bin

# Verify new fw is available on target
$ mcumgr --conntype serial --connstring "/dev/ttyACM0,baud=115200" image list
Images:
 image=0 slot=0
    version: 0.0.0
    bootable: true
    flags: active confirmed
    hash: fa0ce99fdc4d31f6f268996b950f99438ea77d3414898b92bde3568d8b285b95
 image=0 slot=1
    version: 0.0.0
    bootable: true
    flags:
    hash: 7438bb5803ef5fa80f27c5b8c7181595cc6e34e7f71ab81688bcd9fcc3b3d53e
Split status: N/A (0)

# Instruct mcumgr to run the new fw
$ mcumgr --conntype serial --connstring "/dev/ttyACM0,baud=115200" image test 7438bb5803ef5fa80f27c5b8c7181595cc6e34e7f71ab81688bcd9fcc3b3d53e
Images:
 image=0 slot=0
    version: 0.0.0
    bootable: true
    flags: active confirmed
    hash: fa0ce99fdc4d31f6f268996b950f99438ea77d3414898b92bde3568d8b285b95
 image=0 slot=1
    version: 0.0.0
    bootable: true
    flags: pending
    hash: 7438bb5803ef5fa80f27c5b8c7181595cc6e34e7f71ab81688bcd9fcc3b3d53e
Split status: N/A (0)

# Reset the target to get MCUBoot swap both fw and run the new image
$ mcumgr --conntype serial --connstring "/dev/ttyACM0,baud=115200" reset
# Verify images have been swapped
$ mcumgr --conntype serial --connstring "/dev/ttyACM0,baud=115200" image list
Images:
 image=0 slot=0
    version: 0.0.0
    bootable: true
    flags: active
    hash: 7438bb5803ef5fa80f27c5b8c7181595cc6e34e7f71ab81688bcd9fcc3b3d53e
 image=0 slot=1
    version: 0.0.0
    bootable: true
    flags: confirmed
    hash: fa0ce99fdc4d31f6f268996b950f99438ea77d3414898b92bde3568d8b285b95
Split status: N/A (0)

Check target console output:
      *** Using Zephyr OS build v3.7.0-680-g9ff712620783 ***
      I: Starting bootloader
      I: Primary image: magic=good, swap_type=0x4, copy_done=0x1, image_ok=0x1
      I: Secondary image: magic=good, swap_type=0x2, copy_done=0x3, image_ok=0x3
      I: Boot source: none
      I: Image index: 0, Swap type: test
      I: Starting swap using move algorithm.
      I: Bootloader chainload address offset: 0xc000
      I: Jumping to the first image slot
      *** Booting Zephyr OS build v3.7.0-680-g9ff712620783 ***
      Launching primary slot application on nucleo_wb55rg
      Build time: Aug  8 2024 15:44:25



Note:
Twister command to run test automatically:

twister --west-flash -vvv -N --device-testing --enable-slow --hardware-map ../map.yaml -T tests/boot/with_mcumgr/
