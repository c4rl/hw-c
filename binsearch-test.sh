#! /bin/bash

x1=$(date +%s);
for VAR in {0..10000}
do
  ./a.out > /dev/null
done

x2=$(date +%s);
took=$(( x2-x1 ));

echo $took;

