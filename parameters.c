#include "main.h"
/**
 * init_par - clears struct and buf
 * @par :struct parameters
 * @ap: pointer arg
 * Return : void
 */
void init_par(par_t *par, varlist ap)
{
	par->plus_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->zero_flag = 0;
	par->minus_flag = 0;
	par->width = 0;
	par->precision = UNIT_MAX;
	par->h_mod = 0;
	par->l_mod = 0;
	par->unsign = 0;
	(void)ap;
}
