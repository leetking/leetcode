dry=0

run() {
    echo "$*"
    if [[ $dry == 0 ]]; then
        $*
    fi
}

for dotc in `find . -name '*.c'`; do
    if [[ -e "${dotc%%.c}" ]]; then
        run rm -f "${dotc%%.c}"
    fi
done

for dotcpp in `find . -name '*.cc'`; do
    if [[ -e "${dotcpp%%.cc}" ]]; then
        run rm -f "${dotcpp%%.cc}"
    fi
done
