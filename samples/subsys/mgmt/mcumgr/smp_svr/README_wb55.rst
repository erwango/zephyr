.. zephyr:code-sample:: smp-svr
   :name: SMP server

   Implement a Simple Management Protocol (SMP) server.

Update for nucleo_wb55rg
************************

Build and flash
.. code-block:: console

  west build -p always --sysbuild -b nucleo_wb55rg samples/subsys/mgmt/mcumgr/smp_svr/ \
  -DEXTRA_CONF_FILE='overlay-shell.conf;overlay-fs.conf' -DSB_CONFIG_BOOTLOADER_MCUBOOT=y
  west flash

Build new image:
.. code-block:: console

 west build -p always --sysbuild -b nucleo_wb55rg samples/subsys/mgmt/mcumgr/smp_svr/ \
  -DEXTRA_CONF_FILE='overlay-shell.conf;overlay-fs.conf' -DSB_CONFIG_BOOTLOADER_MCUBOOT=y

Sign:
.. code-block:: console

  west sign -t imgtool -d build/smp_svr/ -- --key ../bootloader/mcuboot/root-rsa-2048.pem

Install mcumgr rust version. See https://github.com/vouch-opensource/mcumgr-client/

Upload new f/w in (use -s 0 to write partition 1)
.. code-block:: console

 mcumgr-client upload /local/home/frq07517/zephyrproject/zephyr/build/smp_svr/zephyr/zephyr.signed.bin -s 0

Note: To get the mcumgr-client working properly, after boot you need to open the console and then release it.
Otherwise all commands return an error.

Upload new f/w in (use -s 3 to write partition 2)
.. code-block:: console
 mcumgr-client upload /local/home/frq07517/zephyrproject/zephyr/build/smp_svr/zephyr/zephyr.signed.bin -s 3

When examining flash, you'll see that f/w has been written in 0x80A2000.
