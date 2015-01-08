#! /bin/sh

echo "The program $0 is now running"
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The third parameter is $3"
shift
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "The third parameter is $@"
