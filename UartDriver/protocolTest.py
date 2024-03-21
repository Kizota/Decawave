import serial
import time
import io

ser = serial.Serial("COM6",115200,timeout=0.5)

ser.write(b'1500')
time.sleep(0.2)


while True:
    res = ser.read(100)
    for b in res:
        print("the number is: ",b)


