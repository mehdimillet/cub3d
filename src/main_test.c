#include "../headers/cub3d.h"

static char **make_file(const char *lines[])
{
    int     count;
    char    **f;
    int     i;

    count = 0;
    while (lines[count])
        count++;
    f = malloc(sizeof(char *) * (count + 1));
    i = 0;
    while (i < count)
    {
        f[i] = ft_strdup(lines[i]);
        i++;
    }
    f[count] = NULL;
    return (f);
}

static void reset_cub(t_cub *info)
{
    int i = 0;
    while (i < 6) { info->seen[i] = 0; i++; }
    info->map_start = -1;
    info->floor.red = -1;
    info->floor.green = -1;
    info->floor.blue = -1;
    info->ceiling.red = -1;
    info->ceiling.green = -1;
    info->ceiling.blue = -1;
}

static void test(const char *label, const char *lines[],
                 int expected_ret, int expected_map_start)
{
    char    **file;
    t_cub   info;
    int     ret;

    reset_cub(&info);
    file = make_file(lines);
    printf("\n--- %s ---\n", label);
    ret = info_distrib(file, &info);
    printf("ret=%d (expected %d) | map_start=%d (expected %d)\n",
           ret, expected_ret, info.map_start, expected_map_start);
    if (ret == expected_ret
        && (expected_map_start < 0 || info.map_start == expected_map_start))
        printf("    pass\n");
    else
        printf(">>> FAIL\n");
    free_tab(file);
}

int main(void)
{
    /* === nominal === */
    const char *t1[] = {
        "NO ./north.xpm", "SO ./south.xpm", "WE ./west.xpm", "EA ./east.xpm",
        "F 220,100,0", "C 225,30,0",
        "111111", "10000N1", "111111", NULL };
    test("nominal", t1, 0, 6);

    /* === lignes vides === */
    const char *t2[] = {
        "", "NO ./n.xpm", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", "111", "1N1", "111", NULL };
    test("blank at start", t2, 0, 7);

    const char *t3[] = {
        "NO ./n.xpm", "", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", "111", "1N1", "111", NULL };
    test("blank between configs", t3, 0, 7);

    const char *t4[] = {
        "NO ./n.xpm", "", "", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", "111", "1N1", "111", NULL };
    test("two blanks in a row", t4, 0, 8);

    const char *t5[] = {
        "NO ./n.xpm", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", "", "111", "1N1", "111", NULL };
    test("blank just before map", t5, 0, 7);

    const char *t6[] = {
        "NO ./n.xpm", "   \t  ", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", "111", "1N1", "111", NULL };
    test("whitespace-only line", t6, 0, 7);

    /* === doublons === */
    const char *t7[] = {
        "NO ./n.xpm", "NO ./other.xpm", "SO ./s.xpm", "WE ./w.xpm",
        "EA ./e.xpm", "F 1,1,1", "C 2,2,2", "111", NULL };
    test("NO duplicate consecutive", t7, 1, -1);

    const char *t8[] = {
        "NO ./n.xpm", "SO ./s.xpm", "F 1,1,1", "F 2,2,2",
        "WE ./w.xpm", "EA ./e.xpm", "C 3,3,3", "111", NULL };
    test("F duplicate separated", t8, 1, -1);

    /* === manques === */
    const char *t9[] = {
        "NO ./n.xpm", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "111", "1N1", "111", NULL };
    test("missing C", t9, 1, -1);

    const char *t10[] = {
        "NO ./n.xpm", "111", NULL };
    test("only one config then map", t10, 1, -1);

    /* === lignes inconnues === */
    const char *t11[] = {
        "Hello world", "NO ./n.xpm", NULL };
    test("unknown line at start", t11, 1, -1);

    const char *t12[] = {
        "NO ./n.xpm", "XX ./bad.xpm", "SO ./s.xpm", NULL };
    test("unknown identifier mid-config", t12, 1, -1);

    /* === cas tordus === */
    const char *t13[] = { NULL };
    test("empty file", t13, 1, -1);

    const char *t14[] = { "", "", "   ", NULL };
    test("only blank lines", t14, 1, -1);

    const char *t15[] = {
        "NO ./n.xpm", "SO ./s.xpm", "WE ./w.xpm", "EA ./e.xpm",
        "F 1,1,1", "C 2,2,2", NULL };
    test("all configs but no map", t15, 1, -1);

    const char *t16[] = { "111111", "10001", NULL };
    test("map first, no config", t16, 1, -1);

    return (0);
}