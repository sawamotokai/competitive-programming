#!/bin/sh
solution=${PWD}/$1
brute=${PWD}/$2
generator=${PWD}/$3

if [ ! -f $solution ]; then
  echo $PWD
  echo "No such solution file as ${solution}"
  exit
fi

if [ ! -f $brute ]; then
  echo "No such brute force file as ${brute}"
  exit
fi

if [ ! -f $generator ]; then
  echo "No such generator force file as ${generator}"
  exit
fi

echo "Compiling solution file"
cpp $solution
echo "Compiling brute force file"
g++ -std=c++17 -Wshadow -Wall -o brute $brute -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
echo "Compiling generator file"
g++ -std=c++17 -Wshadow -Wall -o gen $generator -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

echo "Finish compling files and now testing"

for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    ./a < int > out1
    ./brute < int > out2
    diff -w out1 out2 || break
done
