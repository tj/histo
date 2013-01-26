
while true; do
  uptime | awk '{ print $10 }'
  sleep 60
done
