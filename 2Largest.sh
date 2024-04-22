read -p "Enter Number of terms : " n
l=0
sl=0
for((i=1;i<=n;i++)); do
	read -p "Enter Number $i : " x
	if [ $x -gt $l ]; then
		sl=$l
		l=$x		
	elif [ $x -gt $sl ] && [ $x -ne $l ]; then
		sl=$x
	fi
done

echo "Second Largest Number is : $sl"

echo exit




