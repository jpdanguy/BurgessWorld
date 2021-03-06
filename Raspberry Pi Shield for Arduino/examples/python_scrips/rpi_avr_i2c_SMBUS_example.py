#!/usr/bin/python
import smbus
import time

bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)

# Give the I2C device time to settle
time.sleep(2)

DEVICE_ADDRESS = 0x8      #7 bit address (will be left shifted to add the read write bit)
DEVICE_REG_MODE1 = 0x00
DEVICE_REG_LEDOUT0 = 0x1d

def StringToBytes(val):
    retVal = []
    for c in val:
            retVal.append(ord(c))
    return retVal

byteString = ("hello")
bytelist = StringToBytes(byteString)

while True:
  for byte in bytelist:
    bus.write_byte(DEVICE_ADDRESS, byte)
  while bus.read_byte(DEVICE_ADDRESS) != 1:
    pass
