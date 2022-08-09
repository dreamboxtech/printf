#include "main.h"

/**
 * handle_specifiers - Matches a conversion specifier with
 * a corresponding conversion function
 * @specifier: A pointer to a potential conversion specifier.
 *
 * Return: If a conversion function is matched - a pointer to the function.
 * Otherwise - NULL.
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *, unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_d},
		{'i', convert_i},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
