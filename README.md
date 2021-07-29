# OSS-Rad-Monitor
### Version: 0.0.1  
### OSS-HAL-Version: 0.1.0

This is the FPGA/ARM configuration that is used to monitor the radiation that the FPGA system experiences while in orbit on OPS-SAT. 

* ``userLogic/`` contains the hardware for the project. The top-level is ``userLogic/oss_hal.sv`` which interfaces to the OSS-HAL.
* ``userSoftware/`` contains the driver software.

## Build Instructions
To build the image type:
```
	make image
```

This will create a directory ``./image`` that contains the bitstream to configure the FPGA fabric, ``./image/bitstream.rbf``, and a binary executable that can be run on the ARM HPS, ``./image/sw_driver.o``.

These files can be deployed manually on our test machine. However, there is also a automated deployment script. To deploy the hardware and code on our OPS-SAT test device type:
```
	make test_deploy
```
This will ask you to type in the password for the device twice: once to transfer the image accross, and once to run the executable.


### Version History

* 0.0.1 - initial version, no checking logic added yet
