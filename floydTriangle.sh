read -p "Enter number of Rows : " r
num=1
for ((i=1;i<=r;i++)); do
	for ((j=1;j<=i;j++)); do
		echo -n "$num "
		num=$(($num+1))
	done
	echo
done
exit
