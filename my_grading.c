#include <stdio.h>
#include <ctype.h>

double calculate();
double input();
double get_mean(double, double, double, double , double, double);
const char* get_grade(double);
void show(double, const char*);

int main()
{
    int class, number;
    printf("How many students are in the class? ");
    scanf("%d", &number);

    for(class=0; class<number; class++)
    {
        calculate();
    }

    printf("\nEND OF ENTRY\n");
    return 0;
}

double calculate()
{
    double math, eng, kisw, sci, sst, re, mean;

    printf("\nNEW ENTRY: ");
    printf("\nEnter score for math: ");
    math=input();
    printf("\nEnter score for eng: ");
    eng=input();
    printf("\nEnter score for kisw: ");
    kisw=input();
    printf("\nEnter score for sci: ");
    sci=input();
    printf("\nEnter score for sst: ");
    sst=input();
    printf("\nEnter score for re: ");
    re=input();

    mean=get_mean(math, eng, kisw, sci, sst, re);
    const char* grade=get_grade(mean);
    show(mean, grade);
    return mean;
}

double input()
{
    double score;

    while (scanf("%lf", &score) != 1 || score < 0 || score > 100)
    {
        printf("Invalid input! Enter a score within [0-100]: ");
        while (getchar() != '\n');
    }
    
    return score;
}

double get_mean(double a, double b, double c, double d, double e, double f)
{
    return(a+b+c+d+e+f)/6;
}

const char* get_grade(double mean)
{
    if(mean>79)
        return "A";
    else if(mean>=75)
        return "A-";
    else if(mean>=70)
        return "B+";
    else if(mean>=65)
        return "B";
    else if(mean>=60)
        return "B-";
    else if(mean>=55)
        return "C+";
    else if(mean>=45)
        return "C";
    else if(mean>=40)
        return "C-";
    else if(mean>=35)
        return "D+";
    else if(mean>=30)
        return "D";
    else if(mean>=25)
        return "D-";
    else
        return "E";
}

void show(double mean, const char* grade)
{
    printf("\nMean: %.3f, Grade: %s\n", mean, grade);
}