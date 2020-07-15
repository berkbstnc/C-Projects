#include <stdio.h>
#define pi 3.14

double calculateBaseArea(double radius);
double calculatePerimeter(double radius);
double calculateVolume(double radius,double height);
double calculateCircumference(double radius,double height);
void printResults(double radius,double height);

int main ()
{
	double radius,height;
	
	do
{	

	printf("Enter radius, and height ");
	scanf("%lf%lf",&radius,&height);
	

	if(radius>0 && height>0){
	printResults(radius,height);
	printf("New Cylinder *********** \n");
}
	
}while(radius!=0 && height!=0);

    printf("Goodbye!");
	return (0);
}

double calculateBaseArea(double radius)
{
	double base_area;
	
	base_area = pi * (radius*radius);
	
	return base_area; 
}

double calculatePerimeter(double radius)
{
	double perimeter;
	
	perimeter = 2 * pi * radius;
	
	return perimeter;
}

double calculateVolume(double radius,double height)
{
	double volume;
	
	volume = calculateBaseArea(radius)*height;
	
	return volume;
}

double calculateCircumference(double radius,double height)
{
	double circumference;
	
	circumference = ((calculatePerimeter(radius) * height) + (2* calculateBaseArea(radius)));
	
	return circumference;
}

void printResults(double radius,double height)
{
	printf("Cylinder has %.2lf volume, and %.2lf circumference \n",calculateVolume(radius,height),calculateCircumference(radius,height));
} 
