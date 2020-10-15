function waitla {
	target=${1:-$(($(nproc)+4))}
	la=$(cut -d' ' -f 1 /proc/loadavg)
	until [[ $(echo "$la<$target" | bc) -eq "1" ]]; do
		#echo $la
		sleep 1
		la=$(cut -d' ' -f 1 /proc/loadavg)
	done
}
waitla 20
