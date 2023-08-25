#include <stdlib.h>

char **strtow(char *str, char *delims);
intis_delim(char ch, char *delims);
intget_word_length(char *str, char *delims);
intget_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
* strtow - a function that separates the words of a string
*
* @str: string to seperate
* @delims: delimitors to use
*
* Return: pointers to each word
*/

char **strtow(char *str, char *delims)

{
char **w = NULL;
int count, length, n, i = 0;

if (str == NULL || !*str)
	return (NULL);
count = get_word_count(str, delims);


if (count == 0)
	return (NULL);
w = malloc((count + 1) * sizeof(char *));
if (w == NULL)
	return (NULL);
while (i < count)
{
	length = get_word_length(str, delims);
	if (is_delim(*str, delims))
	{
		str = get_next_word(str, delims);
	}
	w[i] = malloc((wordLen + 1) * sizeof(char));
	if (w[i] == NULL)
	{
		while (i >= 0)
		{
			i--;
			free(w[i]);
		}
		free(w);
		return (NULL);
	}
	n = 0;
	while (n < length)
	{
		w[i][n] = *(str + n);
		n++;
	}
	w[i][n] = '\0';
	str = get_next_word(str, delims);
	i++;
}
w[i] = NULL;
return (w);
}

/**
* is_delim - checks if stream contains delimitor char
*
* @ch: char in stream
*
* @delims: null terminated array of delimitors
*
* Return: 1 (success), 0 if it fails
*/

intis_delim(char ch, char *delims)

{
int k = 0;

while (delims[k])
{
	if (delims[k] == ch)
		return (1);
	k++;
}
return (0);
}

/**
* get_word_length - gets the word length of aword in string
*
* @str: string to get word length from.
* @delims: delimitors to use
*
* Return: word length
*/

intget_word_length(char *str, char *delims)
{
int length = 0, p = 1, i = 0;

while (*(str + i))
{
	if (is_delim(str[i], delims))
		p = 1;
	else if (p)
	{
		length++;
	}
	if (length > 0 && is_delim(str[i], delims))
		break;
	i++;
}
return (length);
}

/**
* get_word_count - a function that gets word count of a string
*
* @str: string from which to get word count
* @delims: delimitors to use
*
* Return: word count
*/

intget_word_count(char *str, char *delims)

{
int count = 0, pending = 1, i = 0;

while (*(str + i))
{
	if (is_delim(str[i], delims))
		pending = 1;
	else if (pending)
	{
		pending = 0;
		count++;
	}
	i++;
}
return (count);
}

/**
 * get_next_word - a function that gets the next word
 * in a string
 *
 * @str: string from which to get next word
 * @delims: delimitors to use
 *
 * Return: First character of the next word
 */

char *get_next_word(char *str, char *delims)

{
int pending = 0;
int o = 0;

while (*(str + o))

{
	if (is_delim(str[o], delims))
		pending = 1;
	else if (pending)
		break;
	o++;
}
return (str + o);
}
