'''
Created on 6/10/2014

@author: wasiqkashkari
'''
import sys
import psutil


#cpu utilisation
stats = psutil.cpu_percent(interval=1, percpu=True);
print(stats)

#cpu times
stats_cup_times = psutil.cpu_times_percent(interval=1, percpu=True)
print(stats_cup_times)
