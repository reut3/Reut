gd=gcc -ansi -pedantic-errors -Wall -Wextra -g
gc=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3


#sort_arr_012
sort_arr_012.out: sort_arr_012.o test_module.o 
	$(gd) $^ -o $@

sort_arr_012.o: sort_arr_012.c test_module.h
	$(gd) -c $<


#max_profit
max_profit.out: max_profit.o test_module.o 
	$(gd) $^ -o $@

max_profit.o: max_profit.c test_module.h
	$(gd) -c $<


#max_sub_arr
max_sub_arr.out: max_sub_arr.o test_module.o 
	$(gd) $^ -o $@

max_sub_arr.o: max_sub_arr.c test_module.h
	$(gd) -c $<


test_module.o: test_module.c test_module.h
	$(gd) -c $<


.PHONY: clean
clean:
	rm *.o *.out
