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

To deploy the hardware and code on our OPS-SAT test device type:
```
	make test_deploy
```
