echo "FACTORIAL"
echo -n "Enter a number: "
read num

fact=1

for (( i = 1; i <= num; i ++ ))
do
	fact=`echo $fact \* $i | bc`
done

echo "Factorial = $fact"
