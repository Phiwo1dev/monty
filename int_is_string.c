#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - gets a pointer to new string
 * containing interger.
 * @num: num to be converted to string
 *
 * Return: Pointer to newly created string,
 * NULL if malloc fails.
 */
char *get_int(int num)

{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Gets the absolute value of an integer
 * @i: Int to get absolute value of.
 *
 * Return: Unsigned int abs representation of i
 */
unsigned int _abs(int i)

{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of required buffer for an unsigned int
 * @num: number for required buffer length
 * @base: num base used by buffer
 *
 * Return: integer with length of required buffer
 */
int get_numbase_len(unsigned int num, unsigned int base)

{
	int l = 1;

	while (num > base - 1)
	{
		l++;
		num /= base;
	}
	return (l);
}

/**
 * fill_numbase_buff - fills buffer up to base 36
 * @num: number to be converted to string
 * @base: num base used in conversion
 * @buff: buffer to fill with converted num
 * @buff_size: buffer size in bytes
 *
 * Return: void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int r, l = buff_size - 1;

	buff[buff_size] = '\0';
	while (l >= 0)
	{
		r = num % base;
		if (r > 9) /* return lowercase ascii value */
			buff[l] = r + 87; /* 10 = a, 11 is b, ... */
		else
			buff[l] = r + '0';
		num /= base;
		l--;
	}
}
