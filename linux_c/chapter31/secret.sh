#! /bin/sh

echo "Enter password"
COUNTER=0
read TRY
while [ "$TRY" != "secret" -a $COUNTER -le 4 ];do
	echo "Sorry, try again"
	COUNTER=$((COUNTER+1));
	read TRY
done

