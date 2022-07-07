# profile 수정

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
# device_config.json 추가
````````````````````````````````````````````````````````````````````
#sudo vi /home/pi/.config/googlesamples-assistant/device_config.json
{"id": "b6480674-e55d-11ec-aa41-b827eb6d09fe", "model_id": "ai-speaker-123df-raspberry-pi-3-kiyx9e", "client_type": "SDK_SERVICE"}
````````````````````````````````````````````````````````````````````
