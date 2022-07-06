#!/bin/bash
while [ 1 ]
   do
        pid=`ps -ef | grep "calltotalk.py" | grep -v 'grep' | awk '{print $2}'`
        if [ -z $pid ]; then
        amixer -c Device cset numid=3 14
        ~/venv/bin/python calltotalk.py &
        fi
   done
