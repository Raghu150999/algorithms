m=`cat $1 | wc -l`
n=`python3 parse.py $1`
echo "$n $m"
