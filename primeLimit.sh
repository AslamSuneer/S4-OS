echo Enter the lower limit
read low
echo enter the upper limit
read high
echo the prime numbers are..
if [ $low -lt 2 ];then
 low=2
fi
for (( i=$low;i<=$high ;i++ ));do
flag=1
	for (( j=2;j<= $i/2;j++ ));do
		if [ $(($i%$j)) -eq 0 ];then
			flag=0
			break
		fi
	done
if [ $flag -eq 1 ];then
	echo $i
fi
done
