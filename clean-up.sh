dry=0

run() {
    echo "$*"
    if [ $dry -ne 1 ]; then
        $*
    fi
}

for dotc in `find . -name '*.c'`; do
    run rm -f "${dotc%%.c}"
done

for dotcpp in `find . -name '*.cc'`; do
    run rm -f "${dotcpp%%.cc}"
done
