ls | grep .cpp | xargs g++
for f in `ls ./test/input`; do
    ./a.out < "./test/input/$f" > "./test/output/$f"
done