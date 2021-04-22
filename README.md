# Arduino-RPi-nrf24l01-communication

Simple scripts to make an arduino and raspberry pi communicate with each other using nrf24l01 modules.

To start, you need to install the RF24 library on both RPi and arduino board : https://github.com/nRF24/RF24

On raspberry, start by enabling SPI : ``sudo nano /boot/config.txt``uncomment ``dtparam=spi=on``. 
Install the required package for following instructions : ``sudo apt-get update`` and ``sudo apt-get install git``

Create a new directory where you want to make your project : ``mkdir yourDirectory `` and then clone the github repository : ``git clone https://github.com/TRMh20/RF24.git``
It will create a new directory named RF24. We now choose the SPIDEV support : ``cd R24``and then ``./configure --driver=SPIDEV``. 
We then need to compile and install : ``make``, ``sudo make install -B``. 

The library is now installed and ready for C/C++ use. If we need the Python support too : ``sudo apt-get install python-dev python-setup-tools libboost-python-dev`` then ``cd pyRF24`` and ``./setup.py build`` 


On arduino, in the library manager search for RF24 library by TRMh20 and install it.


Connect the nrf24l01 as follow 

<img src="https://user-images.githubusercontent.com/38764918/115746275-7e09f080-a394-11eb-89ca-0769d4c3a552.png" width="500" height="500"> 


<img src="https://user-images.githubusercontent.com/38764918/115748014-12c11e00-a396-11eb-836a-7ed37e686a0e.jpg" width="500" height="600">


The scripts are written for Arduino=transmitter and RPi=receiver.
To compile the RPi script, go to ``RF24/examples_linux``, copy the file there and edit Makefile ``sudo nano Makefile`` to add the name of the script to ``PROGRAMS= ...``
