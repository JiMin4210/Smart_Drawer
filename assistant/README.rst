#profile 수정 필요
````````````````````````````````````````````````````````````````````
#sudo vi /etc/profile
pid=\`ps -ef | grep "run.sh" | grep -v 'grep' | awk '{print $2}'\`
if [ -z $pid ]; then
  cd /home/pi/smart_drawer/assistant 
  ./run.sh &
else
  echo "run file is running"
fi
````````````````````````````````````````````````````````````````````
