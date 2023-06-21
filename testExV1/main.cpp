#include <iostream>
#include <vector>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>

#define COUNT_OF_CURVES 10
#define DIAPAZON_DOUBLE 50
#define DIAPAZON_STEP 0.9

double getRandomNumber(double low, double high) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(low, high);
	return dis(gen);
}

int getRandomInt(int low, int high) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(low, high);
	return dis(gen);
}

int main(int argc, char *argv[]) {
	const double M_PI = std::acos(-1.0);

	std::vector<Curve*> firstContainer;

	for (int i = 0; i < COUNT_OF_CURVES; i++)
	{
		Curve* tmpObj;
		switch (getRandomInt(0,2))
		{
		case 0:
			tmpObj = new Circle(getRandomNumber(1, DIAPAZON_DOUBLE));
			firstContainer.push_back(tmpObj);
			break;

		case 1:
			tmpObj = new Ellipse(getRandomNumber(1, DIAPAZON_DOUBLE), getRandomNumber(1, DIAPAZON_DOUBLE));
			firstContainer.push_back(tmpObj);
			break;

		case 2:
			tmpObj = new Helix(getRandomNumber(1, DIAPAZON_DOUBLE), getRandomNumber(0.1, DIAPAZON_STEP));
			firstContainer.push_back(tmpObj);
			break;
		default:
			break;
		}
	}

	double t = M_PI / 4.0;
	int count = 0;
	for (const auto& element : firstContainer) {
		std::cout << "Count = " << count++ << std::endl;
		element->printCoordinatesAndDerivative(t);
	}

	std::vector<Circle*> secondContainer;
	for (const auto& element : firstContainer) {
		if (dynamic_cast<Circle*>(element) != nullptr) {
			secondContainer.push_back(static_cast<Circle*>(element));
		}
	}
	std::cout << "\nSecond container of Circles" << std::endl;

	std::sort(secondContainer.begin(), secondContainer.end(), [](const Circle* cir1,const  Circle* cir2) {
		return cir1->getRadius() < cir2->getRadius();
		});


	double totalRadiusSum = 0.0;

	count = 0;
	for (const auto& circle : secondContainer) {
		double radius = circle->getRadius();
		std::cout << "Count: " << count++ << "    Radius = " << radius << std::endl;
		totalRadiusSum += radius;
		
	}
	std::cout << "Total radius = " << totalRadiusSum << std::endl;



	return 0;
}