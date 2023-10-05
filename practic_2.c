#include "type.h"

#inlcude <stdlib.h>
#inlcude <stdio.h>
#inlcude <stdint.h>
#include <math.h>
#inlcude <mem.h>


/*
Удалить из заданного целочисленного линейного массива первые два элемента,
десятичная запись которых оканчивается на 8, сдвинув оставшиеся к началу массива. Если есть
только одно оканчивающееся на 8 значение, то вставить после него его копию, сдвинув
оставшиеся элементы. Если значений, кратных оканчивающихся на 8, в массиве нет, добавить
число 8 первым и последним элементом массива. 
*/

// {1,2,4,8,28,18,25,6,3,23,4,566,785888, 23}
void process (
	const iterator begin, const uint64 size, 
	iterator *_begin, iterator *_end
) {
	iterator end = begin + size + 1
	iterator it1 = 0, it2 = 0;
	uint64 index1 = 0;
	uint64 index2 = 0
	for (iterator it = begin; it != end; ++it)
		{
			if (abs(*it) % 10 == 8)
			{ 
				if (!it1 || (++index1 == (uint64)-1)) { first8 = it;  } 
				else if (!it2 || (++index2 == (uint64)-1)) { it2 = it; }
				else break;
			}
		}

	// count 2
	*_begin = malloc(sizeof(int32) * size-2);
	*_end = *_begin + size + 1;

	memcpy(*_begin, begin, sizeof(int32) * index1);

	
	
}



int main (void) {

  
  
  return 0;
}
