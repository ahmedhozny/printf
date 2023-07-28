#include "main.h"

/**
 * get_flag - gets the flag func
 * @r : string
 * @par :thr parameter
 *
 * Return: the flag is valid
 */
int get_flag(char *r, par_t *par)
{
	int j = 0;

	switch (*r)
	{
		case '+':
			j = par->plus = 1;
			break;
		case ' ':
			j = par->space = 1;
			break;
		case '#':
			j = par->hashtag = 1;
			break;
		case '-':
			j = par->minus = 1;
			break;
		case '0':
			j = par->zero = 1;
			break;
	}
	return (j);
}

/**
 * get_mdif - gets the modifier
 * @r :string
 * @par :the parameter
 *
 * Return: if it's valid
 */
int get_mdif(char *r, par_t *par)
{
	int j = 0;

	switch (*r)
	{
		case 'h':
			j = par->h_modif = 1;
			break;
		case 'l':
			j = par->l_modif = 1;
			break;
	}
	return (j);
}
