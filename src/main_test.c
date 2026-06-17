#include "../headers/cub3d.h"

static void	test_one(const char *label, char *line, int expected)
{
	t_color	c;
	int		ret;

	c.red = -1;
	c.green = -1;
	c.blue = -1;
	printf("\n--- %s ---\n", label);
	printf("input    : \"%s\"\n", line);
	printf("expected : %s\n", expected == 0 ? "OK" : "Error");
	ret = give_color(&c, line);
	printf("got      : %s (r=%d g=%d b=%d)\n",
		ret == 0 ? "OK" : "Error", c.red, c.green, c.blue);
	if (ret != expected)
		printf(">>> FAIL\n");
	else
		printf("    pass\n");
}

int	main(void)
{
	/* should succeed */
	test_one("classic",       "F 220,100,0",   0);
	test_one("all max",       "F 255,255,255", 0);
	test_one("all zero",      "F 0,0,0",       0);
	test_one("ceiling style", "C 50,80,200",   0);

	/* should fail */
	test_one("over 255",      "F 256,0,0",     1);
	test_one("missing val",   "F 220,100",     1);
	test_one("too many",      "F 1,2,3,4",     1);
	test_one("empty middle",  "F 220,,0",      1);
	test_one("leading comma", "F ,220,100,0", 1);
	test_one("trailing comma","F 220,100,0,", 1);
	test_one("letters",       "F abc,1,2",     1);
	test_one("overflow",      "F 9999,0,0",    1);
	test_one("only id",       "F",             1);

	return (0);
}