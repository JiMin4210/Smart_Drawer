#!/bin/bash
kill -9 `ps -ef|grep -P "call|run.sh"|grep -v 'grep'|awk '{print $2}'`
