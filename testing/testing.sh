echo "Numbers : $(python testing/random_ints.py $@ > test && cat test) - \n\n\n $(./push_swap $(cat test) \
    | wc -l) Lines, and Checker is : $(./push_swap $(cat test) | ./testing/checker_Mac $(cat test))"; rm test
