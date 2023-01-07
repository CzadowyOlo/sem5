#!/bin/bash
IP=http://192.168.43.183:8080/api/
echo "Trying to do without api"
curl --header "Content-Type: application/json" \
  --request POST \
  --data '{"number1":10,"number2":12}' \
  $IP/pair/add/