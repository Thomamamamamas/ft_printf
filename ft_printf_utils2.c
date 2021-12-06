#include "ft_printf.h"

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	long long int	lln;
	int				len;

	lln = n;
	len = 0;
	if (lln < 0)
	{
		len += ft_putchar('-');
		lln = lln * -1;
	}
	if (lln > 9)
	{
		len += ft_putnbr(lln / 10);
		lln = lln % 10;
	}
	len += ft_putchar(lln + '0');
	return (len);
}

int		ft_put_address(unsigned long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		len += ft_put_address((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}

int		ft_putnbr_hexa(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_hexa((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}

int		ft_putnbr_hexa_lower(long long n)
{
	char	*caracters;
	int		len;

	caracters = "0123456789abcdef";
	len = 0;

	if (n >= LONG_MAX)
		return (ft_putstr("ffffffff"));
	if (n >= 16)
	{
		len += ft_putnbr_hexa_lower((n / 16));
		len += ft_putchar(caracters[n % 16]);
	}
	else
		len += ft_putchar(caracters[n % 16]);
	return (len);
}

int	ft_putstr(char *s)
{
	int	n;
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	n = 0;
	while (s[n])
	{
		len += ft_putchar(s[n]);
		n++;
	}
	return (len);
}
