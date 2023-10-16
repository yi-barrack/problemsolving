#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
//sadf
int main()
{
    char name[51], grade[3];
    float score, sum = 0;
    int cnt = 0;
    for (int i = 0; i < 20; i++)
    {
        scanf("%s %f %s", name, &score, grade);
        if (strcmp(grade, "P") != 0)
        {
            cnt += score;
            if (strcmp(grade, "A+") == 0)
                sum += 4.5 * score;
            else if (strcmp(grade, "A0") == 0)
                sum += 4.0 * score;
            else if (strcmp(grade, "B+") == 0)
                sum += 3.5 * score;
            else if (strcmp(grade, "B0") == 0)
                sum += 3.0 * score;
            else if (strcmp(grade, "C+") == 0)
                sum += 2.5 * score;
            else if (strcmp(grade, "C0") == 0)
                sum += 2.0 * score;
            else if (strcmp(grade, "D+") == 0)
                sum += 1.5 * score;
            else if (strcmp(grade, "D0") == 0)
                sum += 1.0 * score;
            else if (strcmp(grade, "F") == 0)
                sum += 0;
        }
    }//?
    if (sum == 0)
        printf("%f", 0.0);
    else
        printf("%f", sum / cnt);
    return 0;
}
