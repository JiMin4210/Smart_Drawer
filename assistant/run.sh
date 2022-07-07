#!/bin/bash
while [ 1 ]
   do
        pid=`ps -ef | grep "calltotalk.py" | grep -v 'grep' | awk '{print $2}'`
        if [ -z $pid ]; then
        amixer -c Device cset numid=3 14
        ~/venv/bin/python calltotalk.py &
        fi
        bt=`hcitool con | grep D4:F5 | awk '{print $2}'`
        if [ -z $bt ]; then
        sleep 1
        echo -e "connect D4:F5:47:97:C8:CB \nquit" | bluetoothctl
        fi
   done
