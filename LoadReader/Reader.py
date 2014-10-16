'''
Created on 6/10/2014

@author: wasiqkashkari
'''
import sys
import psutil
import serial
import time

ser = serial.Serial('/dev/tty.usbmodem1421',9600,timeout=3)

time.sleep(3)
if (not ser.isOpen()):
    print "Cannot open Serial!"
else:
    while(True):
        stats = psutil.cpu_percent(interval=0.2, percpu=True);
        cpuusage = 0;
        #cpu utilisation
        print(stats)
        for i in stats:
            cpuusage += i;
        cpuusage = cpuusage/len(stats)
        if cpuusage >= 100:
            cpuusage = 99;

        hey = "a" +  ("%02d" %cpuusage)
        print hey
        ser.write(hey)
        """ser.write(hey[0])
        ser.write(hey[1])
        ser.write(hey[2])"""
        #ser.write('b')
        print ser.read()
