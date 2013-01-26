
# todo: remove %d when we have float support back
while true; do
  uptime | awk '{ printf "%d\n", $10 }'
  sleep 5
done
