for x in $(curl https://www.cloudflare.com/ips-v4);do iptables -A INPUT -p tcp --dport 443 -s "$x" -j ACCEPT; done

iptables -A INPUT -p tcp  --dport 443  -j REJECT
iptables -A INPUT -p udp  --dport 443  -j REJECT
